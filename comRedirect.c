#include "major2.h"

void comRedirect(char *args[], char *first, int arg_count, char *line)
{
  pid_t pid;
  int status;
  
  //if the line has both pipelining and redirection, print error
	if (strchr(line, '|') != NULL && (strchr(line, '<') != NULL || strchr(line, '>') != NULL)) {
	    fprintf(stderr,"Error: contains both pipelining and redirection\n");
	}
  
  // Add pipelining and redirection calls
  
  else
  {
    char *cmd[arg_count+1];
    cmd[0] = first;
    for(int i = 1; i < arg_count; i++)
      cmd[i] = args[i-1];
    cmd[arg_count] = '\0';

    pid = fork();
		if(pid == 0) 
		{	
			cpid = pid;
			
			setpgid(cpid, cpid);
			
			execvp(*cmd, cmd);
			fprintf(stderr,"%s: command not found\n", *cmd);	
			while(1)
			{
				printf("Infinite loop\n");
				sleep(1);
			}
		}
		else 
		{
			tcsetpgrp(0,cpid);
			cpid = tcgetpgrp(0);
			wait(&status);
			tcsetpgrp(0,ppid);
		}
  }
}

}
