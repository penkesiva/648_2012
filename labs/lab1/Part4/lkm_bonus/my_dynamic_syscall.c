#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */

void  dummy(void);

void (*mycall_mul)(void);

int module_start(void)
{
	printk(KERN_INFO "Module start\r\n");
	mycall_mul = &dummy;
        return 0;
}

void dummy(void)
{
	printk(KERN_INFO "mycall_mul is called now\r\n");
	/* return and function arguments are still be taken from sys_mycall */
}

void module_end(void)
{
	printk(KERN_INFO "Module EXIT\r\n");
	/* nothing to be done here */
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("18342[Team 10]");
MODULE_VERSION("V0.1");
MODULE_DESCRIPTION("Change mycall system call upon insmod");

