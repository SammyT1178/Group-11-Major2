#ifndef MAJOR2_H
#define MAJOR2_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

pid_t ppid; //Parent PID
pid_t cpid; //Child PID

#define MAX 512  //Set user input to max at 512 bytes

void InteractiveMode();
void BatchMode(char *file);
int parseCom(char *userIn);
int parseArg(char *line, char *args[]);
void exeCom(char *com, char *line);
void comRedirect(char *args[], char *first_command, int arg_count, char *full_line);
void comPiped(char* args[], char *first, int arg_count);
void formatIfExit(char* commands[], int count);

// Built-In Commands
void CD(char *input, int arg_num);
void MyExit();

// Shell Support
void signalHandle(int sig);

char *prompt;
char *command[MAX];

#endif
