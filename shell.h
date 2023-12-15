#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/* const */
#define INVALID_CMD -1
#define EXT_CMD 1
#define INT_CMD 2
#define PATH_CMD 3

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct mappings - struct for mapping cmd to a func
 *
 *@cmd_name: command name
 *@func: func to execute the cmd
 */

typedef struct mappings
{
	char *cmd_name;
	void (*func)(char **cmd_);
} func_mapper;

extern char **environ;
extern char *line;
extern char **cmds;
extern char *name_of_shell;
extern int status;

/* helperfuncs */
int _strlength(char *);
void _strcopy(char *, char *);
void print(char *, int);
char **tokenize(char *, char *);
void rm_newline(char *);

/* 2 */
char *_strconcat(char *, char *);
int _strspn(char *, char *);
char *_strchr(char *, char);
int _strcspn(char *, char *);
int _strcomp(char *, char *);

/* 3 */
char *_strtoken_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new);
void control_c_handler(int);
void rm_comment(char *);

/* utils */
int parse_cmd(char *);
void exec_cmd(char **, int);
char *path_checker(char *);
void (*get_funct(char *))(char **);
char *_get_env(char *);

/* built_in funcs*/
void env(char **);
void exit_(char **);

/* main funcs*/
extern void not_interactive(void);
extern void initialize_(char **current_cmd, int cmd_type);

#endif /*SHELL_H*/
