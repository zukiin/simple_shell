#include "main.h"

/**
  * inbuilt - ...
  * @argv: array of args
  * @argv: arr of args
  * Return: 0 on success
  */
void (*inbuilt(char **argv))(char **argv)
{
	int ind, index;
	Command F[] = {
		{"exit", term_exit},
		{"env", _printenv},
		{"setenv", set_env},
		{"unsetenev", _unsetenv},
		{NULL, NULL}
	};

	for (ind = 0; F[ind].name; ind++)
	{
		index = 0;
		if (F[ind].name[index] == argv[0][index])
		{
			for (index = 0; argv[0][index]; index++)
			{
				if (F[ind].name[index] != argv[0][index])
					break;
			}
			if (!argv[0][index])
				return (F[ind].func);
		}

	}
	return (0);
}
