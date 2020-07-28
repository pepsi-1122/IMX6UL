#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exit.h"
#include "bsp_keyfilter.h"

/*
 * @description	: mian函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	unsigned char state = 0;

	int_init(); 
	imx6u_clkinit();
	clk_enable();		/* 使能所有的时钟 			*/
	led_init();			/* 初始化led 			*/
	beep_init();
	key_init();
//	exit_init();
	filterkey_init();

	while(1)			
	{	
		state = !state;
 		led_switch(LED0, state);
 		delay(500);
	}

	return 0;
}
