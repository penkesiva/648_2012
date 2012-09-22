/*
 *  Test Char driver written for 18648 lab1
 *  Author: 18648 Team 10
 *  Written: 26th Sept 2011
 *  Version: V0.1
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */

#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/fs.h>
#include <linux/sched.h>

#define OK 		0
#define NOK 		1
#define DEVICE_NAME 	"my_char_dev"	/* Dev name as it appears in /proc/devices */
#define MAJOR_NUM 	123  		/* Hardcoded since we are the only once going to use this driver; a dynamic
					assignment may require udev to create at runtime */
#define MINOR_NUM 	0

static int device_open(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t * offset);
static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t *off);
static int device_release(struct inode *inode, struct file *file);

static struct file_operations fops = {
        .read   = device_read,
        .write  = device_write,
        .open   = device_open,
        .release= device_release
};

struct task_struct *my_task;

int module_start(void)
{
	int ret = -1;

	ret = register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops);
	if(ret < 0){
		printk(KERN_ALERT "Char Device registration failed\r\n");
		return ret;
	}
        return OK;
}

static int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "File opened");	/* Do we have to do anything here */
	return OK;
}

static int device_read(struct file *filp, char *buffer, size_t length, loff_t * offset)
{	
	for_each_process(my_task){
        	printk(KERN_INFO "Hello World from Process [%d] with priority [%d]\r\n", my_task->pid, my_task->prio);
	}
	return OK;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
	printk(KERN_INFO "This operation not supported\r\n");
	return OK;
}

static int device_release(struct inode *inode, struct file *file)
{
	return OK;
}

void module_end(void)
{
	unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("18648[Team 10]");
MODULE_VERSION("V0.1");
MODULE_SUPPORTED_DEVICE("my_char_dev");
MODULE_DESCRIPTION("Print current PID's and priorities of all processes");
                                                
