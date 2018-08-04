

/***************************************/
void usart2_init(void)//串口2
{
	NVIC_InitTypeDef NVIC_InitSructure;
	USART_InitTypeDef USART_InitStructure;
	DMA_InitTypeDef DMA_Struct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);      //DMA1
	
	NVIC_InitSructure.NVIC_IRQChannel = USART2_IRQn;//开放串口2中断
	NVIC_InitSructure.NVIC_IRQChannelPreemptionPriority=1 ;// 抢占优先级为 1
	NVIC_InitSructure.NVIC_IRQChannelSubPriority=0;//响应优先级为0
	NVIC_InitSructure.NVIC_IRQChannelCmd = ENABLE;  //使能指定通道
	NVIC_Init(&NVIC_InitSructure);
	
	USART_DeInit(USART2);//复位串口2寄存器
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//数据位8位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;			//停止位1位
  USART_InitStructure.USART_Parity = USART_Parity_No;				//无校验位
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //无硬件流控
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART2, &USART_InitStructure);//配置串口参数 
	USART_ClearFlag(USART2, USART_FLAG_TC );//清除发送完成标志位
  USART_Cmd(USART2, ENABLE);//使能串口
	USART_ITConfig(USART2,USART_IT_IDLE,ENABLE);	//使能空闲中断
	
	//DMA_Rec_Init
	DMA_DeInit(DMA1_Channel6);  
	DMA_Struct.DMA_PeripheralBaseAddr = (u32)&USART2->DR;  //DMA外设基地址
	DMA_Struct.DMA_MemoryBaseAddr = (u32)Uart2RecBuff;      //DMA内存基地址
	DMA_Struct.DMA_DIR = DMA_DIR_PeripheralSRC;  		   //数据传输方向，从外设到内存
	DMA_Struct.DMA_BufferSize = UART2_BUFF_SIZE;  	   	   //DMA通道的DMA缓存的大小
	DMA_Struct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  //外设地址寄存器不变
	DMA_Struct.DMA_MemoryInc = DMA_MemoryInc_Enable;  		  //内存地址寄存器递增
	DMA_Struct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  //数据宽度为8位
	DMA_Struct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;   //数据宽度为8位
	DMA_Struct.DMA_Mode = DMA_Mode_Circular;  				  //工作在循环缓存模式
	DMA_Struct.DMA_Priority = DMA_Priority_High; 		  //DMA通道 x拥有高优先级 
	DMA_Struct.DMA_M2M = DMA_M2M_Disable;  					  //DMA通道x没有设置为内存到内存传输
	DMA_Init(DMA1_Channel6, &DMA_Struct);  
	DMA_Cmd(DMA1_Channel6,ENABLE);					//DMA使能
	USART_DMACmd(USART2,USART_DMAReq_Rx,ENABLE);	//串口DMA使能
}
/***************************************/
void USART2_IRQHandler(void)
{
	usart2_count=USART2->SR;
	usart2_count=USART2->DR;     //清除中断标志
	usart2_count=UART2_BUFF_SIZE-DMA_GetCurrDataCounter(DMA1_Channel6);  //读取接收字节个数
	DMA_Cmd(DMA1_Channel6,DISABLE);        //关闭DMA
	DMA1_Channel6->CNDTR=UART2_BUFF_SIZE;  //重新设置DMA
	DMA_Cmd(DMA1_Channel6,ENABLE);         //开启DMA
	rcv2_flag=1;
}
/***************************************/
void UART2_send(u8 *p,u32 num)
{
	while(num--)
	{
		USART_SendData(USART2,*p++);
		while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET);	//判断是否发送完成
	}
}
/***************************************/
void UART2_one(u8 dat)
{
	USART_SendData(USART2,dat);
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET);	//判断是否发送完成
}
/***************************************/



