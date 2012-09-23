#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/kthread.h>

struct task_struct *my_task;

void my_func(void);

int module_start(void)
{
	my_task = kthread_run((void*)my_func, NULL, "my_lkm");
	return 0;
}

void my_func(void)
{
	printk(KERN_INFO "Hello World from Process [%d] with priority [%d]\r\n", my_task->pid, my_task->prio);
	return;
}

void module_end(void)
{
	/* Nothing as of now here. Generally used to clean up the module that are allocated in init*/
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("18648[Team 18]");
MODULE_VERSION("V0.1");
MODULE_SUPPORTED_DEVICE("testdevice");
MODULE_DESCRIPTION("Print current Kthreads PID and Prio");
