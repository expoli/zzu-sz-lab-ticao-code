//#include <stm32f10x_lib.h>
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "action.h"

//Mini STM32开发板范例代码3
//串口实验
//正点原子@ALIENTEK
//技术论坛:www.openedv.com	
int main(void)
{
	u8 flag;

	u16 times = 0;
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化 
	uart_init(115200);	 //串口初始化为9600
	//LED_Init();

	//SetServoLimit(10,0,1023);		  	 
	//SetServoLimit(12,0,1023);
	//	while(key0==1) ;
	while (1)
	{

		stand();
		delay_ms(1000);
		stand();
		delay_ms(1000);
		
		/*left_turn();//完成
		left_turn();//完成
		//left_turn();//完成

		bow();		//ok
		wave();		//ok
		stand();
		delay_ms(1000);

		before_toss();
		behind_toss();//over
		push_up();
		left_turn();//完成
		right_turn();
		stand_on_head();	

		//zibian();*/
		//zibian1();
		//zibian3();
		zibian0();
		//bow();
		//wave();
		delay_ms(5000);
		stand();
		delay_ms(5000);
		delay_ms(5000);
		while (1)
		{
			delay_ms(5000);
		}

	}
}



