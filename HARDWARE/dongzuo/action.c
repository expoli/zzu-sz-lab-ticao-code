#include "action.h"
#include "delay.h"
#include "usart.h"

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

void bow()                          //弯腰
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
void wave()                        //挥手
{

	Action_write(3, 742, 300);
	Action();
	delay_ms(800);

	Action_write(4, 810, 450);
	Action_write(3, 820, 300);//第一次挥手，3,4all move
	Action();
	delay_ms(800);

	Action_write(4, 510, 450);
	Action_write(3, 742, 300);//复位
	Action();
	delay_ms(800);

	Action_write(4, 810, 450);
	Action_write(3, 820, 300);
	Action();
	delay_ms(800);//挥手


	Action_write(3, 392, 300);
	Action_write(4, 436, 450);     //复位
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}



void before_toss() {

	Action_write(1, 180, 600);
	Action_write(2, 236, 500);
	Action_write(3, 414, 300);
	Action_write(4, 538, 300);
	Action_write(5, 641, 300);//1.预备2，在这里机器趴下
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
	Action_write(1, 657, 300);//648   //704  //715
	Action_write(2, 126, 200);///154   //252
	Action_write(3, 547, 300);
	Action_write(4, 741, 300);
	Action_write(5, 517, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);



	Action_write(9, 858, 300);
	Action();									//3.抬右腿
	delay_ms(1000);
	delay_ms(800);

	Action_write(7, 750, 800);
	Action_write(1, 468, 300);
	Action_write(2, 193, 300);//4.提腿，上腰//1慢增加稳定性  觉得慢调2
	
	Action();
	delay_ms(1000);



	Action_write(7, 497, 300);
	Action_write(8, 545, 300);
	Action_write(9, 551, 300);//5.大劈叉预备
	Action();
	delay_ms(1000);
	//6.大劈叉
	Action_write(2, 488, 400);//497
	Action_write(8, 860, 300);
	Action_write(9, 241, 300);
	Action();									//7.倒立
	delay_ms(800);


	Action_write(2, 780, 150);
	// 	Action_write(2,831,150);
	Action();									//8.下腰，腿与腰垂直
	delay_ms(1000);
	delay_ms(800);

	Action_write(1, 320, 75);
	Action();									//9.下脖子，准备站立减7
	delay_ms(1000);
	delay_ms(500);


	Action_write(1, 720, 300);
	Action_write(2, 748, 300);
	Action();									//10.
	delay_ms(650);

	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);//11.翻脖子站立准备
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);

	//这里应该加一个动作1   在650佑?50之间动作太大

	Action_write(1, 741, 300);
	Action_write(2, 744, 300);
	Action_write(3, 309, 300);
	Action_write(4, 576, 300);
	Action_write(5, 714, 300);//12.抬身子，尝试站立
	Action_write(6, 509, 300);
	Action();
	delay_ms(1000);

	Action_write(1, 682, 300);
	Action_write(2, 740, 300);
	Action_write(3, 346, 300);
	Action_write(4, 561, 300);
	Action_write(5, 744, 300);//13.抬身子，尝试站立
	Action_write(6, 483, 300);
	Action();
	delay_ms(300);

	Action_write(1, 501, 300);
	Action_write(2, 491, 400);
	Action_write(3, 360, 300);
	Action_write(4, 497, 300);
	Action_write(5, 683, 300);
	Action_write(6, 550, 300);
	Action_write(7, 495, 300);   //489
	Action_write(8, 851, 300);   //185
	Action_write(9, 244, 300);		//735		 //换脚之后，的站立动作
	Action_write(10, 506, 300);   //565
	Action();
	delay_ms(1000);
	delay_ms(500);



}

void behind_toss() {


	//1,后仰	、1，2速度快了就恶意下去
	Action_write(1, 863, 650);//830			
	Action_write(2, 756, 655);//737速度680
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


	Action_write(1, 325, 300);//325  //318  			
	Action_write(2, 853, 300);//832  //818  
	Action_write(3, 553, 300);
	Action_write(4, 738, 300);
	Action_write(5, 489, 300);
	Action_write(6, 313, 300);
	Action();
	delay_ms(1000);
	delay_ms(800);

	Action_write(8, 235, 300);
	Action();									//3.抬右腿
	delay_ms(1000);
	delay_ms(800);
	//上来
	Action_write(1, 498, 300);
	Action_write(2, 833, 300);
	Action_write(10, 744, 850);
	Action();
	delay_ms(1000);

	/*Action_write(1, 502, 195);//495
	Action_write(2, 826, 200);
	//4.提腿，上腰//1慢增加稳定性  觉得慢调2
	Action();
	delay_ms(200);*/

	Action_write(10, 502, 300);
	Action_write(8, 538, 300);
	Action_write(9, 555, 300);//5.大劈叉预备
	Action();
	delay_ms(1000);

	Action_write(2, 485, 400);
	Action_write(8, 856, 300);
	Action_write(9, 243, 300);
	Action();									//7.倒立
	delay_ms(800);


	Action_write(2, 202, 150);
	// 	Action_write(2,831,150);
	Action();									//8.下腰，腿与腰垂直
	delay_ms(1000);
	delay_ms(800);



	Action_write(1, 704, 75);
	Action();									//9.下脖子，准备站立减7
	delay_ms(1000);
	delay_ms(500);

	Action_write(1, 150, 300);
	Action_write(2, 308, 300);
	Action();									//10.抬脖子
	delay_ms(800);

	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);//11.翻脖子站立准备
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);


	/////////////////////////////////
	Action_write(1, 257, 300);//151 速度250  237  142  
	Action_write(2, 271, 300);//320 速度250  247  286
	Action_write(3, 339, 300);//352
	Action_write(4, 511, 300);//513
	Action_write(5, 711, 300);//12.抬身子，尝试站立
	Action_write(6, 536, 300);//523
	Action();
	delay_ms(1000);


	Action_write(1, 239, 300);
	Action_write(2, 228, 300);
	Action_write(3, 385, 300);
	Action_write(4, 488, 300);
	Action_write(5, 671, 300);//立正预备，腰收回
	Action_write(6, 540, 300);
	Action();
	delay_ms(300);
	//4.23晚   12.  13.  动作有点不稳
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



void push_up()                                                          //俯卧撑
{

	Action_write(1, 180, 600);
	Action_write(2, 239, 500);
	Action_write(3, 410, 350);
	Action_write(4, 498, 400);
	Action_write(5, 644, 350);
	Action_write(6, 532, 400);				 //趴下去	
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

	Action_write(1, 309, 300);
	Action_write(2, 512, 500);
	Action_write(3, 307, 350);
	Action_write(4, 426, 400);
	Action_write(5, 741, 200);
	Action_write(6, 622, 200);				 //2.双手夹紧
	Action();
	delay_ms(1000);
	//***********************************************************************************************************
	//leftpushup
	//***************************************************************************************************************



	Action_write(3, 408, 350);
	Action_write(4, 274, 400);		//3. 3，4回收预备
	Action();
	delay_ms(500);

	Action_write(3, 563, 350);
	Action_write(4, 539, 400);		//4.  3，4水平
	Action();
	delay_ms(500);


	Action_write(3, 822, 350);
	Action_write(4, 809, 400);		//6.另一只手上去
	Action();
	delay_ms(800);//1000


	Action_write(1, 240, 250);
	Action_write(2, 512, 500);
	Action_write(5, 600, 250);
	Action_write(6, 831, 400);				 //7.单手支撑预备2，下去
	Action();
	delay_ms(800);

	Action_write(1, 300, 300);
	Action_write(2, 512, 500);
	Action_write(5, 741, 250);
	Action_write(6, 622, 400);					 //8.单手支撑预备second time
	Action();
	delay_ms(800);

	Action_write(1, 240, 250);
	Action_write(2, 512, 500);
	Action_write(5, 600, 250);
	Action_write(6, 831, 400);				 //9.单手支撑预备2，下去
	Action();
	delay_ms(800);


	Action_write(1, 300, 300);
	Action_write(2, 512, 500);
	Action_write(5, 741, 250);
	Action_write(6, 622, 400);					 //10.单手支撑预备finally，准备站立
	Action();
	delay_ms(800);
	delay_ms(100);


	Action_write(3, 563, 350);
	Action_write(4, 274, 400);		//11.  3，4水平
	Action();
	delay_ms(800);


	Action_write(3, 408, 350);
	Action_write(4, 274, 400);		//12. 3，4回收预备
	Action();
	delay_ms(500);



	Action_write(1, 300, 300);
	Action_write(3, 307, 350);
	Action_write(4, 426, 400);
	Action();
	delay_ms(800);


	//***********************************************************************************************************
	//rightpushup
	//***************************************************************************************************************

	Action_write(5, 679, 200);
	Action_write(6, 739, 200);				 //3. 5，6回收，准备抬起，防止直接抬起蹭地
	Action();
	delay_ms(800);

	Action_write(5, 478, 200);
	Action_write(6, 500, 200);				 //4.5，6回收预备
	Action();
	delay_ms(800);



	Action_write(5, 226, 350);
	Action_write(6, 178, 400);		//5另一只手上去
	Action();
	delay_ms(800);

	Action_write(1, 247, 300);
	Action_write(2, 480, 500);
	Action_write(3, 465, 250);
	Action_write(4, 212, 380);		//6手下去2
	Action();
	delay_ms(800);

	Action_write(1, 261, 300);
	Action_write(2, 480, 500);
	Action_write(3, 307, 250);
	Action_write(4, 426, 380);			 //7单手支撑预备1，，，second time
	Action();
	delay_ms(800);

	Action_write(1, 248, 300);
	Action_write(2, 480, 500);
	Action_write(3, 465, 250);
	Action_write(4, 212, 380);		//8手下去2，，，second  time
	Action();
	delay_ms(800);

	Action_write(1, 261, 300);
	Action_write(2, 480, 500);
	Action_write(3, 307, 250);
	Action_write(4, 426, 380);			 //9单手支撑预备1，，，finally
	Action();
	delay_ms(800);

	Action_write(5, 478, 300);
	Action_write(6, 739, 400);			 //10.4，5，6回收预备
	Action();
	delay_ms(800);


	Action_write(5, 679, 300);
	Action_write(6, 739, 400);				 //11.3， 5，6回收，准备抬起，防止直接抬起蹭地
											 // 	Action_write(5,741,200);
											 // 	Action_write(6,622,200);//为了矫正
	Action();
	delay_ms(800);


	Action_write(5, 741, 200);
	Action_write(6, 622, 200);//为了矫正。。。成功
	Action();
	delay_ms(500);

	Action_write(1, 301, 100);
	Action_write(2, 462, 500);
	Action_write(3, 305, 200);
	Action_write(4, 478, 400);
	Action_write(5, 731, 200);
	Action_write(6, 576, 400);				 //手夹紧
	Action();
	delay_ms(800);
	delay_ms(200);
	//***********************************************************************************************************
	//pushup
	//***************************************************************************************************************
	Action_write(3, 574, 400);
	Action_write(4, 220, 330);	//减5，为了矫正	
	Action_write(5, 467, 400);
	Action_write(6, 824, 330);
	Action_write(1, 238, 100);				 //俯卧撑，2，下去，，，，，first time
	Action_write(2, 493, 500);

	//腿立正
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);

	Action();
	delay_ms(800);


	Action_write(1, 301, 100);
	Action_write(2, 462, 400);
	Action_write(3, 305, 400);
	Action_write(4, 478, 330);
	Action_write(5, 731, 400);
	Action_write(6, 576, 330);				 //手夹紧
	Action();
	delay_ms(800);
	delay_ms(200);


	Action_write(3, 574, 400);
	Action_write(4, 220, 330);
	Action_write(5, 467, 400);
	Action_write(6, 824, 330);
	Action_write(1, 238, 100);				 //俯卧撑，2，下去，，，，，first time
	Action_write(2, 493, 500);

	//腿立正
	Action_write(7, 495, 300);
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);
	Action_write(10, 506, 300);

	Action();
	delay_ms(800);

	Action_write(1, 301, 100);
	Action_write(2, 462, 400);
	Action_write(3, 305, 400);
	Action_write(4, 478, 330);
	Action_write(5, 731, 400);
	Action_write(6, 576, 330);				 //手夹紧FINALLY 
	Action();
	delay_ms(800);
	delay_ms(200);



	Action_write(3, 410, 300);
	Action_write(4, 452, 300);
	Action_write(5, 633, 300);//立正预备1，双手打开。。。。来自 push up
	Action_write(6, 582, 300);

	Action();
	delay_ms(800);

	Action_write(1, 239, 300);
	Action_write(2, 228, 300);
	Action_write(3, 385, 300);
	Action_write(4, 488, 300);
	Action_write(5, 671, 300);//立正预备，腰收回
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

void left_turn()
{
	Action_write(1, 488, 300);//507
	Action_write(2, 491, 300);//486
	Action_write(3, 618, 300);
	Action_write(4, 690, 300);
	Action_write(5, 482, 300);
	Action_write(6, 337, 300);
	Action_write(7, 548, 400);
	Action_write(8, 865, 300);
	Action_write(9, 173, 300);//yubei
	Action_write(10, 349, 300);
	Action();
	delay_ms(1000);

   
 	Action_write(5,487,300);//538
  	Action_write(6,281,300);//286
	Action_write(7,509,400);
	Action_write(8,859,300);
	Action_write(9,359,300);
	Action_write(10,355,300);//430侧着站
	Action();
	delay_ms(1000);
	delay_ms(200);

	//抱手
	Action_write(3,787,300);
	Action_write(4,909,300);
	Action_write(5,313,300);//350
	Action_write(6,152,300);//130
	Action_write(7,485,450);//翻滚，主要抬腿
	Action_write(8,884,300);
	Action_write(9,715,300);
	Action_write(10,517,300);//496  //479
	Action();
	delay_ms(1000);
	delay_ms(200);
	
 

	Action_write(7,505,700);
	Action_write(8,359,900);
	Action_write(9,690,950);	   //翻滚
	Action_write(10,784,950);
	Action();
	delay_ms(1000);
	delay_ms(300);
	
	Action_write(3, 603, 300);
	Action_write(4, 759, 300);
	Action_write(5, 522, 300);
	Action_write(6, 283, 300);
	Action_write(7, 475, 300);//滚后，侧起单脚单手站立 过渡
	Action_write(8, 491, 150);
	Action_write(9, 245, 300);
	Action_write(10, 510, 300);
	Action();
	delay_ms(1000);
	delay_ms(300);

	Action_write(3, 594, 300);
	Action_write(4, 592, 300);
	Action_write(5, 512, 300);
	Action_write(6, 381, 300);
	Action_write(7, 468, 300);//滚后，侧起单脚单手站立
	Action_write(8, 815, 150);
	Action_write(9, 237, 300);
	Action_write(10, 499, 300);
	Action();
	delay_ms(1000);
	delay_ms(300);


	
	
	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);  
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300);
	Action_write(9, 244, 300);			 //换脚之后，的站立动作
	Action_write(10, 506, 300); 
	Action();
	delay_ms(1000);
	delay_ms(1000);
	

  


}
void right_turn()                                                 //右侧翻	
{
	//预备
	Action_write(1, 491, 300);//507
	Action_write(2, 499, 300);//486
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
	Action_write(7, 459, 300);	 	//492抱手
	Action_write(8, 369, 400);
	Action();
	delay_ms(1000);
	delay_ms(100);

	//翻滚
	Action_write(7, 206, 700);	 	//
	Action_write(8, 399, 700);
	Action_write(9, 703, 750);
	Action_write(10, 496, 750);//482
	Action();
	delay_ms(1000);
	delay_ms(300);

	Action_write(3, 565, 200);
	Action_write(4, 584, 300);
	Action_write(5, 501, 200);
	Action_write(6, 466, 200);
	Action_write(7, 512, 200);
	Action_write(8, 838, 300);
	Action_write(9, 522, 300);	//准备起立
	Action_write(10, 557, 200);//486
	Action();
	delay_ms(1000);

	Action_write(3, 604, 200);
	Action_write(4, 584, 300);
	Action_write(5, 501, 200);
	Action_write(6, 466, 200);
	Action_write(7, 512, 200);
	Action_write(8, 838, 300);
	Action_write(9, 304, 300);	//准备起立
	Action_write(10, 537, 200);//486
	Action();
	delay_ms(1000);
	delay_ms(200);

	Action_write(1, 483, 300);  
	Action_write(2, 496, 300);  
	Action_write(3, 392, 300);  
	Action_write(4, 436, 300);
	Action_write(5, 663, 300); 
	Action_write(6, 632, 300); 
	Action_write(7, 495, 300); 
	Action_write(8, 851, 300); 
	Action_write(9, 244, 300);		 //换脚之后，的站立动作
	Action_write(10, 506, 300); 
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);

}


void stand_on_head()
{
	//倒立并腿


	//倒立劈叉
	/////////////////////////////////////////////////////////////////////



	Action_write(1, 180, 600);
	Action_write(2, 236, 500);
	Action_write(3, 414, 300);
	Action_write(4, 538, 300);
	Action_write(5, 641, 300);//1.预备2，在这里机器趴下
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
	Action_write(1, 657, 300);//648   //704  //715
	Action_write(2, 126, 200);///154   //252
	Action_write(3, 547, 300);
	Action_write(4, 741, 300);
	Action_write(5, 517, 300);
	Action_write(6, 307, 300);
	Action();
	delay_ms(1000);
	delay_ms(1000);



	Action_write(9, 858, 300);
	Action();									//3.抬右腿
	delay_ms(1000);
	delay_ms(800);

	Action_write(7, 750, 800);
	Action_write(1, 468, 300);
	Action_write(2, 193, 300);//4.提腿，上腰//1慢增加稳定性  觉得慢调2
	
	Action();
	delay_ms(1000);



	Action_write(7, 497, 300);
	Action_write(8, 545, 300);
	Action_write(9, 551, 300);//5.大劈叉预备
	Action();
	delay_ms(1000);


	Action_write(2, 488, 400);//497
	Action_write(8, 860, 300);
	Action_write(9, 241, 300);
	Action();									//7.倒立
	delay_ms(800);

	Action_write(3, 795, 300);//823
	Action_write(4, 529, 300);//535
	Action_write(5, 233, 300);//260      //8.倒立后将将身提举起来
	Action_write(6, 502, 300);//497
	Action();
	delay_ms(1000);
	delay_ms(200);

	/////倒立劈叉
	Action_write(7, 179, 300);
	Action_write(8, 536, 300);
	Action_write(9, 551, 300);
	Action_write(10, 816, 300);
	Action();									//10.劈叉
	delay_ms(1000);
	delay_ms(200);
	//delay_ms(1000);

	Action_write(7, 497, 300);
	Action_write(8, 858, 300);
	Action_write(9, 246, 300);
	Action_write(10, 509, 300);//493

	Action();									//11.倒立
	delay_ms(1000);
	delay_ms(200);

	///////////////////////////////////////


	///////////////////////////////////////后滚翻的站立


	Action_write(3, 533, 300);//506
	Action_write(4, 722, 300);//782
	Action_write(5, 495, 300);//9.将手放下去
	Action_write(6, 307, 300);
	Action();
	delay_ms(1200);


	///////////////////////////////////////////////////////////
	Action_write(2, 780, 150);
	// 	Action_write(2,831,150);
	Action();									//8.下腰，腿与腰垂直
	delay_ms(1000);
	delay_ms(800);

	Action_write(1, 320, 75);
	Action();									//9.下脖子，准备站立减7
	delay_ms(1000);
	delay_ms(500);


	Action_write(1, 720, 300);
	Action_write(2, 748, 300);
	Action();									//10.
	delay_ms(650);

	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);//11.翻脖子站立准备
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);

	//这里应该加一个动作1   在650佑?50之间动作太大

	Action_write(1, 741, 300);
	Action_write(2, 744, 300);
	Action_write(3, 309, 300);
	Action_write(4, 576, 300);
	Action_write(5, 714, 300);//12.抬身子，尝试站立
	Action_write(6, 509, 300);
	Action();
	delay_ms(1000);

	Action_write(1, 682, 300);
	Action_write(2, 740, 300);
	Action_write(3, 346, 300);
	Action_write(4, 561, 300);
	Action_write(5, 744, 300);//13.抬身子，尝试站立
	Action_write(6, 483, 300);
	Action();
	delay_ms(300);

	Action_write(1, 501, 300);
	Action_write(2, 491, 400);
	Action_write(3, 360, 300);
	Action_write(4, 497, 300);
	Action_write(5, 683, 300);
	Action_write(6, 550, 300);
	Action_write(7, 495, 300);   //489
	Action_write(8, 851, 300);   //185
	Action_write(9, 244, 300);		//735		 //换脚之后，的站立动作
	Action_write(10, 506, 300);   //565
	Action();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
}

//金鸡独立
void zibian1()
{
	//	/*Action_write(1,540,300);
	//	Action_write(2,530,300);
	//	Action_write(3,577,300);
	//	Action_write(4,545,300);
	//	Action_write(5,521,300);//521
	//	Action_write(6,488,300);
	//	Action_write(7,595,300);//590 586
	// 	Action_write(8,850,200);
	// 	Action_write(9,206,200);				 //自编预备
	//	Action_write(10,516,300);
	//	Action();			
	//	delay_ms(1000);
	//	delay_ms(500);
	//	
	//		Action_write(1,307,100);
	//	Action_write(2,340,200);//320
	//		Action_write(3,546,300);
	//	Action_write(4,602,300);
	//	Action_write(5,537,300);//513
	//	Action_write(6,437,300);//自编预备

	//	Action();
	//	delay_ms(1000);
	//	
	//	
	//	
	//	 	Action_write(9,784,200);				 //自编预备
	//   	Action_write(10,499,300);
	//	Action();
	//	delay_ms(1000);
	//	delay_ms(1000);
	//	delay_ms(1000);
	//	///////////////////////////////////17.5.6新改
	//		Action_write(3,680,300);  //挥手1
	//		Action_write(4,900,300);
	//		Action_write(5,387,300);
	//		Action_write(6,480,300);
	//		Action_write(10,576,300);
	//		Action();
	//		delay_ms(1000);
	//		delay_ms(500);
	//		
	//		Action_write(4,569,300);
	//		Action_write(6,133,300);
	//		Action_write(10,389,300);
	//		Action();
	//		delay_ms(1000);
	//		delay_ms(500);
	//		
	//		Action_write(3,680,300);  //挥手2
	//		Action_write(4,900,300);
	//		Action_write(5,387,300);
	//		Action_write(6,480,300);
	//		Action_write(10,576,300);
	//		Action();
	//		//delay_ms(1000);
	//		delay_ms(500);
	//		
	////Action_write(3,430,300);  //319
	//		Action_write(4,553,300);//536
	//		Action_write(5,631,300);//750
	//		Action_write(6,482,300);	//479
	//			delay_ms(1000);
	//			delay_ms(1000);
	//		delay_ms(500);
	//	
	//		Action_write(9,190,200);				 //换脚之后，的站立动作
	//	Action_write(10,503,200);
	//		Action();
	//	delay_ms(1000);
	//	delay_ms(200);*/
	//	


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



	////////////////////////////////////


	// // 	//////////////////////////////自编1.0	

	//自编2.0
	/////////////////////////////////////

	Action_write(2, 599, 300);
	Action();
	delay_ms(1000);

	Action_write(1, 606, 300);
	Action_write(3, 561, 300);
	Action_write(4, 555, 300);
	Action_write(5, 491, 300);
	Action_write(6, 479, 300);//第一次手平
	Action();
	delay_ms(1000);

	Action_write(1, 703, 100);
	Action_write(2, 693, 50);
	Action_write(3, 418, 300);
	Action_write(4, 844, 500);
	Action_write(5, 406, 300);
	Action_write(6, 727, 500);//第一次手弯曲0
	Action();
	delay_ms(900);
	Action_write(1, 703, 100);
	Action_write(2, 693, 50);
	Action_write(3, 663, 300);
	Action_write(4, 316, 500);
	Action_write(5, 660, 300);
	Action_write(6, 231, 500);//第二次手弯曲1
	Action();
	delay_ms(1000);




	//Action_write(1,780,100);
	//Action_write(2,703,50);


	Action_write(7, 617, 100);
	Action_write(8, 922, 100);

	Action();
	delay_ms(900);
	//Action_write(1,780,100);
	//Action_write(2,703,50);


	Action_write(9, 841, 80);
	Action_write(10, 618, 100);
	Action();			//上腿，抬9
	delay_ms(1000);
	delay_ms(1000);


	///////////////////////////////////////////
	Action_write(3, 561, 300);
	Action_write(4, 555, 300);
	Action_write(5, 491, 300);
	Action_write(6, 479, 300);//第2次调平
	Action();
	delay_ms(1000);




	Action_write(3, 418, 300);
	Action_write(4, 844, 500);
	Action_write(5, 406, 300);
	Action_write(6, 727, 500);//第一次手弯曲0
	Action_write(9, 888, 250);
	Action_write(10, 356, 150);
	Action();
	delay_ms(1000);
	Action_write(3, 663, 300);
	Action_write(4, 316, 500);
	Action_write(5, 660, 300);
	Action_write(6, 231, 500);//第二次手弯曲1
	Action_write(9, 813, 250);
	Action_write(10, 701, 150);
	Action();
	delay_ms(1000);


	/*Action_write(3,418,300);
	Action_write(4,844,500);
	Action_write(5,406,300);
	Action_write(6,727,500);//第一次手弯曲0
	Action_write(9,851,150);
	Action_write(10,420,250);
	Action();
	delay_ms(1000);

	Action_write(3,663,300);
	Action_write(4,316,500);
	Action_write(5,660,300);
	Action_write(6,231,500);//第二次手弯曲1
	Action_write(9,763,150);
	Action_write(10,642,250);
	Action();
	delay_ms(1000);*/



	////////////////////////////////////////////
	Action_write(3, 561, 300);
	Action_write(4, 555, 300);
	Action_write(5, 491, 300);
	Action_write(6, 479, 300);//第3次调平
	Action();
	delay_ms(1000);


	////////////////////////////////////////////
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

	Action_write(1, 483, 200);  
	Action_write(2, 496, 200);  
	Action_write(3, 392, 200);  
	Action_write(4, 436, 200);
	Action_write(5, 663, 200); 
	Action_write(6, 632, 200); 
	Action_write(7, 495, 200); 
	Action_write(8, 851, 200); 
	Action_write(9, 244, 200);		 //换脚之后，的站立动作
	Action_write(10, 506, 200);
	Action();
	delay_ms(1000);
	//delay_ms(800);
}
//摇摆 摇摆
void zibian2()
{
	//过渡 手打平
	//Action_write(1, 479, 300);
	//Action_write(2, 495, 300);
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
	//Action_write(1, 479, 300);
	//Action_write(2, 495, 300);
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
//倒立
void zibian3()
{
	Action_write(1, 180, 600);
	Action_write(2, 236, 500);
	Action_write(3, 414, 300);
	Action_write(4, 538, 300);
	Action_write(5, 641, 300);//1.预备2，在这里机器趴下
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
	Action_write(1, 657, 300);//648   //704  //715
	Action_write(2, 126, 200);///154   //252
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
	//手弯折 手臂着地
	Action_write(1, 495, 200);//648   //704  //715
	Action_write(2, 193, 200);///154   //252
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

	Action_write(2, 488, 400);//497
	Action_write(3, 547, 200);
	Action_write(4, 741, 200);
	Action_write(5, 517, 200);
	Action_write(6, 307, 200);
	Action_write(8, 860, 200);
	Action_write(9, 241, 200);
	Action();									//7.倒立
	delay_ms(1000);


	Action_write(2, 202, 150);
	// 	Action_write(2,831,150);
	Action();									//8.下腰，腿与腰垂直
	delay_ms(1000);
	delay_ms(800);



	Action_write(1, 704, 75);
	Action();									//9.下脖子，准备站立减7
	delay_ms(1000);
	delay_ms(500);

	Action_write(1, 150, 300);
	Action_write(2, 308, 300);
	Action();									//10.抬脖子
	delay_ms(800);

	Action_write(3, 555, 300);
	Action_write(4, 515, 300);
	Action_write(5, 481, 300);//11.翻脖子站立准备
	Action_write(6, 532, 300);
	Action();
	delay_ms(800);


	/////////////////////////////////
	Action_write(1, 257, 300);//151 速度250  237  142  
	Action_write(2, 271, 300);//320 速度250  247  286
	Action_write(3, 339, 300);//352
	Action_write(4, 511, 300);//513
	Action_write(5, 711, 300);//12.抬身子，尝试站立
	Action_write(6, 536, 300);//523
	Action();
	delay_ms(1000);


	Action_write(1, 239, 300);
	Action_write(2, 228, 300);
	Action_write(3, 385, 300);
	Action_write(4, 488, 300);
	Action_write(5, 671, 300);//立正预备，腰收回
	Action_write(6, 540, 300);
	Action();
	delay_ms(300);
	//4.23晚   12.  13.  动作有点不稳
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
void zibian()//
{

	

	///////////////////////////////////自编3.0
	//自编3.0

	Action_write(1, 492, 300);
	Action_write(2, 479, 300);
	Action_write(3, 685, 300);
	Action_write(4, 901, 300);
	Action_write(5, 569, 300);
	Action_write(6, 519, 300);
	Action_write(7, 549, 400);
	Action_write(8, 765, 300);
	Action_write(9, 135, 300);//yubei
	Action_write(10, 402, 300);
	Action();
	delay_ms(1000);

	Action_write(1, 492, 300);
	Action_write(2, 479, 300);
	Action_write(5, 538, 300);
	Action_write(6, 286, 300);
	Action_write(7, 496, 400);
	Action_write(8, 762, 300);
	Action_write(9, 420, 300);
	Action_write(10, 430, 300);//侧着站
	Action();
	delay_ms(1000);
	delay_ms(200);




	Action_write(1, 492, 300);
	Action_write(2, 479, 300);
	Action_write(3, 601, 300);
	Action_write(4, 719, 300);
	Action_write(5, 289, 300);
	Action_write(6, 259, 300);
	Action_write(9, 583, 300);
	Action_write(10, 452, 300);
	Action();
	delay_ms(1000);
	delay_ms(200);

	Action_write(1, 492, 300);
	Action_write(2, 479, 300);
	Action_write(8, 500, 500);	   //翻滚
	Action_write(10, 700, 600);
	Action_write(3, 582, 75);
	Action_write(4, 691, 75);
	Action_write(5, 240, 200);
	Action_write(6, 138, 200);
	Action();
	delay_ms(1000);
	delay_ms(200);

	Action_write(7, 503, 300);
	Action_write(10, 500, 300);
	Action_write(8, 503, 300);
	Action_write(9, 502, 300);
	Action();									//劈叉
	delay_ms(1000);
	delay_ms(200);






	Action_write(2, 488, 300);
	Action_write(7, 501, 300);
	Action_write(8, 789, 300);
	Action_write(9, 183, 300);				 //换脚之后，的站立动作
	Action_write(10, 500, 300);
	Action();									//劈叉
	delay_ms(1000);
	delay_ms(200);

	Action_write(2, 488, 300);
	Action_write(5, 265, 300);//269
	Action_write(6, 130, 300);//137
	Action_write(3, 500, 100);
	Action_write(4, 500, 100);
	Action();									//单臂倒立我弄成
	delay_ms(1000);
	delay_ms(200);

	Action_write(7, 202, 300);
	Action_write(10, 202, 300);
	Action_write(4, 202, 300);
	Action();									//单臂倒立动作0
	delay_ms(1000);
	delay_ms(200);

	Action_write(7, 803, 300);
	Action_write(10, 803, 300);
	Action_write(4, 500, 300);
	Action();									//单臂倒立动作1
	delay_ms(1000);
	delay_ms(200);

	Action_write(7, 202, 300);
	Action_write(10, 202, 300);
	Action_write(4, 202, 300);
	Action();									//单臂倒立动作0
	delay_ms(1000);
	delay_ms(200);

	/*                                                                        
	 	Action_write(7,803,300);
	Action_write(10,803,300);
	Action_write(4,500,300);
	Action();									//单臂倒立动作1
	delay_ms(1000);
	delay_ms(200);*/

	Action_write(7, 500, 300);
	Action_write(10, 500, 300);
	Action_write(3, 582, 75);
	Action_write(4, 691, 75);
	Action();									//单臂倒立动作
	delay_ms(1000);
	delay_ms(200);

	Action_write(1, 492, 300);
	Action_write(2, 479, 300);
	Action_write(3, 601, 300);
	Action_write(4, 719, 300);
	Action_write(5, 289, 100);
	Action_write(6, 259, 100);//huishou
	Action_write(9, 583, 300);
	Action_write(10, 452, 100);
	Action();
	delay_ms(1000);
	delay_ms(200);



	Action_write(3, 653, 200);
	Action_write(4, 824, 300);
	Action_write(5, 379, 200);
	Action_write(6, 245, 200);
	Action_write(8, 420, 300);
	Action_write(9, 558, 300);	//准备起立
	Action_write(10, 486, 200);
	Action();
	delay_ms(400);

	Action_write(2, 488, 300);
	Action_write(3, 619, 200);
	Action_write(4, 738, 300);
	Action_write(5, 493, 200);
	Action_write(6, 298, 200);
	Action_write(7, 510, 300);	//准备起立
	Action_write(8, 778, 350);
	Action_write(9, 516, 250);
	Action_write(10, 533, 250);
	Action();
	delay_ms(1000);
	delay_ms(200);

	Action_write(1, 501, 300);
	Action_write(2, 491, 300);
	Action_write(3, 354, 300);
	Action_write(4, 496, 300);
	Action_write(5, 680, 300);
	Action_write(6, 572, 300);
	Action_write(7, 499, 300);
	Action_write(8, 788, 300);
	Action_write(9, 190, 200);				 //换脚之后，的站立动作
	Action_write(10, 503, 300);
	Action();
	delay_ms(1000);
	delay_ms(500);
	//	delay_ms(1000);

}




