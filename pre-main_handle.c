#include "main.h"

void _isatty()
{
	const char *text_prompt = "cisfun$ ";

	if (isatty(STDIN_FILENO)) 
		write(STDOUT_FILENO, text_prompt, _strlen(text_prompt));
}

void ctrl_chk(int sign)
{
	if (sign == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

void _EOF(int length, char* str)
{
	(void)str;

	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(str);
		}
		exit(0);
	}
}

