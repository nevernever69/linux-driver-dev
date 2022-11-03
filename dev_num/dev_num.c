#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>

MODULE_LICENSE("GPL");     			//PUBLIC LICENSE
static  dev_t first;

int __init kern_start(void)			//INIT FUNCTION 
{


	if(alloc_chrdev_region(&first, 0, 3, "Name") < 0 ){
		return -1;
	}
	printk(KERN_INFO "<major,minor>: <%d, %d\n>",MAJOR(first), MINOR(first));     //print major and minor number
	return 0;



}

void __exit kern_end(void)
{
	unregister_chrdev_region(first, 3);		//unregister	 
	printk(KERN_ALERT"GOODBYE!!");
	

}



module_init(kern_start);
module_exit(kern_end);
