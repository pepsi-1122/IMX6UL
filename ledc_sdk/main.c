/***************************************************************
文件名 : mian.c
描述 :  C 语言来点亮开发板上的 LED 灯
其他 : 无
**************************************************************/

//#include "main.h"
//#include "imx6ul.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"


/*
* @description : 使能 I.MX6U 所有外设时钟
* @param : 无
* @return : 无
*/

void clk_enable(void)
{
/*   
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
*/
    CCM->CCGR0 = 0xfffffff;
    CCM->CCGR1 = 0xfffffff;
    CCM->CCGR2 = 0xfffffff;
    CCM->CCGR3 = 0xfffffff;
    CCM->CCGR4 = 0xfffffff;
    CCM->CCGR5 = 0xfffffff;
    CCM->CCGR6 = 0xfffffff;

}

/*
* @description : 初始化 LED 对应的 GPIO
* @param : 无
* @return : 无
*/

void led_init(void)
{
    /* 1、初始化 IO 复用, 复用为 GPIO1_IO03 */
//   SW_MUX_GPIO1_IO03 = 0x5;
//   IOMUX_SW_MUX->GPIO1_IO03 = 0X5;
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);

    /* 2、配置 GPIO1_IO03 的 IO 属性*/
//   SW_PAD_GPIO1_IO03 = 0X10B0;
//   IOMUX_SW_PAD->GPIO1_IO03 = 0X10B0;
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0X10B0);

    /* 3、初始化 GPIO, GPIO1_IO03 设置为输出 */
//   GPIO1_GDIR = 0X0000008;
//    GPIO3->GDIR = 0X0000008;
    GPIO1->GDIR |= (1<<3);

    /* 4、设置 GPIO1_IO03 输出低电平 */
//   GPIO1_DR = 0X0;
//    GPIO3->DR = 0X0;
    GPIO1->DR &= ~(1<<3); 
}

/*
* @description : 打开 LED 灯
* @param : 无
* @return : 无
*/
void led_on(void)
{
//   GPIO1_DR &=~(1<<3);
//   GPIO3->DR &= ~(1<<3);
    GPIO1->DR &= ~(1<<3); 
}

/*
* @description : 关闭 LED 灯
* @param : 无
* @return : 无
*/
void led_off(void)
{
//   GPIO1_DR |=(1<<3);
//   GPIO3->DR |= (1<<3);
    GPIO1->DR |= (1<<3);
}

/*
* @description : 短时间延时函数
* @param : 要延时循环次数(空操作循环次数，模式延时)
* @return : 无
*/
void delay_short(volatile unsigned int n)
{
    while(n--){}
}

/*
 * @description : 延时函数,在 396Mhz 的主频下延时时间大约为 1ms
 * @param - n : 要延时的 ms 数
 * @return : 无
 */
 void delay(volatile unsigned int n)
 {
    while(n--)
    {
        delay_short(0x7ff);
    }
 }  

 /*
* @description : main
* @param : 无
* @return : 无
*/
int main(void)
{
    clk_enable();
    led_init();

    while(1)
    {
        led_off();
        delay(500);

        led_on();
        delay(500);
    }
    return 0;
}