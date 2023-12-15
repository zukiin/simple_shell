#include "shell.h"

/* Auth: Zuki Nkalitshana */

	char **cmds = NULL;
	char *line = NULL;
	char *name_of_shell = NULL;
	int status = 0;

/**
 * main - entry point for program
 * @argc: args passed
 * @argv: args vector to pass
 * for funcs in utils and implementing end of file
 * Return: 0 on success and err on failure
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char **current_cmd = NULL;
	int i, cmd_type = 0;
	size_t n = 0;

	signal(SIGINT, control_c_handler);
	name_of_shell = argv[0];

	while (1)
	{
		not_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			rm_newline(line);
			rm_comment(line);
			cmds = tokenize(line, ";");

		for (i = 0; cmds[i] != NULL; i++)
		{
			current_cmd = tokenize(cmds[i], " ");
			if (current_cmd[0] == NULL)
			{
				free(current_cmd);
				break;
			}
			cmd_type = parse_cmd(current_cmd[0]);

			initialize_(current_cmd, cmd_type);
			free(current_cmd);
		}
		free(cmds);
	}
	free(line);

	return (status);
}
