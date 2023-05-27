#include "shell.h"

	char **cmds = NULL;
	char *term= NULL;
	char *name = NULL;
	int status = 0;

/**
* main - the main shell code
* @argc: number of arguments passed
* @argv: program arguments to be parsed

* Return: 0 on success
*/


	int main(int argc __attribute__((unused)), char **argv)
{
	char **command = NULL;
	int a, c_type = 0;
	size_t n = 0;

	signal(SIGINT, handle_ctrlc);
	name = argv[0];
	while (1)
	{
		non_terminal();
		_puts(" ($) ", STDOUT_FILENO);

		if (getline(&term, &n, stdin) == -1)
		{
			free(term);
			exit(status);
		}
		wipe_nl(term);
		wipe_com(term);
		cmds = splitter(term, ";");

		for (a = 0; cmds[a] != NULL; a++)
		{
			command = splitter(cmds[a], " ");
			if (command[0] == NULL)
			{
				free(command);
					break;
			}
			c_type = prep(command[0]);

			prompt(command, c_type);
			free(command);
		}
			free(cmds);
	}
	free(term);
	return (status);
}
