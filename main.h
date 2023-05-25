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

#define min(a, b) (((a) < (b)) ? (a) : (b))

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

extern char *term;
extern char **cmd;
extern char *name;
extern int status;
extern char **environ;

typedef struct {
	char *name;
	void (*func)(char **argv);
} Command;

void *_realloc(void *p, size_t old, size_t new);
void handle_ctrlc(int signum);
void env(char **command __attribute__((unused)));
void ex_it(char **input);
char *_strtok(char *str, char *dem, char **ptr);
int _atoi(char *s);
void _strcpy(char *from, char *to);
int _strlen(char *str);
void wipe_nl(char *string);
 void _puts(char *str, int stream);
int _strcmp(char *s1, char *s2);
char *_strcat(char *to, char *from);
int _strcspn(char *s, char *p);
int _strspn(char *s, char *p);
char *_strchr(char *str, char c);
void prompt(char **input_str, int input);
char **splitter(char *str, char *dem);
void _puts(char *str, int stream);
void handle_com(char *com);
void from_term(void);
void (*get_func(char *cmd))(char **);
char *_getenv(char *name);
int parse_cmd(char *input);
char *path_chk(char *input);
void _exec(char **input_str, int input);
int parse_cmd(char *input);


#endif 
