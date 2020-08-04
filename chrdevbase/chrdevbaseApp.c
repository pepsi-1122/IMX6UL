#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"
/***************************************************************
文件名		: chrdevbaseApp.c
描述	   	: chrdevbase驱测试APP。
其他	   	: 使用方法：./chrdevbase /dev/chrdevbase <1>|<2>
  			 argv[2] 1:读文件
  			 argv[2] 2:写文件		
***************************************************************/

static char usrdata[] = {"usr data!"};

int main(int argc,char *argv[])
{
    int fd,ret;
    char *filename;
    char readbuf[100],writebuf[100];

    if(argc != 3)
    {
        printf("Error Usage!!\r\n");
        return -1;
    }

    filename = argv[1];

    fd = open(filename,O_RDWR);
    if(fd < 0)
    {
        printf("Cant open file!!\r\n");
        return -1;
    }

    if(atoi(argv[2]) == 1)
    {
        ret = read(fd,readbuf,sizeof(readbuf));
        if(ret < 0)
        {
            printf("Cant read file!!\r\n");
        }
        else
        {
            printf(" read data:%s!!\r\n",readbuf);
        }        
    }
    if(atoi(argv[2]) == 2)
    {
        memcpy(writebuf, usrdata, sizeof(usrdata));
        ret = write(fd,writebuf,50);
        if(ret < 0 )
        {
            printf("Cant write file!!\r\n");
            return -1;
        }
    }

    ret = close(fd);
    if(ret < 0)
    {
        printf("Cant close file!!\r\n");
        return -1;
    }
    return 0;
}