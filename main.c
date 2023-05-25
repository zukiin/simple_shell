#include "main.h"

int status = 0;
char *term = NULL;
char *name = NULL;
char **cmd = NULL;

int main(int argc __attribute__((unused)), char **argv)
{
	size_t n = 0;
	char **input_str =NULL;
	int a = 0, input = 0;

	signal(SIGINT, handle_ctrlc);
	name = argv[0];
	while (1)
	{
		from_term();
		_puts(" cisfun$ ", STDOUT_FILENO);
		if (getline(&term, &n, stdin) == -1)
		{
			free(term);
			exit(status);
		}
		handle_com(term);
		wipe_nl(term);
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
		free(cmd);
	}
	free(term);
	return (status);
}
