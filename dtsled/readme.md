设备树驱动

1、修改设备树文件

打开 ixxx.dts 文件， 在根节“/”下创建一个名为“alphaled”的子节点

如led驱动

```C++
alphaled {
	#address-cells = <1>;
	#size-cells = <1>;
	compatible = "atkalpha-led";
	status = "okay";
	reg = < 0X020C406C 0X04 /* CCM_CCGR1_BASE */
			0X020E0068 0X04 /* SW_MUX_GPIO1_IO03_BASE */
			0X020E02F4 0X04 /* SW_PAD_GPIO1_IO03_BASE */
			0X0209C000 0X04 /* GPIO1_DR_BASE */
			0X0209C004 0X04 >; /* GPIO1_GDIR_BASE */
 };
/*
*reg 属性中起始地址占用一个字长(cell)，地址长度也占用一个字长(cell)
*属性 compatbile 设置 alphaled 节点兼容性为“atkalpha-led”。
*属性 status 设置状态为“okay”。
*reg 属性设置了led驱动里面所要使用的寄存器物理地址
/
```

设备树修改完成以后输入如下命令重新编译一下。

make dtbs

2、 LED 灯驱动程序编写

2.1 创建dtsled设备结构体

```C++
/* dtsled设备结构体 */
struct dtsled_dev{
	dev_t devid;			/* 设备号 	 */
	struct cdev cdev;		/* cdev 	*/
	struct class *class;		/* 类 		*/
	struct device *device;	/* 设备 	 */
	int major;				/* 主设备号	  */
	int minor;				/* 次设备号   */
	struct device_node	*nd; /* 设备节点 */
};
struct dtsled_dev dtsled;	/* led设备 */
```

2.2 获取设备树中的属性数据

```C++
//获取设备节点：alphaled
dtsled.nd = of_find_node_by_path("/alphaled");
```

```C++
//获取compatible属性内容
proper = of_find_property(dtsled.nd, "compatible", NULL);
```

```C++
//获取status属性内容
ret = of_property_read_string(dtsled.nd, "status", &str);
```

```C++
//获取reg属性内容
ret = of_property_read_u32_array(dtsled.nd, "reg", regdata, 10);
```

2.3将从设备树节点中获取的属性数据初始化硬件

```C++
//初始化LED--寄存器地址映射
IMX6U_CCM_CCGR1 = of_iomap(dtsled.nd, 0);
SW_MUX_GPIO1_IO03 = of_iomap(dtsled.nd, 1);
SW_PAD_GPIO1_IO03 = of_iomap(dtsled.nd, 2);
GPIO1_DR = of_iomap(dtsled.nd, 3);
GPIO1_GDIR = of_iomap(dtsled.nd, 4);
```





