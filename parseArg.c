#include "major2.h"

int parseArg(char *line, char *args[])
{
  int count = 0;
  
  char *token = strtok(line, " ");
  token = strtok(NULL, " ");
  
  while(token != NULL)
  {
    args[count] = strdup(token);
    count++;
    token = strtok(NULL, " ");
  }
  return count + 1;
}
