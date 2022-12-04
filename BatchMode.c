#include "major2.h"

void BatchMode(char *file)
{
  FILE *filepointer = fopen(file, "r");
  if(filepointer == NULL)
  {
    printf("Error: File could not be opened or found\n");
    MyExit();
  }
  
  char *command_line = (char *)malloc(MAX);
  memset(command_line, '\0', sizeof(command_line));
  
  while(fgets(command_line, MAX, filepointer))
  {
    command_line[strcspn(command_line, "\n")] = 0;
    printf("Processing input: %s\n", command_line);
    
    int comNum = parseCom(command_line);
    
    for(int n=0; n < comNum; n++)
    {
      char *temp = strdup(command[n]);
      temp = strtok(temp, " ");
      exeCom(temp, command[n]);
      free(temp);
    }
  }
  free(command_line);
  fclose(filepointer);
}
