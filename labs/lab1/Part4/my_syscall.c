#include<linux/linkage.h>
#include<linux/kernel.h>
#include<linux/syscalls.h>


asmlinkage long sys_mycall(size_t i, size_t j)
{
	printk(KERN_INFO "**My first system call![%u][%u]\n",i,j);

	return i+j;	/* ADD */
	
}

