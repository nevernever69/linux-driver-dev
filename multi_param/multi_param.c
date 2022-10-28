#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");                //GNU General Public License

int paramarray[3];			//passing param 

module_param_array(paramarray, int , NULL, S_IWUSR| S_IRUSR);	

static int array_init(void)
{
	printk(KERN_ALERT"into the parameter array");   
	printk(KERN_ALERT"array elements are:%d\t%d\t%d\t",paramarray[0], paramarray[1], paramarray[2]);
	return 0;
}


static void array_exit(void)
{
	printk(KERN_ALERT"exiting a paramter multi");


}

module_init(array_init);
module_exit(array_exit);
