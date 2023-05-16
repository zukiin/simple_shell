#include "main.h"

#define MAX_COMMAND 10

void prompt(char **av, char **env)
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
		
		j = 0;
		argv[j] = strtok(buffer, " ");

		while (argv[j] != NULL)
		{
			j++;
			argv[j] = strtok(NULL, " ");
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				printf("%s: No such file or directory\n", av[0]);
			}

		}

		else
			wait(&status);
		}
}
