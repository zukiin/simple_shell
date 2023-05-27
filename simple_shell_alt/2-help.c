#include "shell.h"

/**
*_strtok - splits a string
*@s: string to be splitted
*@dem: delimiter to be used to split the string
*ptr: pointer to be used to keep track of the next extract
*
*Return: The next available token
*/
char *_strtok(char *s, char *dem, char **ptr)
{
	char *end;

	if (s == NULL)
		s = *ptr;

	if (*s == '\0')
	{
		*ptr = s;
		return (NULL);
	}

	s += _strspn(s, dem);
	if (*s == '\0')
	{
		*ptr = s;
		return (NULL);
	}

	end = s + _strcspn(s, dem);
	if (*end == '\0')
	{
		*ptr = end;
		return (s);
	}

	*end = '\0';
	*ptr = end + 1;
	return (s);
}

/**
* _atoi - changes a string to an integer
* @s: the string.
*
* Return: the converted int
*/

int _atoi(char *s)
{
	unsigned int n = 0;

	do {
			if (*s == '-')
				return (-1);
			else if ((*s < '0' || *s > '9') && *s != '\0')
				return (-1);
			else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
			else if (n > 0)
				break;
		} while (*s++);
	return (n);
}

/**
* _realloc - reallocates a memory block
* @ptr: pointer to the pre-allocated memory block.
* @old: size of ptr
* @new: size of the new memory to be allocated
*
* Return: pointer to the address of the new memory block
*/
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	void *vault;
	unsigned int a;

	if (ptr == NULL)
	{
		vault = malloc(new);
		return (vault);
	}
	else if (new == old)
		return (ptr);
	else if (new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		vault = malloc(new);
		if (vault != NULL)
		{
			for (a = 0; a < min(old, new); a++)
			*((char *)vault + a) = *((char *)ptr + a);
			free(ptr);
			return (vault);
		}
		else
			return (NULL);
	}
}

/**
* handle_ctrlc - this function handles the signal raised by CTRL-C
* @signum: signal number
*
* Return: void
*/
void handle_ctrlc(int signum)
{
	if (signum == SIGINT)
		_puts("\n($) ", STDIN_FILENO);
}

/**
* wipe_com - removes everything after the '#'
* @s: input
*
* Return: void

*/
void wipe_com(char *s)
{
	int a = 0;

	if (s[a] == '#')
		s[a] = '\0';
	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == '#' && s[a - 1] == ' ')
			break;
		a++;
	}
	s[a] = '\0';
}
