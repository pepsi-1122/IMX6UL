#include "bsp_exit.h"
#include "bsp_gpio.h"
#include "bsp_int.h"
#include "bsp_delay.h"
#include "bsp_beep.h"

/*
 * @description : 初始化外部中断
 * @param : 无
 * @return : 无
 */
void exit_init(void)
{
    gpio_pin_config_t key_config;

    /* 1、设置 IO 复用 */
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18,0xf0b0);

    /* 2、初始化 GPIO 为中断模式 */
    key_config.direction = kGPIO_DigitalInput;
    key_config.interruptMode = kGPIO_IntFallingEdge;
    key_config.outputLogic = 1;

    gpio_init(GPIO1,18,&key_config);

    /* 3、使能 GIC 中断、注册中断服务函数、使能 GPIO 中断 */
    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);
    system_register_irqhandler(GPIO1_Combined_16_31_IRQn,
                                    (system_irq_handler_t)gpio_io18_irqhandler,NULL);

    gpio_enableint(GPIO1,18);                                
}

/*
 * @description : GPIO1_IO18 最终的中断处理函数
 * @param : 无
 * @return : 无
 */
void gpio_io18_irqhandler(void)
{
    static unsigned char state = 0;

    delay(10);
    if(gpio_pinread(GPIO1,18) == 0) /* 按键按下了 */
    {
        state = !state;
          beep_switch(state);
    }

    gpio_clearintflags(GPIO1,18);   /* 清除中断标志位 */
    

}