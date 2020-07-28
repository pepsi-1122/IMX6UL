#ifndef _BSP_KEYFILTER_H
#define _BSP_KEYFILTER_H
/***************************************************************
文件名	: 	 bsp_keyfilter.c
描述	   : 定时器按键消抖驱动头文件。
其他	   : 无
***************************************************************/


/* 函数声明 */
void filterkey_init(void);
void filtertimer_init(unsigned int value);
void filtertimer_stop(void);
void filtertimer_restart(unsigned int value);
void filtertimer_irqhandler(void);
void gpio1_16_31_irqhandler(void);

#endif
