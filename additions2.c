#include "shell.h"

/**
 *_strtoken_r - string tokenization
 *@str: str passed
 *@delimit: dstring's delimiter
 *@ptr: ptr for token tracking
 *Return: next token
 */
char *_strtoken_r(char *str, char *delimit, char **ptr)
{
	char *c;

	if (str == NULL)
		str = *ptr;

	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}

	str += _strspn(str, delimit);

	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}

	c = str + _strcspn(str, delimit);

	if (*c == '\0')
	{
		*ptr = c;
		return (str);
	}

	*c = '\0';
	*ptr = c + 1;
	return (str);
}

/**
 * _atoi - changes str to int
 * @str: string to convert
 * Return: resulting int
 */
int _atoi(char *str)
{
	unsigned int i = 0;

	do {
		if (*str == '-')
			return (-1);
		else if ((*str < '0' || *str > '9') && *str != '\0')
			return (-1);
		else if (*str >= '0'  && *str <= '9')
			i = (i * 10) + (*str - '0');
		else if (i > 0)
			break;
	} while (*str++);
	return (i);
}

/**
 * _realloc - reallocates mem blocks
 * @p: pointer to previously allocated mem block
 * @size_old: size of pointer
 * @size_new: memory size for alloc
 * Return: ptr to new mem block's address
 */
void *_realloc(void *p, unsigned int size_old, unsigned int size_new)
{
	void *temp;
	unsigned int n;

	if (p == NULL)
	{
		temp = malloc(size_new);
		return (temp);
	}
	else if (size_new == size_old)
		return (p);
	else if (size_new == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	else
	{
		temp = malloc(size_new);
		if (temp != NULL)
		{
			for (n = 0; n < min(size_old, size_new); n++)
				*((char *)temp + n) = *((char *)p + n);
			free(p);
			return (temp);
		}
		else
			return (NULL);
	}
}


/**
 * control_c_handler - for handling of signal raised
 * @signal_num: signal num
 * Return: nothing
 */
void control_c_handler(int signal_num)
{
	if (signal_num == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
 * rm_comment - does not consider comments press after #
 * @entered: data entered for use
 * Return: nothing
 */
void rm_comment(char *entered)
{
	int n = 0;

	if (entered[n] == '#')
		entered[n] = '\0';
	while (entered[n] != '\0')
	{
		if (entered[n] == '#' && entered[n - 1] == ' ')
			break;
		n++;
	}
	entered[n] = '\0';
}
