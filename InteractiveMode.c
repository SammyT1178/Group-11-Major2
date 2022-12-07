#include "major2.h"

void InteractiveMode()
{
 	int status = 0;
  
 	 // Prepare prompt in memory, set prompt value from user
 	 prompt = (char*)malloc(MAX);
 	 printf("Enter prompt: ");
 	 fgets(prompt, MAX, stdin);
  
 	 //remove newline from prompt
 	 if (prompt[strlen(prompt)-1] == '\n') 
 	 {
 	     prompt[strlen(prompt)-1] = '\0'; 
 	 }
  
 	 while(1)
 	 {
  		char *str = (char*)malloc(MAX);
 		printf("%s> ", prompt);
    		fgets(str, MAX, stdin);
    	
    		if(strlen(str) == 1)
    		{
    		  continue;
    		}
      
    		// Remove newline
    		if (str[strlen(str)-1] == '\n') 
    		{
    		  str[strlen(str)-1] = '\0';    
    		}
    
    		// parse commands
    		int numCmd = parseCom(str);
    		for(int i=0; i < numCmd; i++)
		{
			char *temp = strdup(command[i]);
			temp = strtok(temp, " ");
			exeCom(temp, command[i]);
				
			//free temp
			free(temp);
		}
    		
		// Free str
		free(str);
    	
  	}	
}	
