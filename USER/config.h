
/**************************************************/
#define UART1_BUFF_SIZE		128

#define LED_PORT	GPIOB
#define LED_PIN		GPIO_Pin_2
/**************************************************/
u32 timer_cntr;

u8 Uart1RecBuff[UART1_BUFF_SIZE];//串口1
u8 Uart1SndBuff[UART1_BUFF_SIZE];
u8  rcv1_flag;
u32 usart1_count;

u16 ad_value[32];
/**************************************************/
