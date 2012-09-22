#include<stdio.h>
#include<linux/unistd.h>
#include<asm/unistd.h>
#include<stdlib.h>
#include<string.h>

struct my_struct
{
	char pid_name[32];
	unsigned pid;
	unsigned prio;
}*process, *var;

int main(void)
{
	int i=0, j=0;
	unsigned count=0;
	long ret=0, retval=0;

	while(1) 
	{
		count = syscall(362);

		process =  malloc(count*sizeof(struct my_struct));
		
		var = malloc(count*sizeof(struct my_struct));

		if(process == NULL || var == NULL)
			exit(-1);

		retval = syscall(363, &process);

		printf("Running task information in decending order:\r\n");

		for(i=0;i<count;i++)
		{
			for(j=i+1;j<count;j++)
			{
				if((process+i)->prio > (process+j)->prio)
				{	/* swap the processes */
					var->prio = (process+j)->prio;
					var->pid = (process+j)->pid;
					strcpy(var->pid_name, (process+j)->pid_name);

					(process+j)->prio = (process+i)->prio;
					(process+j)->pid = (process+i)->pid;
					strcpy((process+j)->pid_name, (process+i)->pid_name);

					(process+i)->prio = var->prio;
					(process+i)->pid = var->pid;
					strcpy((process+i)->pid_name, var->pid_name);

				}
			}
		}

		for(i=0; i<count; i++)
			printf("PROCESS %s, PID:: %d, PRIO:: %d\n", (process+i)->pid_name, (process+i)->pid, (process+i)->prio);
		fflush(stdout);
		free(var);
		free(process);
		sleep(2);
	}	
	return 0;
}	
