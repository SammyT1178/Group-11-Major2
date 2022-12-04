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
		if(pid == 0) {
			execvp(*cmd, cmd);
			fprintf(stderr,"%s: command not found\n", *cmd);
			MyExit();//Ensures child exits after executing command
		}
    /*else if (pid < 0)
    {
     fprintf(stderr, "Fork error\n"); 
    }*/
    else wait(&status);
  }
}
