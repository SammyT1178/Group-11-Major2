#include "major2.h"

void comRedirect(char *args[], char *first, int arg_count, char *line)
{
  	pid_t pid;
  	int status;
  
  	//if the line has both pipelining and redirection, print error
	if (strchr(line, '|') != NULL && (strchr(line, '<') != NULL || strchr(line, '>') != NULL)) 
	{
		fprintf(stderr,"Error: contains both pipelining and redirection\n");
	}
  
  	// Add pipelining and redirection calls
  	else
  	{
		// Move the current command up
    		char *cmd[arg_count+1];
    		cmd[0] = first;
    		for(int i = 1; i < arg_count; i++)
      		cmd[i] = args[i-1];
    		cmd[arg_count] = '\0';

   		pid = fork();
		if(pid == 0) 
		{	
			cpid = pid;
			
			setpgid(cpid, cpid); // Set Child PGID to value CPID
			
			// Execute command
			execvp(*cmd, cmd);
			fprintf(stderr,"%s: command not found\n", *cmd);	
		}
		else 
		{
			tcsetpgrp(0,cpid); // Set Child process to foreground
			cpid = tcgetpgrp(0); // Set Child pid to foreground PGRP
			wait(&status);
			tcsetpgrp(0,ppid);  // Once child complete, set parent to foreground
		}
	}

}
