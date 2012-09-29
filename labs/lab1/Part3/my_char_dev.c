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
#include <linux/types.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/slab_def.h>
#include <linux/errno.h>
#define OK 	0
#define NOK 	1
#define DEVICE_NAME 	"my_char_dev"	/* Dev name as it appears in /proc/devices */
#define MAJOR_NUM 	123  		/* Hardcoded since we are the only once going to use this driver; a dynamic
					assignment may require udev to create at runtime */
#define MINOR_NUM 	0

static int device_open(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t * offset);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);
static int device_release(struct inode *inode, struct file *file);

static struct file_operations fops = {
        .read   = device_read,
        .write  = device_write,
        .open   = device_open,
        .release= device_release
};

struct task_struct *my_task;
char *read_buf = NULL;
int flag = 0;
int flag1=0;
char *curr_ptr = NULL;
int len = 0;
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
	read_buf = kmalloc((size_t)(8192),GFP_ATOMIC);
	if(read_buf ==NULL)
		return -ENOMEM;
	flag = 0;
	flag1 = 0;
	len = 0;
	return OK;
}

static int device_read(struct file *filp, char *buffer, size_t length, loff_t * offset)
{	
	char *str = NULL; 
	if(flag == 0)
	{
		str = kmalloc((size_t)(128),GFP_ATOMIC);
		if(str ==NULL)
			return -ENOMEM;
		strcpy(read_buf,"");
		for_each_process(my_task){
	        	sprintf(str,"Hello World from Process [%d] with priority [%d]\r\n", my_task->pid, my_task->prio);
			strcat(read_buf,str);
		}
		flag =1;
		printk(KERN_INFO "%d",strlen(read_buf));
		curr_ptr = read_buf;
		kfree(str);
	}
	if((flag == 1) && (flag1==0)) 
	{
		printk(KERN_INFO "flag1 %d",flag1);
		if((len+length) < strlen(read_buf))
		{
			
			memcpy(buffer,curr_ptr,length);			
			curr_ptr = curr_ptr + length+1;
			len = len + length;
			printk(KERN_INFO "%d",len);
			return length;
		}
		else 
		{
			length = (read_buf + strlen(read_buf)) - curr_ptr;
			memcpy(buffer,curr_ptr,length+1);
			curr_ptr = curr_ptr + length+1;	
			len = len + length;
			flag1 = 1;
			return length;
			
		}
		
	}
	
	kfree(read_buf);
	return OK;
	
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
	printk(KERN_INFO "This operation not supported\r\n");
	return OK;
}

static int device_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "This device is released\r\n");
	flag = 0;
	flag1 = 0;
	len = 0;
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
                                                
