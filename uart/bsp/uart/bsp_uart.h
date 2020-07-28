#ifndef __BSP_UART_
#define __BSP_UART_

#include "imx6ul.h"


void uart_init(void);
void uart_io_init(void);
void uart_disable(UART_Type *base);

void uart_enable(UART_Type *base);
void uart_softreset(UART_Type *base);
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz);

void putc(unsigned char c);
void puts(char *str);
unsigned char getc(void);
void raise(int sig_nr);



#endif