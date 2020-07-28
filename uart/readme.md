Makefile 

在链接的时候加入了数学库， 因为在 bsp_uart.c 中有个函数
uart_setbaudrate，在此函数中使用到了除法运算，因此在链接的时候需要将编译器的数学库也链
接进来

LIBPATH			:= -lgcc -L /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/lib/gcc/arm-linux-gnueabihf/4.9.4

加入了选项“-fno-builtin”，否则编译的时候提示“putc”、“puts”
这两个函数与内建函数冲突

