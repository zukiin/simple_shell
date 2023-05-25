#include "main.h"

/**
  * execute_cmd - executes a command
  * @av:
  * @env:
  * @buffer:
  */
void execute_command(char **av, char **env, char **buffer)
{
	int i = 0;
	int is_inbuilt = 0;
	char *argv[MAX_COMMAND];

	while (buffer != '\n')
	{
		buffer = str_split(buffer);

		if (_strcmp("exit", buffer[0] == 0)
			break;

		is_inbuilt = handle_inbuilt(buffer[0]);

        {
            buffer[i] = '\0';
        }

        i++;
    }

	int j = 0;
	argv[j] = strtok(buffer, " ");

	while (argv[j] != NULL)
	{
		j++;
		argv[j] = strtok(NULL, " ");
	}

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		free(buffer);
		perror("(fork) Error");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		child_process(av, env, argv);
	}
	else
	{
		parent_process();
	}
}
