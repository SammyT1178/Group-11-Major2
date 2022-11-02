//Samuel Thomas - sjt0134
//Minor Assignment 3

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    bool exitKey = false; //Bool to exit while loop

    char user_in[1000]; //User input string

    while(1) //Loop until exit
    {	
		printf("$> ");
        scanf("%[^\n]", user_in);
        getchar();

        if(strcmp(user_in, "quit") == 0) //Check if user wants to exit 
        {
            printf("minor3 shell closed\n");
            exit(0);        
        }
        else
        {
            int index = 0;
            char *args[80];
            char *token;
            
            token = strtok(user_in, " ");

            while (token != NULL) //Fill args array with arguments
            {
                args[index] = token;
                token = strtok(NULL, " ");
                index += 1;
            }
            args[index] = NULL; //Set last input as NULL

            pid_t pid = fork();

            if(pid == 0) //Child
            {
                int status = execvp(args[0],args); //Execute arguments
                if(status < 0) //If error, run error message
                    printf("%s: command not found\n",user_in);
                exit(1);
            }
            else if (pid > 0) //Parent
            {
                wait(0);
            }
            else //Error
            {
                perror("fork error");
            }
        }
    }
    return 0;
}
