#include "main.h"

/**
  * _putchar - writes a character to stdout
  * @a: char to be writ
  * Return: char writ in stdout
  */
int _putchar(char a)
{
	return (write(1, &a, 1));
}

/**
  * _puts - outputs an arr of char using _putchar
  * @buff: character array
  */
void _puts(char *buff)
{
	int a = 0;

	while (buff[a])
	{
		_putchar(buff[a]);
		a++;
	}
}

/**
  * con_cat - concatenates character arrays
  * @str: character array
  * @dim: array of char 2
  * @value: arr of char 3
  * Return: concatenated string
  */
char *con_cat(char *str, char *dim, char *value)
{
	char *res;
	int a, b, c, i, len;

	a = _strlen(str);
	b = _strlen(dim);
	c = _strlen(value);

	res = malloc(a + b + c + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		res[i] = str[i];

	len = i;
	for (i = 0; dim[i]; i++)
		res[len + i] = dim[i];

	len = len + i;
	for (i = 0; value[i]; i++)
		res[len + i] = value[i];
	len = len + i;

	res[len] = '\0';
	return (res);
}

/**
  * _strlen - finds length of a string
  * @str: string passed as arr of char
  * Return: length of string
  */
int _strlen(const char *str)
{
	int a = 0;

	for (; str[a] != '\0';)
	{
		a++;
	}

	return (a);
}

/**
  * _strdup - duplicates a string
  * @str: string as an arg
  * Return: concat string
  */
char *_strdup(char *str)
{
	int a = 0, b = 0;
	char *string;

	if (str == NULL)
		return (NULL);

	while (str[a] != '\0')
	{
		a++;
	}
	string = malloc(sizeof(char) * a + 1);
	if (!string)
	{
		return (NULL);
	}
	for (; b < a; b++)
	{
		string[b] = str[b];
	}
	string[a] = str[a];
	return (string);

}
