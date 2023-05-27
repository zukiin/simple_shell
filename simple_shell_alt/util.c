#include "shell.h"


/**
* prep - ascertains the type of the command
* @input: command to be parsed
*
* Return: value representing the type of the command
*/

int prep(char *input)
{
	char *internal_command[] = {"env", "exit", NULL};
	char *path = NULL;
	int a;

	for (a = 0; input[a] != '\0'; a++)
	{
		if (input[a] == '/')
			return (EXTERNAL_COMMAND);
	}

	for (a = 0; internal_command[a] != NULL; a++)
	{
		if (_strcmp(input, internal_command[a]) == 0)
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

/**
* execute_command - executes a command based on it's type
* @split: tokenized form of the command (ls -l == {ls, -l, NULL})
* @c_type: type of the command
*
* Return: void
*/

void execute_command(char **split, int c_type)
{
	void (*func)(char **command);

	if (c_type == EXTERNAL_COMMAND)
	{
		if (execve(split[0], split, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}

	if (c_type == PATH_COMMAND)
	{
		if (execve(path_chk(split[0]), split, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}

	if (c_type == INTERNAL_COMMAND)
	{
		func = get_func(split[0]);
		func(split);
	}

	if (c_type == INVALID_COMMAND)
	{
		_puts(name, STDERR_FILENO);
		_puts(": 1: ", STDERR_FILENO);
		_puts(split[0], STDERR_FILENO);
		_puts(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
* path_chk - checks if a command is found in the PATH
* @input: command
*
* Return: path where the command is found in or NULL.
*/
char *path_chk(char *input)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int i;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));

	_strcpy(path, path_cpy);
	path_array = splitter(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = _strcat(path_array[i], "/");
		temp = _strcat(temp2, input);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
* get_func - retrieves a function based on the command given and a mapping
* @command: string to check against the mapping
*
* Return: pointer to the proper function, or null on fail
*/
void (*get_func(char *command))(char **)
{
	int a;
	function_form path[] = {
	{"env", env},
	{"exit", ex_it}
	};

	for (a = 0; a < 2; a++)
	{
		if (_strcmp(command, path[a].command_name) == 0)
			return (path[a].func);
	}
		return (NULL);
}
/**
*_getenv - gets the value of an environment variable
* @title: name of the environment variable
*
* Return: the value of the variable as a string
*/
char *_getenv(char *title)
{
	char **env_var;
	char *ptr;
	char *name;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		for (ptr = *env_var, name = title;
	     *ptr == *name; ptr++, name++)
		{
			if (*ptr == '=')
				break;
		}
		if ((*ptr == '=') && (*name == '\0'))
			return (ptr + 1);
	}

	return (NULL);
}
