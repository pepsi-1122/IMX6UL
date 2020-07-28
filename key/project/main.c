#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
/*
 * @description	: mian函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	int i =0;
	int keyvalue = 0;

	clk_enable();		/* 使能所有的时钟 			*/
	led_init();			/* 初始化led 			*/
	beep_init();
	key_init();

	while(1)			
	{	
		keyvalue = key_getvalue();
		if(keyvalue)
		{
			switch(keyvalue)
			{
				case KEY0_VALUE:
				{
						led_switch(LED0,1);	
				}
			}
		}
	}

	return 0;
}
