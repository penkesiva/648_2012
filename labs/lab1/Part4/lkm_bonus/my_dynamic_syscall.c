#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */

long (*mycall_mul)(size_t i, size_t j, int *result);

int module_start(void)
{

	printk(KERN_INFO "Dynamic module start\r\n");
	mycall_mul = 0xc0092030;
	//mycall_mul();

        return 0;
}

long multiple(size_t i, size_t j, int *result)
{
        printk(KERN_INFO "System Call to Mul\r\n");
        result = i+j;
        return 0;
}


void module_end(void)
{
	printk(KERN_INFO "Dynamic module EXIT\r\n");
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("18648[Team 18]");
MODULE_VERSION("V0.1");
MODULE_DESCRIPTION("Change mycall syscall upon insmod");

