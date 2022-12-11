# Group-11-Major2

#### How to run ####

To run on the Cell servers, compile everything in the same directory using the `make` command.
Run the code using the `./major2` line. 

## Group Portion ## 

### driver.c ###

### BatchMode.c ###

### InteractiveMode.c ###

### comRedirect.c ###
//Prajwal Katwal

- checks if the line has both pipelining and redirection, then prints error.
- pipelining and redirection calls are added
- Check if we should redirect stdout and redirect stdin
- Ensures child exits after executing command

### comPiped.c ###
//Prajwal Katwal
- It tterates over args count
- goes for fork process
- then checks if process is not last, if so redirect stdout 
- then it iterates over commands and wait for them to finish
- At the end of the fiel it closes pipe.

### exeCom.c ###

### parseArg.c ###

### parseCom.c ###

## Built-In Commands ##

### CD.c ###
// Samuel Thomas

The CD function is passed the number of arguments and the first argument in that list
- If there are more then 2 arguments, print error and exit function
- If there is only 1 argument, change the directory to the HOME directory
- If the directory does not exits, print error and exit

Note: Bug occurs if the first command passed is a blank cd call. 

## Shell Support Functions ##

### signalHandle.c ###
// Samuel Thomas

Checks if the global child pid and global parent pid are the same.
- If they are, print error and exit
- Else, terminate CPID and set PPID as foreground process


## Finish Explination ##
Link to GitHub project: https://github.com/SammyT1178/Group-11-Major2/
