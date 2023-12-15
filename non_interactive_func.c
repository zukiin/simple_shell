#include "shell.h"

/**
 * not_interactive - for non-interactive
 * Return: void
 */

void not_interactive(void)
{
	char **current_cmd = NULL;
	int n, type_cmd = 0;
	size_t s = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &s, stdin) != -1)
		{
			rm_newline(line);
			rm_comment(line);
			cmds = tokenize(line, ";");
			for (n = 0; cmds[n] != NULL; n++)
			{
				current_cmd = tokenize(cmds[n], " ");
				if (current_cmd[0] == NULL)
				{
					free(current_cmd);
					break;
				}
				type_cmd = parse_cmd(current_cmd[0]);
				initialize_(current_cmd, type_cmd);
				free(current_cmd);
			}
			free(cmds);
		}
		free(line);
		exit(status);
	}
}
