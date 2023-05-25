#include "main.h"

char *_strtok(char *str, char *dem, char **ptr)
{
	char *end;

	if (!str)
	{
		str = *ptr;
	}
	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}
	str = str + _strspn(str, dem);
	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}
	end = str + _strcspn(str, dem);
	if (*end == '\0')
	{
		*ptr = end;
		return (str);
	}

	*end = '\0';
	*ptr = end + 1;
	return (str);
}

int _atoi(char *s)
{
	size_t num = 0;

	do 
	{
		if (*s == '-')
			return (-1);
		else if (num > 0)
			break;
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
	} while (*s++);
	return (num);
}

void _strcpy(char *from, char *to)
{
	int a;

	for (a = 0; from[a] != '\0'; a++)
		to[a] = from[a];
	to[a] = '\0';
}

int _strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (length);

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void wipe_nl(char *string)
{
	int a = 0;

	for (; string[a] != '\0'; a++)
	{
		if (string[a] == '\n')
			break;
	}
	string[a] = '\0';
}

void _puts(char *str, int stream)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
		write(stream, &str[a], 1);
}

char **splitter(char *str, char *dem)
{
	int num = 0;
	char **argv = NULL, *split = NULL, *ptr = NULL;

	split = _strtok(str, dem, &ptr);

	while (split)
	{
		argv = _realloc(argv, sizeof(*argv) * num, sizeof(*argv) * (num + 1));
		argv[num] = split;
		split = _strtok(NULL, dem, &ptr);
		num++;
	}
	argv = _realloc(argv, sizeof(*argv) * num, sizeof(*argv) *(num + 1));
	argv[num] = NULL;
	return (argv);
}
