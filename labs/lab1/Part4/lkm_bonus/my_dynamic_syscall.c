/*	
	This LKM hacks the sys_call_table
	to execute a piece of code that 
	will multiply two integers instead
	of adding the two integers
*/
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/sched.h>
#include<linux/proc_fs.h>
#include<asm/unistd.h>
#include<linux/unistd.h>

void** my_sys_call_table=(void**) 0xc000f644;
void* org_address;

long multiply_integers(int num1, int num2, int* result)
{
        printk(KERN_INFO "Enter dynamic module (perform multiply)\n");
        *result = num1*num2;
        return 0;
}

int module_start(void)
{	
	org_address = my_sys_call_table[376];
	my_sys_call_table[376] = multiply_integers;
	return 0;
}

void module_cleanup(void)
{
	my_sys_call_table[376] = org_address;
        printk(KERN_INFO "Exit dynamic Module\n");
}

module_init(module_start);
module_exit(module_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("18648[Team 18]");
MODULE_VERSION("V0.1");
MODULE_DESCRIPTION("Change mycall syscall upon insmod");
