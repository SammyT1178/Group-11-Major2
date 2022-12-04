#include "major2.h"

void CD(char *dir_input, int arg_count)
{
        /*                NOTES
          - If cd is passed for the first time and is without arguments, Segmentation Fault occurs
              - Need to debug before turning in
        */

    if (arg_count > 2) //If the passed value of arg_count is greater than 2, exit
    {
        printf("Too many arguments\n"); //print error
        MyExit();
    }
    else if(arg_count <= 1) //if no arguments are passed, go to the HOME directory
    {
        chdir(getenv("HOME"));
    }
    else if(chdir(dir_input) != 0) //If directory does not exist, print error
        perror("Directory does not exist");
    
}
