#include "main.h"

/**
  * handle_cd - handle case for changing directory
  * input: input passed
  */
void interpret_user_input(char **av, char **env)
{
	char *buffer = NULL;

	if (char_num == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
			}
			i++;
		}

}

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
