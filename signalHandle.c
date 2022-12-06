#include "major2.h"

void signalHandle(int sig)
{	
	/*if(kill(tcgetpgrp(getpid()), SIGINT) != 0)
		perror("kill error");*/
	
	if(getpgid(cpid) == getpgid(ppid)) //If PPID = PID, don't kill process
	{
		write(1,"error\n",7);
		return;
	}
	else
	{
		kill(cpid, SIGINT); //Kill Child PID
		tcsetpgrp(0,ppid); // Set parent PID to foreground
		kill(ppid, SIGCONT); // Continue Parent
	}
}
