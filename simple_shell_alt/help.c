#include "shell.h"

/**
* splitter - splits a string and stores them in an array
*@input: strings to be parsed
*@dem: delimiter to be used.
*
*Return: an array.
*/

char **splitter(char *input, char *delim)
{
	int dem = 0;
	char **str = NULL;
	char *split = NULL;
	char *ptr = NULL;
	split = _strtok(input, delim, &ptr);

	while (split != NULL)
	{
		str = _realloc(str, sizeof(*str) * dem, sizeof(*str) * (dem + 1));
		str[dem] = split;
		split = _strtok(NULL, delim, &ptr);
		dem++;
	}
		str = _realloc(str, sizeof(*str) * dem, sizeof(*str) * (dem + 1));
		str[dem] = NULL;
		return (str);
}

/**
*_puts - prints a string to stdout
*@s: string to be printed
*@st: string to print out to
*
*Return: nothing
*/

void _puts(char *s, int st)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	write(st, &s[a], 1);
}

/**
*wipe_nl - removes new line from a string
*@s: string to be used
*
*Return: void
*/

void wipe_nl(char *s)
{
	int a = 0;

	for ( ; s[a] != '\0'; a++)
	{
		if (s[a] == '\n')
			break;
	}
	s[a] = '\0';
}

/**
*_strcpy - copies a string to another buffer
*@to: to copy from
*@from: to copy to
*
* Return: void
*/

void _strcpy(char *from, char *to)
{
	int a = 0;

	for (; from[a] != '\0'; a++)
		to[a] = from[a];
	to[a] = '\0';
}

/**
*_strlen - counts a string
*@string: string
*
* Return: length of the string
*/

int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (a);

	for ( ; s[a] != '\0'; a++);
	
	return (a);
}
