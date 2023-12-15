#include "shell.h"

/* main's extension*/

/**
 * parse_cmd - realizes cmd type
 * @cmd: cmd to be parsed
 *
 * Return: const for type of the cmd
 * Description -
 *	INVALID_CMD = -1 (self-explanatory)
 *	EXT_CMD = 1
 *	INT_CMD = 2 (e.g., exit)
 *	PATH_CMD = 3 (e.g., ls)
 */

int parse_cmd(char *cmd)
{
	int i;
	char *int_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (EXT_CMD);
	}
	for (i = 0; int_cmd[i] != NULL; i++)
	{
		if (_strcomp(cmd, int_cmd[i]) == 0)
			return (INT_CMD);
	}
	/* @path_checker - for checking if a cmd is found in path */
	path = path_checker(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}

	return (INVALID_CMD);
}

/**
 * exec_cmd - executes a command based on it's type
 * @tokenized_cmd: e.h., {ls, -l, NULL}
 * @cmd_type: cmd type
 *
 * Return: void
 */
void exec_cmd(char **tokenized_cmd, int cmd_type)
{
	void (*func)(char **cmd);

	if (cmd_type == EXT_CMD)
	{
		if (execve(tokenized_cmd[0], tokenized_cmd, NULL) == -1)
		{
			perror(_get_env("PWD"));
			exit(2);
		}
	}
	if (cmd_type == PATH_CMD)
	{
		if (execve(path_checker(tokenized_cmd[0]), tokenized_cmd, NULL) == -1)
		{
			perror(_get_env("PWD"));
			exit(2);
		}
	}
	if (cmd_type == INT_CMD)
	{
		func = get_funct(tokenized_cmd[0]);
		func(tokenized_cmd);
	}
	if (cmd_type == INVALID_CMD)
	{
		print(name_of_shell, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_cmd[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * path_checker - for checking if a cmd is found in path
 * @cmd: cmd to use
 *
 * Return: path of cmd, else NULL
 */
char *path_checker(char *cmd)
{
	char **arr_of_path = NULL;
	char *t, *t2, *cpy_path;
	char *path = _get_env("PATH");
	int i;

	if (path == NULL || _strlength(path) == 0)
		return (NULL);
	cpy_path = malloc(sizeof(*cpy_path) * (_strlength(path) + 1));
	_strcopy(path, cpy_path);
	arr_of_path = tokenize(cpy_path, ":");
	for (i = 0; arr_of_path[i] != NULL; i++)
	{
		t2 = _strconcat(arr_of_path[i], "/");
		t = _strconcat(t2, cmd);
		if (access(t, F_OK) == 0)
		{
			free(t2);
			free(arr_of_path);
			free(cpy_path);
			return (t);
		}
		free(t);
		free(t2);
	}
	free(cpy_path);
	free(arr_of_path);
	return (NULL);
}

/**
 * get_funct - gets funct based on string provided
 * @cmd: cmd string to verify from map
 * Return: pointer to func, else fail
 */
void (*get_funct(char *cmd))(char **)
{
	int i;
	func_mapper mapping[] = {
		{"env", env}, {"exit", exit_}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcomp(cmd, mapping[i].cmd_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * _get_env - retrieves vals of env var
 * @var_name: env var name
 * Return: val of var as str, else null
 */
char *_get_env(char *var_name)
{
	char **my_env;
	char *ptr_pair;
	char *cpy_name;

	for (my_env = environ; *my_env != NULL; my_env++)
	{
		for (ptr_pair = *my_env, cpy_name = var_name;
		     *ptr_pair == *cpy_name; ptr_pair++, cpy_name++)
		{
			if (*ptr_pair == '=')
				break;
		}
		if ((*ptr_pair == '=') && (*cpy_name == '\0'))
			return (ptr_pair + 1);
	}
	return (NULL);
}
