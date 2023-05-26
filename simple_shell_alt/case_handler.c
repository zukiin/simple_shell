#include "main.h"

void handle_ctrlc(int signum)
{
	if (signum == SIGINT)
		_puts("\n($)", STDIN_FILENO);
}

void handle_com(char *com)
{
	int a = 0;

	if (com[a] == '#')
		com[a] = '\0';
	for (; com[a] != '\0'; a++)
	{
		if (com[a] == '#' && com[a - 1] == ' ')
			break;
	}
	com[a] = '\0';
}
