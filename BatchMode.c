#include "major2.h"

void BatchMode(char *file)
{
        // Open FILE
        FILE *filepointer = fopen(file, "r");
        if(filepointer == NULL)
        {
        printf("Error: File could not be opened or found\n");
        MyExit();
        }
  
        // Reserve memory for the line of commands
        char *command_line = (char *)malloc(MAX);
        memset(command_line, '\0', sizeof(command_line));
  
        //Read the line from the pointer and store it into command_line
        while(fgets(command_line, MAX, filepointer))
        {
                command_line[strcspn(command_line, "\n")] = 0;  //Remove any newline
                printf("Processing input: %s\n", command_line);
    
                // Send to parse function
                int comNum = parseCom(command_line);
    
                // Execute each line
                for(int n=0; n < comNum; n++)
                {
                        char *temp = strdup(command[n]);
                        temp = strtok(temp, " ");
                        exeCom(temp, command[n]);
                        free(temp);  // Free temp
                }
        }
        free(command_line); // Free command_line
        fclose(filepointer); // Close FILE
}
