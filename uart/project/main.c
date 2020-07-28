#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exit.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"
#include "stdio.h"


/*
 * @description	: mian函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	unsigned char state = 0;
	int a , b;

	int_init(); 
	imx6u_clkinit();
	clk_enable();		/* 使能所有的时钟 			*/
	delay_init();		/* 初始化延时 			*/
	led_init();			/* 初始化led 			*/
	beep_init();
	key_init();
	uart_init();

	while(1)					
	{	
		printf("输入两个整数，使用空格隔开:");
		scanf("%d %d", &a, &b);					 		/* 输入两个整数 */
		printf("\r\n数据%d + %d = %d\r\n\r\n", a, b, a+b);	/* 输出两个数相加的和 */

		state = !state;
		led_switch(LED0,state);
	}


	return 0;
}
