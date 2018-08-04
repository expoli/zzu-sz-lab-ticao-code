#include "sys.h"
#include "usart.h"	  
////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos 使用	  
#endif
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//串口1初始化		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/8/18
//版本：V1.5
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
//********************************************************************************
//V1.3修改说明 
//支持适应不同频率下的串口波特率设置.
//加入了对printf的支持
//增加了串口接收命令功能.
//修正了printf第一个字符丢失的bug
//V1.4修改说明
//1,修改串口初始化IO的bug
//2,修改了USART_RX_STA,使得串口最大接收字节数为2的14次方
//3,增加了USART_REC_LEN,用于定义串口最大允许接收的字节数(不大于2的14次方)
//4,修改了EN_USART1_RX的使能方式
//V1.5修改说明
//1,增加了对UCOSII的支持
////////////////////////////////////////////////////////////////////////////////// 	  
 

//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

 
 
#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误   	
u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
u16 USART_RX_STA=0;       //接收状态标记	  
  
void uart_init(u32 bound){
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

  USART_Init(USART1, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 

}

void USART1_IRQHandler(void)                	//串口1中断服务程序
	{
	u8 Res;
#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
		{
		Res =USART_ReceiveData(USART1);	//读取接收到的数据
		
		if((USART_RX_STA&0x8000)==0)//接收未完成
			{
			if(USART_RX_STA&0x4000)//接收到了0x0d
				{
				if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
				else USART_RX_STA|=0x8000;	//接收完成了 
				}
			else //还没收到0X0D
				{	
				if(Res==0x0d)USART_RX_STA|=0x4000;
				else
					{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//接收数据错误,重新开始接收	  
					}		 
				}
			}   		 
     } 
#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntExit();  											 
#endif
} 
#endif	

void Send_turn(u8 ch)
{
	USART1->DR=(u8)ch ;
	while((USART1->SR&0X40)==0);//等待发送结束		0100 0000		
}
void SetServoLimit(unsigned char id,unsigned short int cw_limit,unsigned short int ccw_limit)
{
	unsigned short int temp_ccw=0;
	unsigned short int temp_cw=0;
	unsigned char temp_ccw_h=0;
	unsigned char temp_ccw_l=0;
	unsigned char temp_cw_h=0;
	
	unsigned char temp_cw_l=0;
	unsigned char temp_sum=0;
	if(ccw_limit>1023)
	{
		temp_ccw=1023;
	}
	else
	{
		temp_ccw=ccw_limit;
	}
	if(cw_limit>1023)
	{
		temp_cw=1023;
	}
	else
	{
		temp_cw=cw_limit;
	}
	temp_ccw_h=(unsigned char)(temp_ccw>>8);
	temp_ccw_l=(unsigned char)temp_ccw;
	temp_cw_h=(unsigned char)(temp_cw>>8);
	temp_cw_l=(unsigned char)temp_cw;
	//UART5|=(SR&0X40);
	Send_turn(0xff);
	Send_turn(0xff);
	Send_turn(id);
	Send_turn(7);
	Send_turn(0x03);
	Send_turn(0x06);
	Send_turn(temp_cw_l);
	Send_turn(temp_cw_h);
	Send_turn(temp_ccw_l);
	Send_turn(temp_ccw_h);
	temp_sum=id+7+0x03+0x06+temp_cw_l+temp_cw_h+temp_ccw_l+temp_ccw_h;
	temp_sum=~temp_sum;
	Send_turn(temp_sum);
	while((USART1->SR&0X40)==0);//等待发送结束
	delay_ms(2);
}
void SetServoPosition(unsigned char id,unsigned short int position,unsigned short int velocity)
{
	unsigned short int temp_velocity=0;
	unsigned short int temp_position=0;
	unsigned char temp_velocity_h=0;
	unsigned char temp_velocity_l=0;
	unsigned char temp_position_h=0;
	unsigned char temp_position_l=0;
	unsigned char temp_sum=0;
	if(velocity>1023)
	{
		temp_velocity=1023;
	}
	else
	{
		temp_velocity=velocity;
	}
	if(position>1023)
	{
		temp_position=1023;
	}
	else
	{
		temp_position=position;
	}
	temp_velocity_h=(unsigned char)(temp_velocity>>8);
	temp_velocity_l=(unsigned char)temp_velocity;
	temp_position_h=(unsigned char)(temp_position>>8);
	temp_position_l=(unsigned char)temp_position;
//	UART5|=(SR&0X40);
	Send_turn(0xff);
	Send_turn(0xff);
	Send_turn(id);
	Send_turn(7);
	Send_turn(0x03);
	Send_turn(0x1e);
	Send_turn(temp_position_l);
	Send_turn(temp_position_h);
	Send_turn(temp_velocity_l);
	Send_turn(temp_velocity_h);
	temp_sum=id+7+0x03+0x1e+temp_position_l+temp_position_h+temp_velocity_l+temp_velocity_h;
	temp_sum=~temp_sum;
	Send_turn(temp_sum);
	while((USART1->SR&0X40)==0);//等待发送结束
	delay_ms(2);
}
void together(unsigned char id_to1,unsigned short int position_to1,unsigned short int velocity_to1,unsigned char id_to2,unsigned short int position_to2,unsigned short int velocity_to2)
{
    unsigned short int temp_velocity_1=0;
	unsigned short int temp_position_1=0;
	   unsigned char temp_velocity_h_1=0;
   	   unsigned char temp_velocity_l_1=0;
	   unsigned char temp_position_h_1=0;
	   unsigned char temp_position_l_1=0;
	unsigned short int temp_velocity_2=0;
	unsigned short int temp_position_2=0;
	   unsigned char temp_velocity_h_2=0;
   	   unsigned char temp_velocity_l_2=0;
	   unsigned char temp_position_h_2=0;
	   unsigned char temp_position_l_2=0;
	unsigned char temp_sum=0;
	temp_position_1=position_to1;
	temp_velocity_1=velocity_to1;
	temp_position_2=position_to2;
	temp_velocity_2=velocity_to2;

	temp_velocity_h_1=(unsigned char)(temp_velocity_1>>8);
	temp_velocity_l_1=(unsigned char)temp_velocity_1;
	temp_position_h_1=(unsigned char)(temp_position_1>>8);
	temp_position_l_1=(unsigned char)temp_position_1;

	temp_velocity_h_2=(unsigned char)(temp_velocity_2>>8);
	temp_velocity_l_2=(unsigned char)temp_velocity_2;
	temp_position_h_2=(unsigned char)(temp_position_2>>8);
	temp_position_l_2=(unsigned char)temp_position_2;

    Send_turn(0xff);
	Send_turn(0xff);
	Send_turn(0xFE);
	Send_turn(14);	   // 所有数据的长度
	Send_turn(0x83);
	Send_turn(0x1e);
	Send_turn(4);
	
	Send_turn(id_to1);
	Send_turn(temp_position_l_1);
	Send_turn(temp_position_h_1);
	Send_turn(temp_velocity_l_1);
	Send_turn(temp_velocity_h_1);

	Send_turn(id_to2);
	Send_turn(temp_position_l_2);
	Send_turn(temp_position_h_2);
	Send_turn(temp_velocity_l_2);
	Send_turn(temp_velocity_h_2);

	temp_sum=0xFE+14+ 0x83 +0x1e + 4+ id_to1+id_to2+temp_position_l_1+temp_position_h_1 +temp_velocity_l_1 +temp_velocity_h_1 + temp_position_l_2+temp_position_h_2 +temp_velocity_l_2 +temp_velocity_h_2;
	temp_sum=~temp_sum;
	Send_turn(temp_sum);
	while((USART1->SR&0X40)==0);//等待发送结束
	delay_ms(2);
}
void Action_write(unsigned char id,unsigned short int position,unsigned short int velocity)
{
	unsigned short int temp_velocity=0;
	unsigned short int temp_position=0;
	unsigned char temp_velocity_h=0;
	unsigned char temp_velocity_l=0;
	unsigned char temp_position_h=0;
	unsigned char temp_position_l=0;
	unsigned char temp_sum=0;	
	temp_velocity=velocity;
	temp_position=position;
	temp_velocity_h=(unsigned char)(temp_velocity>>8);
	temp_velocity_l=(unsigned char)temp_velocity;
	temp_position_h=(unsigned char)(temp_position>>8);
	temp_position_l=(unsigned char)temp_position;
	Send_turn(0xff);
	Send_turn(0xff);
	Send_turn(id);
	Send_turn(7);
	Send_turn(0x04);
	Send_turn(0x1e);
	Send_turn(temp_position_l);
	Send_turn(temp_position_h);
	Send_turn(temp_velocity_l);
	Send_turn(temp_velocity_h);
	temp_sum=id+7+0x04+0x1e+temp_position_l+temp_position_h+temp_velocity_l+temp_velocity_h;
	temp_sum=~temp_sum;
	Send_turn(temp_sum);
	while((USART1->SR&0X40)==0);//等待发送结束
	delay_ms(2);
}
void Action()
{
	unsigned char temp_sum=0;	
	Send_turn(0xff);
	Send_turn(0xff);
	Send_turn(0xFE);
	Send_turn(2);
	Send_turn(0x05);
	temp_sum=0xFE+0x02+0x05;
	temp_sum=~temp_sum;
	Send_turn(temp_sum);
	while((USART1->SR&0X40)==0);//等待发送结束
	delay_ms(2);
}
void ping(unsigned char id)
{
	unsigned char temp_sum=0;
	Send_turn(0xff);
	Send_turn(0xff);
	Send_turn(id);
	Send_turn(0x02);
	Send_turn(0x01);
	temp_sum=id+0x02+0x01;
	temp_sum=~temp_sum;
	Send_turn(temp_sum);
	while((USART1->SR&0X40)==0);//等待发送结束
	delay_ms(2);		
}
