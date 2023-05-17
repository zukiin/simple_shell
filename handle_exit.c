#include "main.h"

/**
  * exit_shell - exits the shell
  * input: input passed
  */
void exit_shell(char **token)
{
	if(strcmp(token[0], "exit") == 0)
	{
		exit(0);
	}
}
