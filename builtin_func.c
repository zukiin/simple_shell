#include "shell.h"

/**
 *env - prints the current_env
 *@tokenized_cmd: command entered
 *
 *Return: void
 */
void env(char **tokenized_cmd __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * exit_ - goes off the shell
 * @tokenized_cmd: the command entered by user
 *
 * Return: void
 */
void exit_(char **tokenized_cmd)
{
	int number_of_tokens = 0, arg;

	for (; tokenized_cmd[number_of_tokens] != NULL; number_of_tokens++)
		;
	if (number_of_tokens == 1)
	{
		free(tokenized_cmd);
		free(line);
		free(cmds);
		exit(status);
	}

	else if (number_of_tokens == 2)
	{
		arg = _atoi(tokenized_cmd[1]);
		if (arg == -1)
		{
			print(name_of_shell, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_cmd[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}

		else
		{
			free(line);
			free(tokenized_cmd);
			free(cmds);
			exit(arg);
		}
	}
	else
		print("$: cmd cannot take more than one arg \n", STDERR_FILENO);
}
