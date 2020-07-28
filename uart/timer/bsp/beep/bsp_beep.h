#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "imx6ul.h"
/***************************************************************
文件名	: 	 bsp_beep.h
描述	   : BEEP驱动头文件。
其他	   : 无
***************************************************************/

#define LED0	0

/* 函数声明 */
void beep_init(void);
void beep_switch(int status);


#endif