#include "shell.h"

/**
* non_interactive - handles non_interactive mode
*
* Return: void
*/

void non_terminal(void)
{
	char ** command = NULL;
	int a, c_type = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&term, &n, stdin) != -1)
		{
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
		exit(status);
	}
}
