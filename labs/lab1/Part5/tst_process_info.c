#include<stdio.h>
#include<stdlib.h>
#include<linux/unistd.h>
#include<asm/unistd.h>

struct my_struct
{
	char name[32];
	unsigned pid;
	unsigned prio;
}*process, *var;

int main(void)
{
	int i=0, j=0;
	unsigned count=0;
	long ret=0, retval=0;

	count = syscall(377);
	process =  malloc(count*sizeof(struct my_struct));
	var = malloc(count*sizeof(struct my_struct));
	if(process == NULL || var == NULL)  
		exit(-1);

	retval = syscall(378, &process);
	for(i=0; i<count; i++)
		printf("PROCESS:[%s], PID:[%d], PRIO:[%d]\r\n", (process+i)->name, (process+i)->pid, (process+i)->prio);

	fflush(stdout);
	free(var);
	free(process);
	return 0;
}	
