#include "main.h"

void (*get_func(char *cmd))(char **)
{
	int a = 0;

Command map[] = {
	{"env", env},
	{"exit", ex_it}
};
	for (; a < 2; a++)
	{
	if (_strcmp(cmd, map[a].name) == 0)
		return (map[a].func);
	}
	return (NULL);
}

char *_getenv(char *name)
{
	char **env_var, *ptr, *copy;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		for (ptr = *env_var; copy = name, *ptr == *copy; ptr++, copy ++)
		{
			if (*ptr == '=')
				break;
		}
		if ((*ptr == '=') && (*copy == '\0'))
			return (ptr + 1);
	}
	return (NULL);
}

char *path_chk(char *input)
{
	char **array = NULL, *path = _getenv("PATH");
	char *cp1, *cp2, *path_ptr;
	int a, b;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_ptr = malloc(sizeof(*path_ptr) * (_strlen(path) + 1));
	_strcpy(path, path_ptr);

	array = splitter(path_ptr, ":");

	for (a = 0; array[a] != NULL; a++)
	{
		cp2 = _strcat(array[a], "/");
		cp1 = _strcat(cp2, input);
		b = access(cp1, F_OK);
		if (b == 0)
		{
			free(cp2);
			free(array);
			free(path_ptr);
			return (cp1);
		}
		free(cp1);
		free(cp2);
	}
	free(path_ptr);
	free(array);
	return (NULL);
}

int parse_cmd(char *input)
{
	int a = 0;
	char *inbuilt[] = {"env", "exit", NULL};
   	char *path = NULL;

	while (input[a] != '\0')
	{
		if (input[a] == '/')
			return (EXTERNAL_COMMAND);
		a++;
	}
	for (a = 0; inbuilt[a] != NULL; a++)
	{
		if (_strcmp(input, inbuilt[a]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = path_chk(input);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}
	return (INVALID_COMMAND);
}

void _exec(char **input_str, int input)
{
	void (*func)(char **cmd);

	if (input == EXTERNAL_COMMAND)
	{
		if (execve(input_str[0], input_str, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (input == PATH_COMMAND)
	{
		if(execve(path_chk(input_str[0]), input_str, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);

		}
	}
	if (input == INTERNAL_COMMAND)
	{
		func = get_func(input_str[0]);
		func(input_str);
	}
	if (input == INVALID_COMMAND)
	{
		_puts(name, STDERR_FILENO);
		_puts(": 1: ", STDERR_FILENO);
		_puts(input_str[0], STDERR_FILENO);
		_puts(": not found\n", STDERR_FILENO);
		status = 127;
	}
}	
