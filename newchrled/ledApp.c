#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"
/***************************************************************
文件名		: ledApp.c
描述	   	: led驱测试APP。
其他	   	: 使用方法：./led /dev/chrdevbase <1>|<2>
  			 argv[2] 1:读文件
  			 argv[2] 2:写文件		
***************************************************************/



#define LEDOFF 	0
#define LEDON 	1

int main(int argc,char *argv[])
{
    int fd,ret;
    char *filename;
    unsigned char data[1];

    if(argc != 3)
    {
        printf("Error Usage!!\r\n");
        return -1;
    }

    filename = argv[1];

    /* 打开led驱动 */
    fd = open(filename,O_RDWR);
    if(fd < 0)
    {
        printf("Cant open file!!\r\n");
        return -1;
    }

    /* 要执行的操作：打开或关闭 */
    data[0] = atoi(argv[2]);

    /* 向/dev/led文件写入数据 */
    ret = write(fd,data,sizeof(data));
    if(ret < 0)
        printf("Cant write file!!\r\n");
    
    
    ret = close(fd);
    if(ret < 0)
    {
        printf("Cant close file!!\r\n");
        return -1;
    }
    return 0;
}