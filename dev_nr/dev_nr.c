#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#define dev_num 90
MODULE_LICENSE("GPL");

static int openit(struct inode *inode,struct  file *file )
{
	printk("opened ");
	return 0;

}
static int closeit(struct inode *inode , struct file *file)
{

		printk("closing ");
		return 0;
	
}

static struct file_operations fopr = {
	.owner = THIS_MODULE,
	.open = openit,
	.release= closeit
		
	

};
static int __init inmain(void)
{

		int major;
		major = register_chrdev(dev_num, "dev_nr", &fopr);
		if(major== 0)
		{
			printk("dev_nr major: %d, minor %d\n",dev_num, 0);	
		}
		else if (major >0 ){
			printk("dev_nr major: %d, minor %d\n", major>>20, major<<0);
	
		}

		return 0;
}
static void  __exit exmain(void)
{
		unregister_chrdev(dev_num, "dev_nr");
		printk("goodbye! cruel world");
}




module_init(inmain);
module_exit(exmain);
