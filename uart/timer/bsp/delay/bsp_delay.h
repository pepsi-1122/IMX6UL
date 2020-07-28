#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H
/***************************************************************
描述	   : 延时头文件。
其他	   : 无
***************************************************************/
#include "imx6ul.h"


/* 函数声明 */
void delay(volatile unsigned int n);
void delay_init(void);
void delayus(unsigned    int usdelay);
void delayms(unsigned	 int msdelay);
void delay(volatile unsigned int n);
void gpt1_irqhandler(void);
#endif