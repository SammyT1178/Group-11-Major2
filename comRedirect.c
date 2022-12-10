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
    char *redirectionFile;
    char redirect = 0;
    cmd[0] = first;
    for(int i = 1; i < arg_count; i++)
    {
      char arg = args[i-1][0];
      if(arg == '|') {
        comPiped(args, first, arg_count);
        return;
      }
      else if(arg == '>' || arg == '<')
      {
        redirect = arg;
        redirectionFile = args[i];
        cmd[i] = '\0';
        break;
      }
      cmd[i] = args[i-1];
    }
    cmd[arg_count] = '\0';

    pid = fork();
		if(pid == 0) {
      int fd = 0;
      // Check if we should redirect stdout
      if(redirect == '>') {
        // Open file for redireciton
        fd = open(redirectionFile, O_CREAT | O_WRONLY | O_TRUNC);
        // Redirect stdout to write to file
        dup2(fd, STDOUT_FILENO);
      }
      // Check if we should redirect stdin
      else if(redirect == '<') {
        // OPen file for redirection
        fd = open(redirectionFile, O_RDONLY);
        // Redirect stdin to read from file
        dup2(fd, STDIN_FILENO);
      }
			execvp(*cmd, cmd);
      // If there as an open file, close it
      if(fd) {
        close(fd);
      }
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
