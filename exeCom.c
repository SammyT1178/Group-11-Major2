#include "major2.h"

void exeCom(char *command, char *line)
{
  	char *args[MAX]; // Set arguement array
  
  	char *backup = strdup(line); // Create a backup for the command line
  	
	// Parse command line and free backup
  	int arg_count = parseArg(line, args);
  	strcpy(line, backup);
  	free(backup);
  	
	// If built in instruction called, jump to fuction
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
    
	// Free memory
    	for(int i=0; i<arg_count-1; i++)
    	{
      		if(args[i] != NULL)
      		{
        		free(args[i]);
        		args[i] = NULL;
      		}
    	}
}
