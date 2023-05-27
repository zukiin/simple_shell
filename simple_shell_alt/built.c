#include "shell.h"

/**
*env - prints the environnement variables
*@split: command collected
*
*Return: void
*/

void env(char **split __attribute__((unused)))
{
	int a = 0;

	while (environ[a] != NULL)
	{
		_puts(environ[a], STDOUT_FILENO);
		_puts("\n", STDOUT_FILENO);
		a++;
	}
}

/**
* ex_it - exits the shell
* @input_cmd: collected command
*
* Return: nothing
*/

void ex_it(char **input_cmd)
{
	int num = 0, argv;
	
	for (num = 0; input_cmd[num] != NULL; num++);

	if (num == 1)
	{
		free(input_cmd);
		free(term);
		free(cmds);
		exit(status);
	}
	else if (num == 2)
	{
		argv = _atoi(input_cmd[1]);
		if (argv == -1)
		{
			_puts(name, STDERR_FILENO);
			_puts(": 1: exit: Illegal number: ", STDERR_FILENO);
			_puts(input_cmd[1], STDERR_FILENO);
			_puts("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(term);
			free(input_cmd);
			free(cmds);
			exit(argv);
		}
	}
	else
		_puts("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
