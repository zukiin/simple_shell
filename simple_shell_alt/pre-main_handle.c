#include "main.h"

/**
  * _isatty - checks if fd is open
  */
void _isatty(void)
{
	const char *text_prompt = "cisfun$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, text_prompt, _strlen(text_prompt));
}

/**
  * ctrl_chk - handle signal raised
  * @sign: signal num
  */
void ctrl_chk(int sign)
{
	if (sign == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
  * _EOF - checks for the end of file
  * @length: length
  * @str: string pointer
  */
void _EOF(int length, char *str)
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

