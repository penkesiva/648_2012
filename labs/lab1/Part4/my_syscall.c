#include<linux/linkage.h>
#include<linux/kernel.h>
#include<linux/syscalls.h>

asmlinkage long sys_mycall(size_t i, size_t j, int *result)
{
	printk(KERN_INFO "System Call to Add\r\n");
	result = i+j;
	return 0;
}
