#include<linux/init.h>
#include<linux/module.h>


MODULE_LICENSE("GPL");

static int hello_init(void)
{
	printk(KERN_ALERT"HELLO World");
	return 0;

}

static void hello_exit(void)
{

	printk(KERN_ALERT"GOODBYE");

}

module_init(hello_init);
module_exit(hello_exit);
