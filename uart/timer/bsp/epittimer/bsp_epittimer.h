#ifndef _BSP_EPITTIMER_H
#define _BSP_EPITTIMER_H
/***************************************************************
文件名	: 	 bsp_epittimer.h
描述	   : EPIT定时器驱动头文件。
其他	   : 无
***************************************************************/
#include "imx6ul.h"


/* 函数声明 */
void epit1_init(unsigned int frac, unsigned int value);
void epit1_irqhandler(void);

#endif
