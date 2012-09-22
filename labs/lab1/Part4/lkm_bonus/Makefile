obj-m += my_dynamic_syscall.o
all:	
	make arch=ARM CROSS_COMPILE=/home/vm18648/src/droid/prebuilt/linux-x86/toolchain/arm-eabi-4.4.0/bin/arm-eabi- KERNEL_DIR=~/src/droid/omap -C /home/vm18648/src/droid/omap M=$(shell pwd) modules

clean: 
	make arch=ARM CROSS_COMPILE=/home/vm18648/src/droid/prebuilt/linux-x86/toolchain/arm-eabi-4.4.0/bin/arm-eabi- KERNEL_DIR=~/src/droid/omap -C /home/vm18648/src/droid/omap M=$(PWD) clean

