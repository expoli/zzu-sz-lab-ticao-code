#include "delay.h"

void Delay(u32 us)
{
	 u32 temp;				
	 SysTick->LOAD = 9*us;	//SysTick为24位定时器，所以ms最大为	1864
	 SysTick->VAL=0X00;//清空计数器
	 SysTick->CTRL=0X01;//使能，减到零是无动作，采用外部时钟源
	 do
	 {
	  temp=SysTick->CTRL;
	 }while((temp&1)&&(!(temp&(1<<16))));//等待时间到达
	 SysTick->CTRL=0x00; //关闭计数器	
}

void Delay_ms(uint32_t ms)
{	
	u32 temp;
	
	SysTick->LOAD = 21000;
	SysTick->VAL=0X00;	//清空计数器
	SysTick->CTRL=0X01;	//使能，减到零是无动作，采用外部时钟源
	
	while(ms--)
	{
		 do
		 {
			temp=SysTick->CTRL;
		 }while((temp&1)&&(!(temp&(1<<16))));//等待时间到达
	}
	
	SysTick->CTRL=0x00; //关闭计数器		
}
