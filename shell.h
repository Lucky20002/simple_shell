#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024

/* Function prototypes */
void prompt(void);
void handleCtrlC(int signal);
void handleEOF(char *buffer);
void exitShell(char **command);
void freeCommandArray(char **command);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *str);

#endif

