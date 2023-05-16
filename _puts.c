#include "main.h"

int _putchar(char c)
{
	return(write(1, &c, 1));
}

int _puts(const char *string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
	return (i);
}
