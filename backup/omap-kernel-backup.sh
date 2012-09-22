#!/bin/sh
# Linux/RK code backup script for 2.6.38.8
mkdir Backup-`date +%b-%d-%Y`
cd Backup-`date +%b-%d-%Y`

# Make directories
mkdir arch
cd arch
mkdir arm
cd arm
mkdir kernel
mkdir include
cd include
mkdir asm

cd ../../../

mkdir include
cd include
mkdir linux

cd ../

cp ../../arch/arm/include/asm/unistd.h arch/arm/include/asm/.
cp ../../arch/arm/kernel/calls.S arch/arm/kernel/.
cp ../../include/linux/syscalls.h include/linux/.


