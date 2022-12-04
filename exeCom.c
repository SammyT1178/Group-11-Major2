#include "major2.h"

void exeCom(char *command, char *line)
{
  char *args[MAX];
  
  char *backup = strdup(line);
  
  int arg_count = parseArg(line, args);
  strcpy(line, backup);
  free(backup);
  
  if(strcmp(command, "cd") == 0)
    CD(args[0], arg_count);
  else if(strcmp(command, "exit") == 0)
  {
    //Exit Command
  }
  else if(strcmp(command, "path") == 0)
	{
    //Path Command
  }
  else if(strcmp(command, "myhistory") == 0)
	{
    //History Command
  }
  else if(strcmp(command, "alias") == 0)
	{
    //Alias Command
  }
  else comRedirect(args, command, arg_count, line);
    
    for(int i=0; i<arg_count-1; i++)
    {
      if(args[i] != NULL)
      {
        free(args[i]);
        args[i] = NULL;
      }
    }
}
