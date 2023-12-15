#include "shell.h"

/**
 * tokenize - for tokenizing output from str
 *@str_entered: str passed
 *@delimiter: delimiter to use
 *Return: arr of tokens
 */
char **tokenize(char *str_entered, char *delimiter)
{
	int delimit_num = 0;
	char **n = NULL;
	char *t = NULL;
	char *ptr = NULL;

	t = _strtoken_r(str_entered, delimiter, &ptr);

	while (t != NULL)
	{
		n = _realloc(n, sizeof(*n) * delimit_num, sizeof(*n) * (delimit_num + 1));
		n[delimit_num] = t;
		t = _strtoken_r(NULL, delimiter, &ptr);
		delimit_num++;
	}

	n = _realloc(n, sizeof(*n) * delimit_num, sizeof(*n) * (delimit_num + 1));
	n[delimit_num] = NULL;

	return (n);
}

/**
 *print - for printing str to standard output
 *@str: str to print
 *@to_print: to be printed out to stdout
 */
void print(char *str, int to_print)
{
	int n = 0;

	for (; str[n] != '\0'; n++)
		write(to_print, &str[n], 1);
}

/**
 *rm_newline - rm new lines
 *@strin: string to be used
 */

void rm_newline(char *strin)
{
	int n = 0;

	while (strin[n] != '\0')
	{
		if (strin[n] == '\n')
			break;
		n++;
	}
	strin[n] = '\0';
}

/**
 * _strcopy - for copying str
 * @s: to copy from
 * @d: dest for str copied
 */
void _strcopy(char *s, char *d)
{
	int n = 0;

	for (; s[n] != '\0'; n++)
		d[n] = s[n];
	d[n] = '\0';
}

/**
 * _strlength - get str len
 * @str: str inputted
 * Return: str len
 */
int _strlength(char *str)
{
	int l = 0;

	if (str == NULL)
		return (l);
	for (; str[l] != '\0'; l++)
		;
	return (l);
}
