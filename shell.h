#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environ variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker(char **cmd, char *buff);
void prompt_user(void);
void handle_signal(int m);
char **token(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

void print_environ(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);

struct builtin
{
	char *environ;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;


#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*================ Shell_Init =================*/

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);

/*================ create_child =================*/

void create_child(char **command, char *name, char **env, int cicles);
int change_dir(const char *path);

/*================ Execute =================*/

void execute(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cicles, char **command);

/*================ Tokening =================*/

char **tokening(char *buffer, const char *s);

/*================ Free Memory =================*/

void free_dp(char **command);
void free_exit(char **command);

/*================ Auxiliar_Functions =================*/

int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

#endif

