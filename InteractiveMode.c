#include "major2.h"

void InteractiveMode()
{
 int status = 0;
  
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
      
    
    if (str[strlen(str)-1] == '\n') 
    {
      str[strlen(str)-1] = '\0';    
    }
    
    int numCmd = parseCom(str);
    
    formatIfExit(command, numCmd);
    
    for(int i=0; i < numCmd; i++){
			char *temp = strdup(command[i]);
			temp = strtok(temp, " ");
			exeCom(temp, command[i]);
			//free temp
			free(temp);
		}
    
    free(str);
    
  }
}

// Format a commands array in a way that exit is executed last
void formatIfExit(char* commands[], int count) {
  // Check if more than one command is getting executed
  if(count > 1) {
    // Check if the first command is exit, and if so make it execute last
    if(strcmp(commands[0], "exit") == 0)
    {
      char* temp = commands[0];
      commands[0] = commands[count-1];
      commands[count-1] = temp;
    }
  }
}
