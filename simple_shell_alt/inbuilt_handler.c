#include "main.h"

void env(char **command __attribute__((unused)))
{
	int a = 0;

	while (environ[a] != NULL)
	{
		_puts(environ[a], STDOUT_FILENO);
		_puts("\n", STDOUT_FILENO);
		a++;
	}
}

void ex_it(char **input)
{
	int argv, token = 0;

	while (input[token] != NULL)
	{
		token++;
	}
	if (token == 1)
	{
		free(input);
		free(term);
		free(cmd);
		exit(status);
	}
	else if (token == 2)
	{
		argv = _atoi(input[1]);
		if (argv == -1)
		{
			_puts(name, STDERR_FILENO);
			_puts(": 1: exit: Illegal number: ", STDERR_FILENO);
			_puts(input[1], STDERR_FILENO);
			_puts("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(cmd);
			free(input);
			free(term);
			exit(argv);
		}
	}
	else
	{
		_puts("$: exit doesn't take more than one argument\n", STDERR_FILENO);
	}
}
