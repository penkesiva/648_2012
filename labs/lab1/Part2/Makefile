#Makefile for rk kernel modules for i386

KDIR=../../../tegra

AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump

obj-m += my_lkm.o

all:	
	make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- -C $(KDIR) M=$(PWD) modules 

clean:		
	make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- -C $(KDIR) M=$(PWD) clean	
