#include "main.h"

/**
  * _atoi - converts a string to an int value
  * @s: string being passed
  * Return: an int value
  */
int _atoi(const char *s)
{
	int index = 0, result = 0, sign = 1;

	if (s[index] == '+' || s[index] == '-')
	{
		sign = (s[index] == '-') ? -1 : 1;
		index++;
	}
	while ((s[index] >= '0') && (s[index] <= '9') && s[index] != '\0')
	{
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 &&
					(s[index] - '0') > INT_MAX % 10))
		{
			_exit(EXIT_FAILURE);
		}
		result = result * 10 + (s[index] - '0');
		index++;
	}
	return (sign * result);
}

/**
  * str_split - splits strings into multiple substrings
  * @string: string to split
  * @delimiter: delimiter between strings
  * Return: an array of split substrings
  */

char **str_split(char *string, const char *delimiter)
{
	int a, b;
	char **arr;
	char *split, *temp;

	temp = malloc(1 + _strlen(string));
	if (temp == NULL)
	{
		perror("Error allocating memory");
		return (NULL);
	}
	a = 0;
	while (string[a] != '\0')
	{
		temp[a] = string[a];
		a++;
	}
	temp[a] = '\0';

	split = strtok(temp, delimiter);
	arr = malloc(sizeof(char *) * 2);
	arr[0] = _strdup(split);

	a = 1;
	b = 3;

	while (split)
	{
		split = strtok(NULL, delimiter);
		arr = re_alloc(arr, (sizeof(char *) * (b - 1)), sizeof(char *) * b);
		arr[a] = _strdup(split);
		a++;
		b++;
	}
	free(temp);
	return (arr);
}
