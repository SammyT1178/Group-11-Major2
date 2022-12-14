#include "major2.h"

int main(int argc, char *argv[])
{
  	if(!(argc < 3)) // if too many parameters
  	{
  	  printf("Error: Too many parameters\n"); //Error message
  	  exit(0);  // Exit program
  	}
  
  	ppid = getpid(); //Set parent pid
  
  	//Signal Handles
  	signal(SIGINT, signalHandle);
  	signal(SIGTSTP, signalHandle);
  
  	if(argc == 1) 	// If no file, jump to Interactive Mode
  	  InteractiveMode();
  	else		// If files, jump to Batch Mode
  	  BatchMode(argv[1]);
  
  	return 0;
}
