#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
*struct map - a struct that maps a command name to a function 
*
*@command_name: name of the command
*@func: the function that executes the command
*/

typedef struct form
{
		char *command_name;
		void (*func)(char **command);
} function_form;

extern char **environ;
extern char *term;
extern char **cmds;
extern char *name;
extern int status;


void wipe_nl(char *);
int _strlen(char *);
void _strcpy(char *, char *);


int prep(char *);
void execute_command(char **, int);
char *path_chk(char *);
void (*get_func(char *))(char **);

char *_getenv(char *title);


int _strcmp(char *s1, char *s2);
char *_strchr(char *a, char c);
int _strcspn(char *str1, char *str2);
int _strspn(char *s1, char *s2);
char *_strcat(char *from, char *to);
void wipe_com(char *s);
void handle_ctrlc(int signum);
void *_realloc(void *ptr, unsigned int old, unsigned int new);
int _atoi(char *s);
 char *_strtok(char *s, char *dem, char **ptr);
char **splitter(char *input_string, char *delim);
void _puts(char *s, int st);
void ex_it(char **input_cmd);
void env(char **split __attribute__((unused)));

extern void non_terminal(void);
extern void prompt(char **current_command, int type_command);

#endif /*SHELL_H*/


