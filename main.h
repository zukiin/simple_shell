#ifndef MAIN_H
#define MAIN_H

/*typedef struct {
	const char *name;
	void (*func)(char **argv);
} Command; */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <limits.h>

extern char **environ;

typedef struct {
	const char *name;
	void (*func)(char **argv);
} Command;

typedef struct path_name{
	char *dir;
	struct path_name *ptr;
} path_name;

char **str_split(char *string, const char *delimiter);
int _atoi(const char *s);
void (*inbuilt(char **argv))(char **argv);
void prompt(char **av, char **env);
int text_prompt();
int _putchar(char c);
int _getline(char *buffer, size_t size);
int pathchk(char *str);
char *filechk(char *str);
path_name *_add_node(path_name **head, char *str);
path_name *path_link(char *path);
void _freelist(path_name *head);
char *find_path(path_name *head, char *filename);
void _isatty();
void ctrl_chk(int sign);
void _EOF(int length, char* str);
int _putchar(char a);
void _puts(char *buff);
void free_argv(char **arg);
void _printenv(char **argv __attribute__ ((unused)));
void _unsetenv(char **argv);
void set_env(char **argv);
char *_getenv(const char *file);
void term_exit(char **argv);
char *con_cat(char *str, char* dim, char* value);
int _strlen(const char *str);
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);
void _exec(char **argv);

#endif
