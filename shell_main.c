#include "main.h"

void prompt_input(char **av, char **env)
{
	ssize_t char_num;
	size_t size = 0;
	char *buffer = NULL;
	int i, j, status;
	char *argv[MAX_COMMAND];
	pid_t child_pid;

	while(1)
	{
		text_prompt();
		char_num = getline(&buffer, &size, stdin);
	}
}
