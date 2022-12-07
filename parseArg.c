#include "major2.h"

int parseArg(char *line, char *args[])
{
  	int count = 0;
  
  	// Break command into tokens if seperated by " "
  	char *token = strtok(line, " ");
  	token = strtok(NULL, " ");
  
  	while(token != NULL)
  	{
    		// Add to args array
    		args[count] = strdup(token);
   		 count++;
    		token = strtok(NULL, " ");
  	}
  	return count + 1;
}
