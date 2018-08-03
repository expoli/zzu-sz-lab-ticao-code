#include "action.h"
#include "delay.h"
#include "usart.h"
//立正
void stand()
{
	//stand
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300); 
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);  
	Action();
}
//鞠躬
void bow()
{
	Action_write(3, 392, 300);
	Action_write(4, 436, 300);
	Action_write(5, 663, 300);
	Action_write(6, 632, 300);
	Action();
	delay_ms(300);
	Action_write(2, 329, 350);
	Action();
	delay_ms(600);
	Action_write(2, 491, 350);
	Action();
	delay_ms(500);

}
//挥手
void wave()
{
	//抬起至水平
	Action_write(3, 742, 300);
	Action();
	delay_ms(800);

	//第一次挥手
	Action_write(4, 810, 450);
	Action_write(3, 820, 300);
	Action();
	delay_ms(800);

	//复位 到斜上∠ 45°
	Action_write(4, 510, 450);
	Action_write(3, 742, 300);
	Action();
	delay_ms(800);

	//第二次 挥手
	Action_write(4, 810, 450);
	Action_write(3, 820, 300);
	Action();
	delay_ms(800);

    //复位
	Action_write(3, 392, 300);
	Action_write(4, 436, 450);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}
//前翻
void before_toss()
 {
	//1.预备2，在这里机器趴下
	Action_write(1, 180, 600);
	Action_write(2, 253, 500);
	Action_write(3, 414, 300);
	Action_write(4, 538, 300);
	Action_write(5, 641, 300);
	Action_write(6, 502, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);

	//翻手
	Action_write(3, 553, 300);
	Action_write(4, 738, 300);
	Action_write(5, 489, 300);
	Action_write(6, 313, 300);
	Action();
	delay_ms(100);

	//翻勃子
	Action_write(1, 657, 300);
	Action_write(2, 126, 200);
	Action_write(3, 547, 300);
	Action_write(4, 741, 300);
	Action_write(5, 517, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);

	//3.抬右腿
	Action_write(9, 858, 300);
	Action();								
	delay_ms(1000);
	delay_ms(800);

	//4.提腿，上腰//1慢增加稳定性  觉得慢调2
	Action_write(7, 750, 800);
	Action_write(1, 468, 300);
	Action_write(2, 193, 300);
	Action();
	delay_ms(1000);

	//5.大劈叉预备
	Action_write(7, 497, 300);
	Action_write(8, 545, 300);
	Action_write(9, 551, 300);
	Action();
	delay_ms(1000);

	//6.大劈叉 倒立
	Action_write(2, 488, 400);
	Action_write(8, 860, 300);
	Action_write(9, 241, 300);
	Action();
	delay_ms(800);

	//8.下腰，腿与腰垂直
	Action_write(2, 780, 150);
	Action();								
	delay_ms(1000);
	delay_ms(800);
	//9.下脖子，准备站立减7
	Action_write(1, 320, 75);
	Action();								
	delay_ms(1000);
	delay_ms(500);

	//10.抬脖子
	Action_write(1, 720, 300);
	Action_write(2, 748, 300);
	Action();
	delay_ms(650);
	//11.翻脖子站立准备
	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);

	//这里应该加一个动作1   在650佑?50之间动作太大
	//12.抬身子，尝试站立
	Action_write(1, 741, 300);
	Action_write(2, 744, 300);
	Action_write(3, 309, 300);
	Action_write(4, 576, 300);
	Action_write(5, 714, 300);
	Action_write(6, 509, 300);
	Action();
	delay_ms(1000);
	//13.抬身子，尝试站立
	Action_write(1, 682, 300);
	Action_write(2, 740, 300);
	Action_write(3, 346, 300);
	Action_write(4, 561, 300);
	Action_write(5, 744, 300);
	Action_write(6, 483, 300);
	Action();
	delay_ms(300);

	Action_write(1, 501, 300);
	Action_write(2, 491, 400);
	Action_write(3, 360, 300);
	Action_write(4, 497, 300);
	Action_write(5, 683, 300);
	Action_write(6, 550, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	delay_ms(500);



}
//后翻
void behind_toss() {


	//1,后仰	、1，2速度快了就恶意下去
	Action_write(1, 863, 650);	
	Action_write(2, 756, 655);
	Action_write(3, 378, 300);
	Action_write(4, 582, 300);
	Action_write(5, 677, 300);
	Action_write(6, 456, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	delay_ms(250);

	//翻手
	Action_write(1, 325, 300);		
	Action_write(2, 853, 300);
	Action_write(3, 553, 300);
	Action_write(4, 738, 300);
	Action_write(5, 489, 300);
	Action_write(6, 313, 300);
	Action();
	delay_ms(1000);
	delay_ms(800);
	//3.抬右腿
	Action_write(8, 235, 300);
	Action();
	delay_ms(1000);
	delay_ms(800);
	//上来
	Action_write(1, 498, 300);
	Action_write(2, 833, 300);
	Action_write(10, 744, 850);
	Action();
	delay_ms(1000);

	//5.大劈叉预备
	Action_write(10, 502, 300);
	Action_write(8, 538, 300);
	Action_write(9, 555, 300);
	Action();
	delay_ms(1000);
	//7.倒立
	Action_write(2, 485, 400);
	Action_write(8, 856, 300);
	Action_write(9, 243, 300);
	Action();
	delay_ms(800);

	//8.下腰，腿与腰垂直
	Action_write(2, 229, 150);
	Action();								
	delay_ms(1000);
	delay_ms(800);


	//9.下脖子，准备站立减7
	Action_write(1, 704, 75);
	Action();								
	delay_ms(1000);
	delay_ms(500);
	//10.抬脖子
	Action_write(1, 174, 300);
	Action_write(2, 230, 300);
	Action();
	delay_ms(800);
	//11.翻脖子站立准备
	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);

	//12.抬身子，尝试站立
	Action_write(1, 257, 300);
	Action_write(2, 271, 300);
	Action_write(3, 339, 300);
	Action_write(4, 511, 300);
	Action_write(5, 711, 300);
	Action_write(6, 536, 300);
	Action();
	delay_ms(1000);

	//立正预备，腰收回
	Action_write(1, 239, 300);
	Action_write(2, 228, 300);
	Action_write(3, 385, 300);
	Action_write(4, 488, 300);
	Action_write(5, 671, 300);
	Action_write(6, 540, 300);
	Action();
	delay_ms(300);
	//stand
	Action_write(1, 501, 300);
	Action_write(2, 491, 300);
	Action_write(3, 360, 300);
	Action_write(4, 497, 300);
	Action_write(5, 683, 300);
	Action_write(6, 550, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}
//俯卧撑
void push_up()
{
	//趴下去	
	Action_write(1, 180, 600);
	Action_write(2, 239, 500);
	Action_write(3, 410, 350);
	Action_write(4, 498, 400);
	Action_write(5, 644, 350);
	Action_write(6, 532, 400);			
	Action();
	delay_ms(1000);
	delay_ms(200);
	//俯卧撑，预备1，，，first time
	Action_write(1, 253, 600);
	Action_write(2, 442, 300);
	Action_write(3, 410, 300);
	Action_write(4, 452, 300);
	Action_write(5, 633, 300);
	Action_write(6, 582, 300);
	// 	Action_write(7,498,300);		 
	//腿立正
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	//2.双手夹紧
	Action_write(1, 309, 300);
	Action_write(2, 512, 500);
	Action_write(3, 307, 350);
	Action_write(4, 426, 400);
	Action_write(5, 741, 200);
	Action_write(6, 622, 200);			
	Action();
	delay_ms(1000);
	//***********************************************
	//leftpushup
	//***********************************************


	//3. 3，4回收预备
	Action_write(3, 408, 350);
	Action_write(4, 274, 400);	
	Action();
	delay_ms(500);
	//4.  3，4水平
	Action_write(3, 563, 350);
	Action_write(4, 539, 400);	
	Action();
	delay_ms(500);

	//6.另一只手上去
	Action_write(3, 822, 350);
	Action_write(4, 809, 400);	
	Action();
	delay_ms(800);//1000

	//7.单手支撑预备2，下去
	Action_write(1, 240, 250);
	Action_write(2, 512, 500);
	Action_write(5, 600, 250);
	Action_write(6, 831, 400);			
	Action();
	delay_ms(800);
	 //8.单手支撑预备second time
	Action_write(1, 300, 300);
	Action_write(2, 512, 500);
	Action_write(5, 741, 250);
	Action_write(6, 622, 400);
	Action();
	delay_ms(800);
	 //9.单手支撑预备2，下去
	Action_write(1, 240, 250);
	Action_write(2, 512, 500);
	Action_write(5, 600, 250);
	Action_write(6, 831, 400);
	Action();
	delay_ms(800);

	 //10.单手支撑预备finally，准备站立
	Action_write(1, 300, 300);
	Action_write(2, 512, 500);
	Action_write(5, 741, 250);
	Action_write(6, 622, 400);
	Action();
	delay_ms(800);
	delay_ms(100);

	//11.  3，4水平
	Action_write(3, 563, 350);
	Action_write(4, 274, 400);
	Action();
	delay_ms(800);

	//12. 3，4回收预备
	Action_write(3, 408, 350);
	Action_write(4, 274, 400);
	Action();
	delay_ms(500);



	Action_write(1, 300, 300);
	Action_write(3, 307, 350);
	Action_write(4, 426, 400);
	Action();
	delay_ms(800);


	//*************************************************
	//rightpushup
	//*************************************************
	//3. 5，6回收，准备抬起，防止直接抬起蹭地
	Action_write(5, 679, 200);
	Action_write(6, 739, 200);			
	Action();
	delay_ms(800);
	//4.5，6回收预备
	Action_write(5, 478, 200);
	Action_write(6, 500, 200);			
	Action();
	delay_ms(800);

	//5另一只手上去
	Action_write(5, 226, 350);
	Action_write(6, 178, 400);	
	Action();
	delay_ms(800);
	//6手下去2
	Action_write(1, 247, 300);
	Action_write(2, 480, 500);
	Action_write(3, 465, 250);
	Action_write(4, 212, 380);	
	Action();
	delay_ms(800);
	//7单手支撑预备1，，，second time
	Action_write(1, 261, 300);
	Action_write(2, 480, 500);
	Action_write(3, 307, 250);
	Action_write(4, 426, 380);
	Action();
	delay_ms(800);
	//8手下去2，，，second  time
	Action_write(1, 248, 300);
	Action_write(2, 480, 500);
	Action_write(3, 465, 250);
	Action_write(4, 212, 380);
	Action();
	delay_ms(800);
	//9单手支撑预备1，，，finally
	Action_write(1, 261, 300);
	Action_write(2, 480, 500);
	Action_write(3, 307, 250);
	Action_write(4, 426, 380);		
	Action();
	delay_ms(800);
	//10.4，5，6回收预备
	Action_write(5, 478, 300);
	Action_write(6, 739, 400);		
	Action();
	delay_ms(800);

	//11.3， 5，6回收，准备抬起，防止直接抬起蹭地
	Action_write(5, 679, 300);
	Action_write(6, 739, 400);
	Action();
	delay_ms(800);

	//为了矫正。。。成功
	Action_write(5, 741, 200);
	Action_write(6, 622, 200);
	Action();
	delay_ms(500);
	//手夹紧
	Action_write(1, 301, 100);
	Action_write(2, 462, 500);
	Action_write(3, 305, 200);
	Action_write(4, 478, 400);
	Action_write(5, 731, 200);
	Action_write(6, 576, 400);
	Action();
	delay_ms(800);
	delay_ms(200);

	//*************************************************
	//pushup
	//*************************************************

	//减5，为了矫正
	//俯卧撑，2，下去，，，，，first time
	Action_write(3, 574, 400);
	Action_write(4, 220, 330);
	Action_write(5, 467, 400);
	Action_write(6, 824, 330);
	Action_write(1, 238, 100);
	Action_write(2, 493, 500);

	//腿立正
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(800);

	//手夹紧
	Action_write(1, 301, 100);
	Action_write(2, 462, 400);
	Action_write(3, 305, 400);
	Action_write(4, 478, 330);
	Action_write(5, 731, 400);
	Action_write(6, 576, 330);			
	Action();
	delay_ms(800);
	delay_ms(200);

	//俯卧撑，2，下去，，，，，first time
	Action_write(3, 574, 400);
	Action_write(4, 220, 330);
	Action_write(5, 467, 400);
	Action_write(6, 824, 330);
	Action_write(1, 238, 100);			
	Action_write(2, 493, 500);

	//腿立正
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(800);
	//手夹紧FINALLY 
	Action_write(1, 301, 100);
	Action_write(2, 462, 400);
	Action_write(3, 305, 400);
	Action_write(4, 478, 330);
	Action_write(5, 731, 400);
	Action_write(6, 576, 330);			
	Action();
	delay_ms(800);
	delay_ms(200);

	//立正预备1，双手打开。。。。来自 push up
	Action_write(3, 410, 300);
	Action_write(4, 452, 300);
	Action_write(5, 633, 300);
	Action_write(6, 582, 300);
	Action();
	delay_ms(800);
	//立正预备，腰收回
	Action_write(1, 239, 300);
	Action_write(2, 228, 300);
	Action_write(3, 385, 300);
	Action_write(4, 488, 300);
	Action_write(5, 671, 300);
	Action_write(6, 540, 300);
	Action();
	delay_ms(800);

	//立正
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);  
	Action_write(5, 663, 300);  
	Action_write(6, 632, 300); 
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}
//左滚翻
void left_turn()
{
	//预备
	Action_write(1, 488, 300);
	Action_write(2, 491, 300);
	Action_write(3, 618, 300);
	Action_write(4, 690, 300);
	Action_write(5, 482, 300);
	Action_write(6, 337, 300);
	Action_write(7, 548, 400);
	Action_write(8, 865, 300);
	Action_write(9, 173, 300);
	Action_write(10, 349, 300);
	Action();
	delay_ms(1000);

	//侧着站
 	Action_write(5,487,300);
  Action_write(6,281,300);
	Action_write(7,509,400);
	Action_write(8,859,300);
	Action_write(9,359,300);
	Action_write(10,355,300);
	Action();
	delay_ms(1000);
	delay_ms(200);

	//抱手 翻滚，主要抬腿
	Action_write(3,787,300);
	Action_write(4,909,300);
	Action_write(5,313,300);
	Action_write(6,152,300);
	Action_write(7,485,450);
	Action_write(8,884,300);
	Action_write(9,715,300);
	Action_write(10,517,300);
	Action();
	delay_ms(1000);
	delay_ms(200);

   	//翻滚
	Action_write(7,505,700);
	Action_write(8,359,900);
	Action_write(9,690,950);	
	Action_write(10,784,950);
	Action();
	delay_ms(1000);
	delay_ms(300);
	//滚后，侧起单脚单手站立 过渡
	Action_write(3, 603, 300);
	Action_write(4, 759, 300);
	Action_write(5, 522, 300);
	Action_write(6, 283, 300);
	Action_write(7, 475, 300);
	Action_write(8, 491, 150);
	Action_write(9, 245, 300);
	Action_write(10, 510, 300);
	Action();
	delay_ms(1000);
	delay_ms(300);
	//滚后，侧起单脚单手站立
	Action_write(3, 594, 300);
	Action_write(4, 592, 300);
	Action_write(5, 512, 300);
	Action_write(6, 381, 300);
	Action_write(7, 468, 300);
	Action_write(8, 815, 150);
	Action_write(9, 237, 300);
	Action_write(10, 499, 300);
	Action();
	delay_ms(1000);
	delay_ms(300);
	//stand
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);  
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300); 
	Action();
	delay_ms(1000);
	delay_ms(1000);


}
//右滚翻
void right_turn()
{
	//预备
	Action_write(1, 491, 300);
	Action_write(2, 499, 300);
	Action_write(3, 517, 300);
	Action_write(4, 613, 300);
	Action_write(5, 341, 300);
	Action_write(6, 128, 300);
	Action_write(7, 623, 300);
	Action_write(8, 922, 300);
	Action_write(9, 249, 150);
	Action_write(10, 498, 150);
	Action();
	delay_ms(1000);

	//侧身
	Action_write(3, 568, 300);
	Action_write(4, 670, 300);
	Action_write(7, 604, 150);
	Action_write(8, 685, 300);
	Action();
	delay_ms(1000);
	delay_ms(200);

	//抱手
	Action_write(3, 784, 250);
	Action_write(4, 916, 250);
	Action_write(5, 310, 300);
	Action_write(6, 144, 300);
	Action_write(7, 459, 300);
	Action_write(8, 369, 400);
	Action();
	delay_ms(1000);
	delay_ms(100);

	//翻滚
	Action_write(7, 206, 700);
	Action_write(8, 399, 700);
	Action_write(9, 703, 750);
	Action_write(10, 496, 750);
	Action();
	delay_ms(1000);
	delay_ms(300);
	//准备起立
	Action_write(3, 565, 200);
	Action_write(4, 584, 300);
	Action_write(5, 501, 200);
	Action_write(6, 466, 200);
	Action_write(7, 512, 200);
	Action_write(8, 838, 300);
	Action_write(9, 522, 300);
	Action_write(10, 557, 200);
	Action();
	delay_ms(1000);
	//准备起立
	Action_write(3, 604, 200);
	Action_write(4, 584, 300);
	Action_write(5, 501, 200);
	Action_write(6, 466, 200);
	Action_write(7, 512, 200);
	Action_write(8, 838, 300);
	Action_write(9, 304, 300);
	Action_write(10, 537, 200);
	Action();
	delay_ms(1000);
	delay_ms(200);
	//stand
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300); 
	Action_write(9, 244, 300);
	Action_write(10, 506, 300); 
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}

	//倒立并腿——倒立劈叉
void stand_on_head()
{
	//1.预备2，在这里机器趴下
	Action_write(1, 180, 600);
	Action_write(2, 253, 500);
	Action_write(3, 414, 300);
	Action_write(4, 538, 300);
	Action_write(5, 641, 300);
	Action_write(6, 502, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	//翻手
	Action_write(3, 553, 300);
	Action_write(4, 738, 300);
	Action_write(5, 489, 300);
	Action_write(6, 313, 300);
	Action();
	delay_ms(100);
	//翻勃子
	Action_write(1, 657, 300);
	Action_write(2, 126, 200);
	Action_write(3, 547, 300);
	Action_write(4, 741, 300);
	Action_write(5, 517, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	//3.抬右腿
	Action_write(9, 858, 300);
	Action();				
	delay_ms(1000);
	delay_ms(800);
	//4.提腿，上腰//1慢增加稳定性  觉得慢调2
	Action_write(7, 750, 800);
	Action_write(1, 468, 300);
	Action_write(2, 193, 300);
	
	Action();
	delay_ms(1000);
	//5.大劈叉预备
	Action_write(7, 497, 300);
	Action_write(8, 545, 300);
	Action_write(9, 551, 300);
	Action();
	delay_ms(1000);

	//7.倒立
	Action_write(2, 488, 400);
	Action_write(8, 860, 300);
	Action_write(9, 241, 300);
	Action();								
	delay_ms(800);
	//8.倒立后将将身提举起来
	Action_write(3, 795, 300);
	Action_write(4, 529, 300);
	Action_write(5, 233, 300);
	Action_write(6, 502, 300);
	Action();
	delay_ms(1000);
	delay_ms(200);
	//10.劈叉
	//倒立劈叉
	Action_write(7, 179, 300);
	Action_write(8, 536, 300);
	Action_write(9, 551, 300);
	Action_write(10, 816, 300);
	Action();
	delay_ms(1000);
	delay_ms(200);
	//11.倒立
	Action_write(7, 497, 300);
	Action_write(8, 858, 300);
	Action_write(9, 246, 300);
	Action_write(10, 509, 300);
	Action();								
	delay_ms(1000);
	delay_ms(200);

	///后滚翻的站立
	//9.将手放下去
	Action_write(3, 533, 300);
	Action_write(4, 722, 300);
	Action_write(5, 495, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1200);


	//8.下腰，腿与腰垂直
	Action_write(2, 780, 150);
	Action();
	delay_ms(1000);
	delay_ms(800);
	//9.下脖子，准备站立减7
	Action_write(1, 320, 75);
	Action();
	delay_ms(1000);
	delay_ms(500);
	//10.抬脖子
	Action_write(1, 720, 300);
	Action_write(2, 748, 300);
	Action();								
	delay_ms(650);
	//11.翻脖子站立准备
	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);
	//这里应该加一个动作1   在650佑?50之间动作太大
	//12.抬身子，尝试站立
	Action_write(1, 741, 300);
	Action_write(2, 744, 300);
	Action_write(3, 309, 300);
	Action_write(4, 576, 300);
	Action_write(5, 714, 300);
	Action_write(6, 509, 300);
	Action();
	delay_ms(1000);
	//13.抬身子，尝试站立
	Action_write(1, 682, 300);
	Action_write(2, 740, 300);
	Action_write(3, 346, 300);
	Action_write(4, 561, 300);
	Action_write(5, 744, 300);
	Action_write(6, 483, 300);
	Action();
	delay_ms(300);
	//立正
	Action_write(1, 501, 300);
	Action_write(2, 491, 400);
	Action_write(3, 360, 300);
	Action_write(4, 497, 300);
	Action_write(5, 683, 300);
	Action_write(6, 550, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
}

//金鸡独立
void zibian1()
{
	//立正
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300); 
	Action_write(9, 244, 300);	
	Action_write(10, 506, 300);  
	Action();

	//后仰
	Action_write(2, 639, 300);
	Action();
	delay_ms(1000);
	//第一次手平
	Action_write(1, 638, 300);
	Action_write(3, 561, 300);
	Action_write(4, 555, 300);
	Action_write(5, 491, 300);
	Action_write(6, 479, 300);
	Action();
	delay_ms(1000);
	//第一次手弯曲0
	Action_write(1, 703, 100);
	Action_write(2, 693, 50);
	Action_write(3, 418, 300);
	Action_write(4, 844, 500);
	Action_write(5, 406, 300);
	Action_write(6, 727, 500);
	Action();
	delay_ms(900);
	//第二次手弯曲1
	Action_write(1, 703, 100);
	Action_write(2, 693, 50);
	Action_write(3, 663, 300);
	Action_write(4, 316, 500);
	Action_write(5, 660, 300);
	Action_write(6, 231, 500);
	Action();
	delay_ms(1000);
	//侧身
	Action_write(7, 620, 100);
	Action_write(8, 921, 100);
	Action_write(9, 284, 150);
	Action_write(10, 594, 100);
	Action();
	delay_ms(900);
	//上腿，抬9
	Action_write(9, 841, 110);
	Action_write(10, 618, 100);
	Action();		
	delay_ms(1000);
	delay_ms(1000);
	//第2次调平
	Action_write(3, 561, 300);
	Action_write(4, 555, 300);
	Action_write(5, 491, 300);
	Action_write(6, 479, 300);
	Action();
	delay_ms(1000);
	//第一次手弯曲0
	Action_write(3, 418, 300);
	Action_write(4, 844, 500);
	Action_write(5, 406, 300);
	Action_write(6, 727, 500);
	Action_write(9, 888, 250);
	Action_write(10, 356, 150);
	Action();
	delay_ms(1000);
	//第二次手弯曲1
	Action_write(3, 663, 300);
	Action_write(4, 316, 500);
	Action_write(5, 660, 300);
	Action_write(6, 231, 500);
	Action_write(9, 813, 250);
	Action_write(10, 701, 150);
	Action();
	delay_ms(1000);
	//第3次调平
	Action_write(3, 561, 300);
	Action_write(4, 555, 300);
	Action_write(5, 491, 300);
	Action_write(6, 479, 300);
	Action();
	delay_ms(1000);
	//收腿
	Action_write(9, 244, 150);
	Action_write(10, 506, 75);
	Action();
	delay_ms(1000);
	delay_ms(1200);
	//过渡
	Action_write(1, 531, 200);  
	Action_write(2, 533, 200);  
	Action_write(3, 501, 200);  
	Action_write(4, 509, 200);
	Action_write(5, 584, 200); 
	Action_write(6, 582, 200); 
	Action_write(7, 505, 200); 
	Action_write(8, 861, 200); 
	Action_write(9, 247, 200);
	Action_write(10, 511, 200);
	Action();
	delay_ms(800);
	//站立
	Action_write(1, 483, 200);  
	Action_write(2, 496, 200);  
	Action_write(3, 392, 200);  
	Action_write(4, 436, 200);
	Action_write(5, 663, 200); 
	Action_write(6, 632, 200); 
	Action_write(7, 495, 200); 
	Action_write(8, 851, 200); 
	Action_write(9, 244, 200);
	Action_write(10, 506, 200);
	Action();
	delay_ms(1000);
}
//摇摆 摇摆
void zibian2()
{
	//过渡 手打平
	Action_write(3, 518, 300);
	Action_write(4, 612, 300);
	Action_write(5, 502, 300);
	Action_write(6, 449, 300);
	Action_write(7, 483, 300);
	Action_write(8, 844, 300);
	Action_write(9, 251, 300);
	Action_write(10, 515, 300);
	Action();
	delay_ms(1000);
	//右跨一步	手弯折 摆poss
	Action_write(3, 684, 300);
	Action_write(4, 901, 300);
	Action_write(5, 508, 300);
	Action_write(6, 458, 300);
	Action_write(7, 515, 300);
	Action_write(8, 905, 300);
	Action_write(9, 391, 300);
	Action_write(10, 626, 300);
	Action();
	delay_ms(1000);
	//收腿
	Action_write(3, 518, 300);
	Action_write(4, 612, 300);
	Action_write(5, 502, 300);
	Action_write(6, 412, 300);
	Action_write(7, 415, 300);
	Action_write(8, 754, 300);
	Action_write(9, 233, 300);
	Action_write(10, 512, 300);
	Action();
	delay_ms(1000);
	//过渡 手打平
	Action_write(3, 518, 300);
	Action_write(4, 612, 300);
	Action_write(5, 502, 300);
	Action_write(6, 449, 300);
	Action_write(7, 483, 300);
	Action_write(8, 844, 300);
	Action_write(9, 251, 300);
	Action_write(10, 515, 300);
	Action();
	delay_ms(1000);
	//右poss
	Action_write(3, 590, 300);
	Action_write(4, 587, 300);
	Action_write(5, 434, 300);
	Action_write(6, 129, 300);
	Action_write(7, 376, 300);
	Action_write(8, 697, 300);
	Action_write(9, 182, 300);
	Action_write(10, 478, 300);
	Action();
	delay_ms(1000);
	//stand
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300); 
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);  
	Action();
	delay_ms(1000);
}
//倒立	腿上动作	暂时没想到名字
void zibian3()
{
	//1.预备2，在这里机器趴下
	Action_write(1, 190, 500);
	Action_write(2, 253, 400);
	Action_write(3, 414, 300);
	Action_write(4, 538, 300);
	Action_write(5, 641, 300);
	Action_write(6, 502, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	//翻手
	Action_write(3, 553, 300);
	Action_write(4, 738, 300);
	Action_write(5, 489, 300);
	Action_write(6, 313, 300);
	Action();
	delay_ms(100);
	//翻勃子
	Action_write(1, 657, 300);
	Action_write(2, 126, 200);
	Action_write(3, 547, 300);
	Action_write(4, 741, 300);
	Action_write(5, 517, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	//3.抬右腿
	Action_write(9, 858, 300);
	Action();									
	delay_ms(1000);
	delay_ms(800);
	//4.提腿，上腰
	//1慢增加稳定性  觉得慢调2
	Action_write(1, 468, 300);
	Action_write(2, 193, 300);
	Action_write(7, 750, 800);
	Action();
	delay_ms(1000);
	//5.大劈叉预备
	Action_write(7, 497, 300);
	Action_write(8, 545, 300);
	Action_write(9, 551, 300);
	Action();
	delay_ms(1000);
	//手弯折 手臂着地
	Action_write(1, 495, 200);
	Action_write(2, 193, 200);
	Action_write(3, 846, 200);
	Action_write(4, 284, 200);
	Action_write(5, 202, 200);
	Action_write(6, 782, 200);
	Action_write(7, 495, 200);
	Action_write(8, 546, 200);
	Action_write(9, 553, 200);
	Action_write(10, 503, 200);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	//调整腿
	Action_write(2, 498, 320);
	Action();
	delay_ms(600);
	//支撑摆POSS
	Action_write(3, 829, 200);
	Action_write(4, 528, 200);
	Action_write(5, 228, 200);
	Action_write(6, 838, 200);
	Action_write(7, 763, 200);
	Action_write(8, 861, 200);
	Action_write(9, 248, 200);
	Action_write(10, 738, 200);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	//手弯折 手臂着地
	Action_write(3, 846, 200);
	Action_write(4, 284, 200);
	Action_write(5, 202, 200);
	Action_write(6, 782, 200);
	Action_write(7, 495, 200);
	Action_write(8, 546, 200);
	Action_write(9, 553, 200);
	Action_write(10, 503, 200);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	//右边
	//支撑摆POSS
	Action_write(3, 732, 200);
	Action_write(4, 333, 200);
	Action_write(5, 286, 200);
	Action_write(6, 489, 200);
	Action_write(7, 298, 200);
	Action_write(8, 844, 200);
	Action_write(9, 248, 200);
	Action_write(10, 266, 200);
	Action();
	delay_ms(1000);
	delay_ms(1000);
/*	//手弯折 手臂着地
	Action_write(3, 846, 200);
	Action_write(4, 284, 200);
	Action_write(5, 202, 200);
	Action_write(6, 782, 200);
	Action_write(7, 495, 200);
	Action_write(8, 546, 200);
	Action_write(9, 553, 200);
	Action_write(10, 503, 200);
	Action();
	delay_ms(1000);
	delay_ms(1000);*/
	//7.倒立
	Action_write(2, 488, 400);
	Action_write(3, 795, 200);
	Action_write(4, 529, 200);
	Action_write(5, 233, 200);
	Action_write(6, 502, 200);
	Action_write(7, 495, 200);
	Action_write(8, 860, 200);
	Action_write(9, 241, 200);
	Action_write(10, 503, 200);
	Action();
	delay_ms(1000);
	//9.将手放下去
	Action_write(3, 533, 300);
	Action_write(4, 722, 300);
	Action_write(5, 495, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1000);
	//8.下腰，腿与腰垂直
	Action_write(2, 229, 150);
	Action();								
	delay_ms(1000);
	delay_ms(800);
	//9.下脖子，准备站立减7
	Action_write(1, 704, 75);
	Action();								
	delay_ms(1000);
	delay_ms(500);
	//10.抬脖子
	Action_write(1, 174, 300);
	Action_write(2, 347, 300);
	Action();								
	delay_ms(800);
	//11.翻脖子站立准备
	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);
	//12.抬身子，尝试站立
	Action_write(1, 257, 300);
	Action_write(2, 271, 300);
	Action_write(3, 339, 300);
	Action_write(4, 511, 300);
	Action_write(5, 711, 300);
	Action_write(6, 536, 300);
	Action();
	delay_ms(1000);
	//立正预备，腰收回
	Action_write(1, 239, 300);
	Action_write(2, 228, 300);
	Action_write(3, 385, 300);
	Action_write(4, 488, 300);
	Action_write(5, 671, 300);
	Action_write(6, 540, 300);
	Action();
	delay_ms(300);
	//站立
	Action_write(1, 501, 300);
	Action_write(2, 491, 300);
	Action_write(3, 360, 300);
	Action_write(4, 497, 300);
	Action_write(5, 683, 300);
	Action_write(6, 550, 300);
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}
//单臂倒立
void zibian0()//
{
	//预备
	Action_write(1, 488, 300);
	Action_write(2, 491, 300);
	Action_write(3, 618, 300);
	Action_write(4, 690, 300);
	Action_write(5, 482, 300);
	Action_write(6, 337, 300);
	Action_write(7, 548, 400);
	Action_write(8, 865, 300);
	Action_write(9, 173, 300);
	Action_write(10, 349, 300);
	Action();
	delay_ms(1000);
	//侧着站
 	Action_write(5,487,300);
  	Action_write(6,281,300);
	Action_write(7,509,400);
	Action_write(8,859,300);
	Action_write(9,359,300);
	Action_write(10,355,300);
	Action();
	delay_ms(1000);
	delay_ms(200);
	//手撑地
	Action_write(1, 492, 300);
	Action_write(2, 489, 300);
	Action_write(3, 612, 300);
	Action_write(4, 661, 300);
	Action_write(5, 303, 300);
	Action_write(6, 148, 300);
	Action_write(9, 713, 300);
	Action_write(10, 511, 300);
	Action();
	delay_ms(1000);
	delay_ms(200);
	//翻滚
	Action_write(7,505,700);
	Action_write(8,359,900);
	Action_write(9,690,950);	
	Action_write(10,784,950);
	Action();
	delay_ms(1000);
	//劈叉
	Action_write(7, 179, 300);
	Action_write(8, 536, 300);
	Action_write(9, 551, 300);
	Action_write(10, 816, 300);
	Action();
	delay_ms(1000);

	//下半身 挺直
	Action_write(7, 497, 300);
	Action_write(8, 858, 300);
	Action_write(9, 246, 300);
	Action_write(10, 509, 300);
	Action();
	delay_ms(800);

	//单臂倒立开始
	Action_write(2, 491, 300);
	Action_write(3, 565, 300);
	Action_write(4, 555, 300);
	Action_write(5, 303, 100);
	Action_write(6, 148, 100);
	Action();
	delay_ms(600);

	//单臂倒立动作0
	Action_write(3, 420, 300);
	Action_write(4, 448, 300);
	Action_write(7, 260, 300);
	Action_write(10, 317, 300);
	Action();
	delay_ms(800);

	//单臂倒立动作1
	Action_write(3, 598, 300);
	Action_write(4, 459, 300);
	Action_write(7, 714, 300);
	Action_write(10, 651, 300);
	Action();
	delay_ms(800);

	//单臂倒立动作0
	Action_write(3, 420, 300);
	Action_write(4, 448, 300);
	Action_write(7, 260, 300);
	Action_write(10, 317, 300);
	Action();
	delay_ms(800);


	/*                                                                        
	Action_write(7,803,300);
	Action_write(10,803,300);
	Action_write(4,500,300);
	Action();									//单臂倒立动作1
	delay_ms(1000);
	delay_ms(200);*/
	//单臂倒立动作
	Action_write(3, 598, 300);
	Action_write(4, 459, 300);
	Action_write(7, 497, 300);
	Action_write(8, 858, 300);
	Action_write(9, 246, 300);
	Action_write(10, 509, 300);
	Action();
	delay_ms(1000);

	//挥手 下脚 准备起立
	Action_write(1, 503, 200);
	Action_write(2, 519, 200);
	Action_write(3, 562, 200);
	Action_write(4, 499, 200);
	Action_write(5, 225, 100);
	Action_write(6, 460, 100);
	Action_write(9, 679, 300);
	Action_write(10, 513, 100);
	Action();
	delay_ms(1000);

	//准备起立
	Action_write(3, 562, 200);
	Action_write(4, 662, 300);
	Action_write(5, 325, 200);
	Action_write(6, 257, 200);
	Action_write(8, 922, 300);
	Action_write(9, 679, 300);
	Action_write(10, 513, 200);
	Action();
	delay_ms(400);
	//准备起立
	Action_write(2, 492, 300);
	Action_write(3, 574, 200);
	Action_write(4, 663, 300);
	Action_write(5, 507, 200);
	Action_write(6, 409, 200);
	Action_write(7, 508, 300);
	Action_write(8, 922, 350);
	Action_write(9, 596, 250);
	Action_write(10, 602, 250);
	Action();
	delay_ms(1000);
	delay_ms(200);
	//stand
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300); 
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);  
	Action();
	delay_ms(1000);
	delay_ms(500);
	//	delay_ms(1000);

}