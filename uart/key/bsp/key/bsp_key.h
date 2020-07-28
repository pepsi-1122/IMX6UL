#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "imx6ul.h"
/***************************************************************
文件名	: 	 bsp_key.h
描述	   : key驱动头文件。
其他	   : 无
***************************************************************/

/* 定义按键值 */
enum keyvalue
{
    KEY_NONE = 0,
    KEY0_VALUE,
};


void key_init(void);
int key_getvalue(void);

#endif