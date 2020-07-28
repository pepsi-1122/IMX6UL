#include "bsp_gpio.h"


/*
* @description : GPIO 初始化。
* @param - base : 要初始化的 GPIO 组。
* @param - pin : 要初始化 GPIO 在组内的编号。
* @param - config : GPIO 配置结构体。
* @return : 无
 */
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    base->IMR &= ~(1U << pin);

    if(config->direction == kGPIO_DigitalInput)
    {
        base->GDIR &= ~(1<<pin);
    }
    else
    {
        base->GDIR |= (1<<pin);
        gpio_pinwrite(base,pin,config->outputLogic);
    }
    gpio_intconfig(base, pin, config->interruptMode);/* 中断功能配置 */
}

/*
* @description : 读取指定 GPIO 的电平值 。
* @param – base : 要读取的 GPIO 组。
* @param - pin : 要读取的 GPIO 脚号。
* @return : 无
*/
int gpio_pinread(GPIO_Type *base,int pin)
{
    return ((base->DR)>>pin) & (0x1) ;
}


/*
* @description : 指定 GPIO 输出高或者低电平 。
* @param – base : 要输出的的 GPIO 组。
* @param - pin : 要输出的 GPIO 脚号。
* @param – value : 要输出的电平，1 输出高电平， 0 输出低低电平
* @return : 无
*/
void gpio_pinwrite(GPIO_Type *base,int pin,int value)
{
    if(value == 0U)
    {
        base->DR &= ~(1U<<pin);
    }
    else
    {
        base->DR |= (1U<<pin);
    }
    
}


/*
 * @description : 设置 GPIO 的中断配置功能
 * @param - base : 要配置的 IO 所在的 GPIO 组。
 * @param - pin : 要配置的 GPIO 脚号。
 * @param – pinInterruptMode: 中断模式，参考 gpio_interrupt_mode_t
 * @return : 无
 */

void gpio_intconfig(GPIO_Type *base,unsigned int pin,
                        gpio_interrupt_mode_t pinInterruptMode)
{
    volatile uint32_t *icr;
    uint32_t icrShift;

    icrShift = pin;
    base->EDGE_SEL &= ~(1<<pin);

    if(pin < 16)
    {
        icr = &(base->ICR1);
    }
    else
    {
         icr = &(base->ICR2);
         icrShift -= 16; 
    }

    switch(pinInterruptMode)
    {
        case(kGPIO_IntLowLevel):
            *icr &= ~(3U<<(2*icrShift));
            break;
        
        case(kGPIO_IntHighLevel):
            *icr = (*icr &(~(3U<<(2*icrShift)))) | (1U << (2*icrShift));
            break;

        case(kGPIO_IntRisingEdge):
            *icr = (*icr & (~(3U << (2 * icrShift)))) |
                        (2U << (2 * icrShift));
            break;

        case(kGPIO_IntFallingEdge):
            *icr |= (3U << (2 * icrShift));
            break;

        case(kGPIO_IntRisingOrFallingEdge):
             base->EDGE_SEL |= (1U << pin);
             break;
        default:
            break;
    }    
}

/*
 * @description : 使能 GPIO 的中断功能
 * @param - base : 要使能的 IO 所在的 GPIO 组。
 * @param - pin : 要使能的 GPIO 在组内的编号。
 * @return : 无
 */
void gpio_enableint(GPIO_Type *base,unsigned int pin)
{
    base->IMR |= (1 << pin);
}

/*
 * @description : 禁止 GPIO 的中断功能
 * @param - base : 要禁止的 IO 所在的 GPIO 组。
 * @param - pin : 要禁止的 GPIO 在组内的编号。
 * @return : 无
 */
void gpio_disableint(GPIO_Type *base,unsigned int pin)
{
    base->IMR &= ~(1 << pin);
}

/*
 * @description : 清除中断标志位(写 1 清除)
 * @param - base : 要清除的 IO 所在的 GPIO 组。
 * @param - pin : 要清除的 GPIO 掩码。
 * @return : 无
 */
void gpio_clearintflags(GPIO_Type *base,unsigned int pin)
{
    base->ISR |= (1 << pin);
}
