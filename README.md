# Group-11-Major2

#### How to run ####

To run on the Cell servers, compile everything in the same directory using the `make` command.
Run the code using the `./major2` line. 

## Group Portion ## 

### driver.c ###

### BatchMode.c ###

### InteractiveMode.c ###

### comRedirect.c ###

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
