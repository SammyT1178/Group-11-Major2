#include "major2.h"

int parseCom(char *str)
{
  int n = 0;
  char *token = strtok(str, ";");
  
  while(token != NULL)
  {
    while(token[0] == ' ')
    {
      int size = strlen(token);
      for(int i=0; i<size; i++)
      {
        token[i] = token[i+1];
      }
    }
    
    if(token[0] == '\0')
    {
     token = strtok(NULL, ";");
      continue;
    }
    
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
    
    command[n] = token;
    n++;
    token = strtok(NULL, ";");
  }
  return n;
}
