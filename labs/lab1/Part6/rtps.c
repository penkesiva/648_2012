#include<stdio.h>
#include<linux/unistd.h>
#include<asm/unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses/ncurses.h>
#include<ncurses/curses.h>

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
	WINDOW * mainwin;

	while(1) 
	{
		count = syscall(377);
		process =  malloc(count*sizeof(struct my_struct));
		var = malloc(count*sizeof(struct my_struct));

		if(process == NULL || var == NULL)
			exit(-1);

		retval = syscall(378, &process);
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

#if 0

		initscr();
		int x, y, ret;
		ret = getmaxyx(stdscr, y, x);
		printf("x:%d, y:%d\r\n", x, y);

#endif
#if 0
		count = 25;
		WINDOW * mainwin;
		/*  Initialize ncurses  */
		if ( (mainwin = initscr()) == NULL ) {
			fprintf(stderr, "Error initialising ncurses.\n");
			exit(EXIT_FAILURE);
		}

		/*  Display "Hello, world!" in the centre of the
		    screen, call refresh() to show our changes, and
		    sleep() for a few seconds to get the full screen effect  */

		mvaddstr(13, 33, "Hello, world!");
		refresh();
		sleep(3);

		/*  Clean up after ourselves  */

		delwin(mainwin);
		endwin();
		refresh();
#endif
		//printf("****y:%d, x:%d\r\n", y, x);
		count = 15;
		for(i=0; i<count; i++){
			printf("PROCESS:%16s\t PID:%4d\t PRIO:%4d\t\n", (process+i)->pid_name, (process+i)->pid, (process+i)->prio);
		}
		fflush(stdout);
		free(var);
		free(process);
		sleep(2);
		printf(" \033[2J"); 
	}	
	return 0;
}	
