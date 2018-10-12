
#include "stm32f10x.h"
#include "config.h"
#include "usart.h"
#include "sys.h"
#include "delay.h"
#include "oled096.h"
#include "action.h"

#include "timer.c"
#include "adc.c"

/******************************************************************************/
/******************************************************************************/
void adc_deal(void);
void adc_disp(void);
/******************************************************************************/
/******************************************************************************/
void delay_s(u32 i)
{
	while(i--);
}
/******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);//使能GPIOB,GPIOA,AFIO;
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	//配置A端口
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3; //PA2是SDA，PA3是SCL
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //速度
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //复用推挽输出	
	GPIO_Init(GPIOA, &GPIO_InitStructure);            //对选中管脚初始化	
	GPIO_SetBits(GPIOA, GPIO_Pin_2|GPIO_Pin_3);
	
	//配置B端口
	GPIO_InitStructure.GPIO_Pin = LED_PIN;         //PB2是LED
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; //速度
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //通用推挽输出
	GPIO_Init(LED_PORT, &GPIO_InitStructure);            //对选中管脚初始化	
	GPIO_ResetBits(LED_PORT, LED_PIN);         //亮
}
/******************************************************************************/
void LED0_On(void)
{
	GPIO_SetBits(LED_PORT,LED_PIN);
}
/***************************************/
void LED0_Off(void)
{
	GPIO_ResetBits(LED_PORT,LED_PIN);
}
/***************************************/
void LED0_Toggle(void)
{
	if(LED_PORT->IDR & LED_PIN)
		{
			GPIO_ResetBits(LED_PORT,LED_PIN);
		}
	else
		{
			GPIO_SetBits(LED_PORT,LED_PIN);
		}
}
/******************************************************************************/  

/******************************************************************************/
void adc_deal(void)
{
	u32 i,adcx=0;
	u8 qian,bai,shi,ge;
	
	for(i=0;i<16;i++)
	{adcx=adcx+ad_value[i];}
	adcx=adcx/16;
	adcx=adcx*328*57/40960;   //电压分压是10K--47K，所以*57；
	printf("ad4 = %4d\r\n",adcx);
	
	qian=adcx/1000;
	bai=(adcx%1000)/100;
	shi=(adcx%100)/10;
	ge =adcx%10;
	
	if(qian==0)
		{
			OLED_ShowNUM(24,2,bai);
			OLED_ShowNUM(40,2,10);
			OLED_ShowNUM(56,2,shi);
			OLED_ShowNUM(72,2,ge);
			OLED_ShowNUM(88,2,11);
		}
	else
		{
			OLED_ShowNUM(24,2,qian);
			OLED_ShowNUM(40,2,bai);
			OLED_ShowNUM(56,2,10);
			OLED_ShowNUM(72,2,shi);
			OLED_ShowNUM(88,2,ge);
		}
}
/******************************************************************************/
void adc_disp(void)
{
	u32 adcx;
	u8 qian,bai,shi,ge;
	
	adcx=Get_Adc(ADC_Channel_4)*328*57/40960;
	printf("ad4 = %4d\r\n",adcx);
	
	qian=adcx/1000;
	bai=(adcx%1000)/100;
	shi=(adcx%100)/10;
	ge =adcx%10;
	
	if(qian==0)
		{
			OLED_ShowNUM(24,2,bai);
			OLED_ShowNUM(40,2,10);
			OLED_ShowNUM(56,2,shi);
			OLED_ShowNUM(72,2,ge);
			OLED_ShowNUM(88,2,11);
		}
	else
		{
			OLED_ShowNUM(24,2,qian);
			OLED_ShowNUM(40,2,bai);
			OLED_ShowNUM(56,2,10);
			OLED_ShowNUM(72,2,shi);
			OLED_ShowNUM(88,2,ge);
		}
}
/******************************************************************************/


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//分组2
	GPIO_Configuration();
	uart_init(115200);  //串口1
	adc_DMA_Init();  //Adc_Init();
	delay_init();
	delay_s(0x3fffff);
	TIM2_Init();  //10ms定时
	printf("Init OK!!!\r\n");
	
	OLED_Init(); //OLED初始化
	OLED_Fill(0xff); //
	delay_s(0x1fffff);
	OLED_Fill(0x00); //屏全灭
	delay_s(0xfffff);
	OLED_ShowCN(0,0,0);
	OLED_ShowCN(16,0,1);
	OLED_ShowCN(32,0,2);
	OLED_ShowCN(48,0,3);
	OLED_ShowCN(64,0,4);
	OLED_ShowCN(80,0,5);
	OLED_ShowCN(96,0,6);
	OLED_ShowCN(112,0,7);
	
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init();	     //延时初始化 
	uart_init(115200);	 //串口初始化为9600
	
	while(1)
	{
		if(timer_cntr>=50)  //0.5S
		{
			timer_cntr=0;
			LED0_Toggle();
			//adc_disp();
			adc_deal();
		}

		stand();
		delay_ms(1000);
		stand();
		delay_ms(1000);
		
		left_turn();//完成
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

		//zibian();
		//zibian1();
		zibian3();
		zibian0();
		//zibian2();
		bow();
		wave();
		
		delay_ms(5000);
		stand();
		delay_ms(5000);
		delay_ms(5000);
		while(1)
		{
			stand();
			delay_ms(5000);
			delay_ms(5000);
		}
	}
	return 0;
}