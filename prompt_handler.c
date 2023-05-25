#include "main.h"

void prompt(char **input_str, int input)
{
	pid_t PID;

	if (input == EXTERNAL_COMMAND || input == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			_exec(input_str, input);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		_exec(input_str, input);
}

void from_term(void)
{
	char **input_str = NULL;
	int a = 0, input = 0;
	size_t n = 0;

	if(!(isatty(STDIN_FILENO)))
	{
		while (getline(&term, &n, stdin))
		{
			wipe_nl(term);
			handle_com(term);
			cmd = splitter(term, ";");
			while (cmd[a] != NULL)
			{
				input_str = splitter(cmd[a], " ");
				if (input_str[0] == NULL)
				{
					free(input_str);
					break;
				}
				input = parse_cmd(input_str[0]);
				prompt(input_str, input);
				free(input_str);
				a++;
			}
		}
		free(cmd);
	}
	free(term);
	exit(status);
}
