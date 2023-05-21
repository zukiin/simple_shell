#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void prompt(char **av, char **env);
int text_prompt();
int _puts(const char *string);
int _putchar(char c);
int _getline(char *buffer, size_t size);
#endif
