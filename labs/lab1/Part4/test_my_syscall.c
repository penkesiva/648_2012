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
        unsigned long ret=0;
	int flag;

	if(argc != 3)
		printf("Usage: <app> x y\r\n");
	else{
	        ret = syscall(__NR_mycall, atoi(argv[1]), atoi(argv[2]), &flag);
                printf("Sum: %d\r\n", flag);
	}

        return 0;

}

