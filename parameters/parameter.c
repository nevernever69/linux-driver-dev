#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
MODULE_LICENSE("GPL");

int paramtest;
module_param(paramtest, int , S_IRUSR|S_IWUSR);
static int param_init(void)
{
	printk(KERN_ALERT"showing the ");
	printk(KERN_ALERT"value of %d", paramtest);
	return 0;
}

static void param_exit(void)
{
	printk(KERN_ALERT"exiting");
}
module_init(param_init);
module_exit(param_exit);
