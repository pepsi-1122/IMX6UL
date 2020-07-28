#include "bsp_beep.h"
/***************************************************************
文件名	: 	 bsp_led.c
描述	   : beep驱动文件。
其他	   : 无
***************************************************************/


void beep_init(void)
{
    /* 1、初始化 IO 复用，复用为 GPIO5_IO01 */
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0);

    /* 2、、配置 GPIO1_IO03 的 IO 属性 */
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0X10B0);

    /* 3、初始化 GPIO,GPIO5_IO01 设置为输出 */
    GPIO5->GDIR |= (1<<1);

    /* 4、设置 GPIO5_IO01 输出高电平，关闭蜂鸣器 */
    GPIO5->DR |= (1<<1);
}

void beep_switch(int status)
{
    if(status == 0)
    {
        GPIO5->DR |= (1<<1);
    }
    else if(status == 1)
    {
        GPIO5->DR &= ~(1<<1);
    }
}