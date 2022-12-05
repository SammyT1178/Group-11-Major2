#include "major2.h"

void signalHandle(int sig)
{
printf("\nWe are inside the sig function\n");
	
	/*if(kill(tcgetpgrp(getpid()), SIGINT) != 0)
		perror("kill error");*/
	
	printf("\t\tChild PGID: %d\n", getpgid(cpid));
	printf("\t\tParent PGID: %d\n", getpgid(ppid));
	
	if(getpgid(cpid) == getpgid(ppid))
	{
		write(1,"error\n",7);
		return;
	}
	else
	{
		kill(cpid, SIGINT);
		tcsetpgrp(0,ppid);
		kill(ppid, SIGCONT);
		printf("Parent should be working now\n");
	}
}
