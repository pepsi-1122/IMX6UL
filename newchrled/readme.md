新字符设备驱动

创建一个字符设备结构

```C++
struct cdev {
	struct kobject kobj;
	struct module *owner;
	const struct file_operations *ops;
	struct list_head list;
	dev_t dev;
	unsigned int count;
};
struct cdev cdev_t;	
```

新的字符设备注册方法

```C++
/* 1、创建设备号 */
if (cdev_t.major) {		/*  定义了设备号 */
		cdev_t.devid = MKDEV(cdev_t.major, 0);
		register_chrdev_region(cdev_t.devid, DTSLED_CNT, DTSLED_NAME);
	} else {						/* 没有定义设备号 */
		alloc_chrdev_region(&cdev_t.devid, 0, DTSLED_CNT, DTSLED_NAME);	/* 申请设备号 */
		cdev_t.major = MAJOR(cdev_t.devid);	/* 获取分配号的
```

```C++
/* 2、初始化cdev */
cdev_t.cdev.owner = THIS_MODULE;
cdev_init(&cdev_t.cdev, &cdev_t_fops);
```

```C++
/* 3、添加一个cdev */
cdev_add(&cdev_t.cdev, cdev_t.devid, DTSLED_CNT);
```

```C++
/* 4、创建类 */
cdev_t.class = class_create(THIS_MODULE, DTSLED_NAME);
if (IS_ERR(cdev_t.class)) {
    return PTR_ERR(cdev_t.class);
}
```

```C++
/* 5、创建设备 */
cdev_t.device = device_create(cdev_t.class, NULL, cdev_t.devid, NULL, DTSLED_NAME);
if (IS_ERR(cdev_t.device)) {
    return PTR_ERR(cdev_t.device);
}
```

注销字符设备驱动

```C++
cdev_del(&cdev_t.cdev);/*  删除cdev */
unregister_chrdev_region(cdev_t.devid, DTSLED_CNT); /* 注销设备号 */

device_destroy(cdev_t.class, cdev_t.devid);
class_destroy(cdev_t.class);
```

