#include "main.h"
/**
 * _isatty - checks if a command is from the terminal.
 * Return: nothing.
 */

void _isatty()
{
	const char *text_prompt = "cisfun$ ";

	if (isatty(STDIN_FILENO)) 
		write(STDOUT_FILENO, text_prompt, _strlen(text_prompt));
}
/**
 * ctrl_chk - accommodates control - c commands.
 * @sign: a representation for control-c.
 *
 * Return: nothing.
 */ 
void ctrl_chk(int sign)
{
	if (sign == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}
/**
 * _EOF - finds the end of a string.
 * @length: length of the string.
 * @str:

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

