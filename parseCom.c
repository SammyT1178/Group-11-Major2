#include "major2.h"

int parseCom(char *str)
{
  	int n = 0;
  	char *token = strtok(str, ";"); // Breaks string into tokens seperated by ';'
  
  	while(token != NULL)
  	{
    		// Remove whitespaces
		while(token[0] == ' ')
    		{
      			int size = strlen(token);
      			for(int i=0; i<size; i++)
      			{
        			token[i] = token[i+1];
      			}
    		}
    		
		// Check if command is empty
    		if(token[0] == '\0')
    		{
     			token = strtok(NULL, ";");
      			continue;
    		}
    		
		// Remove excess whitespaces between arguments
    		for (int i=0; i<strlen(token); i++)
    		{
			if (token[i] == ' ' && token[i+1] == ' ') 
      			{
				int size = strlen(token);
				for (int j=i; j<size; j++)
					token[j] = token[j+1];
				i--;
			}
		}
    		
		// Set current token into command array
    		command[n] = token;
    		n++;
    		token = strtok(NULL, ";");
  	}
  	return n;
}
