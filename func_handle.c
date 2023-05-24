#include "main.h"

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
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[index] - '0') > INT_MAX % 10))
		{
			_exit(EXIT_FAILURE);
		}
		result = result * 10 + (s[index] - '0');
		index++;
	}
	return (sign * result);
}

char **str_split(char *string, const char *delimiter)
{
	int a, b;
	char **array;
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
	array = malloc(sizeof(char *) * 2);
	array[0] = _strdup(split);

	a = 1;
	b = 3;

	while (split)
	{
		split = strtok(NULL, delimiter);
		array = re_alloc(array, (sizeof(char *) * (b - 1)), sizeof(char *) * b);
		array[a] = _strdup(split);
		a++;
		b++;
	}
	free(temp);
	return (array);
}
