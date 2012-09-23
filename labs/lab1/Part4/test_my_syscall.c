/*
 *  Writing my first System call, for 18648 lab1
 *  Author: 18648 Team 10
 *  Written: 26th Sept 2011
 *  Version: V0.1
 *  
 */

#include <stdio.h>
#include <linux/unistd.h>

#define __NR_mycall 376

int main(int argc, char * argv[])
{
        unsigned long ret = 0;
        unsigned int i;

	if(argc != 2)
		printf("Usage: <app> x y\r\n");
	else{
	        ret = syscall(__NR_mycall, atoi(argv[1]), argv[2], 0, &ret);
                printf("Sum: %d\r\n", i, ret);
	}

        return 0;

}

