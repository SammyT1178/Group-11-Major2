#include "major2.h"


void comPiped(char *args[], char *first, int arg_count) {
  char* cmds[3][arg_count-1];
  cmds[0][0] = first;
  int pipes[2][2];
  int curCmd = 0;
  int curArgs = 1;

  // Iterate over args count
  for(int i = 0; i < arg_count-1; i++) {
    char arg = args[i][0];
    // If arg is pipe icrement commands counter
    if (arg == '|')
    {
      pipe(pipes[curCmd]);
      curCmd++;
      curArgs = 0;
      continue;
    }
    // Set current command args
    cmds[curCmd][curArgs] = args[i];
    curArgs++;
  }
  // Iterate over commands
  for(int i = 0; i <= curCmd; i++)
  {
    // Fork process
    int pid = fork();
		if(pid == 0) {
      // Check if process is not last, if so redirect stdout 
      if(i != curCmd)
        dup2(pipes[i][1], STDOUT_FILENO);
      // Check if process is not first, is so redirect stdin
      if (i != 0)
        dup2(pipes[i-1][0], STDIN_FILENO);
 
			execvp(*cmds[i], cmds[i]);

			fprintf(stderr,"%s: command not found\n", *cmds[i]);
			MyExit();
		}
  }
  // Iterate over commands and wait for them to finish
  for(int i = 0; i < curCmd; i++)
  {
    int status;
    wait(&status);
    // Close pipe
    close(pipes[i][0]);
    close(pipes[i][1]);
  }
}
