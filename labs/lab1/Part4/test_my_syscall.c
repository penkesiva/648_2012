/*
 *  Writing my first System call, for 18648 lab1
 *  Author: 18648 Team 10
 *  Written: 26th Sept 2011
 *  Version: V0.1
 *  
 */

#include <stdio.h>
#include <linux/unistd.h>
//#include <linux/syscalls.h>

#define __NR_mycall 361

int main(int argc, char * argv[])
{
        unsigned long ret = 0;
        unsigned int i;
        for(i=10; i>0; i--)
        {
                ret = syscall(__NR_mycall, 100, i);
                printf("**Sum of [100] and [%u] is [%u]\r\n", i, ret);
        }

        return 0;

}

