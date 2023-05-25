#include "main.h"

char *_strchr(char *str, char c)
{
	int a;

	for (a = 0; str[a] != c && str[a] != '\0'; a++);

	if (str[a] == c)
		return (str + a);
	else
		return (NULL);
}

int _strspn(char *s, char *p)
{
	int a, same = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (_strchr(p, s[a]) == NULL)
			break;
		same++;
	}
	return (same);
}

int _strcspn(char *s, char *p)
{
	int a = 0, len = 0;

	for (; s[a] != '\0'; a++)
	{
		if (_strchr(p, s[a]) != NULL)
			break;
		len++;
	}
	return (len);
}

char *_strcat(char *to, char *from)
{
	char *new = NULL;
	int a = _strlen(to);
	int b = _strlen(from);

	new = malloc(sizeof(*new) * (a + b + 1));
	_strcpy(to, new);
	_strcpy(from, new + a);
	new[a + b] = '\0';
	return (new);
}

int _strcmp(char *s1, char *s2)
{
	int a = 0, diff = 0;

	for (; s1[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			break;
	}
	diff = s1[a] - s2[a];
	return (diff);
}
