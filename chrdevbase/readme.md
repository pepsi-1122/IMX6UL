字符设备驱动

 字符设备驱动开发步骤

1、 驱动 模块的加载和卸载

```C++
/* 驱动入口函数 */
static int __init xxx_init(void)
{
/* 入口函数具体内容 */
 return 0;
}

 /* 驱动出口函数 */
static void __exit xxx_exit(void)
 {
 /* 出口函数具体内容 */
 }

 /* 将上面两个函数指定为驱动的入口和出口函数 */
 module_init(xxx_init);
 module_exit(xxx_exit);
```

2、创建一个file_operations结构体

```c++
/* 设备操作函数 */
static struct file_operations chr_fops = {
	.owner = THIS_MODULE,
	.open = chrtest_open,
	.read = chrtest_read,
	.write = chrtest_write,
	.release = 	led_release,
};
```



3、设置操作这个结构体

```C++
 /* 打开设备 */
 static int chrtest_open(struct inode *inode, struct file *filp)
 {
	 /* 用户实现具体功能 */
 	return 0;
 }

 /* 从设备读取 */
 static ssize_t chrtest_read(struct file *filp, char __user *buf,size_t cnt, loff_t*offt)
 {
 	/* 用户实现具体功能 */
 	return 0;
 }

 /* 向设备写数据 */
 static ssize_t chrtest_write(struct file *filp,const char __user *buf,size_t cnt, loff_t *offt)
 {
 	/* 用户实现具体功能 */
 	return 0;
 }
/* 关闭/ 释放设备 */
 static int chrtest_release(struct inode *inode, struct file *filp)
 {
	/* 用户实现具体功能 */
 	return 0;
 }
```



