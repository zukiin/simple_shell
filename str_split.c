#include "main.h"

/**
  * _strtok - creates a string token
  * str:
  * seperator:
  * Returns a token
  */

char **_strtok(char *str, char *separator)
{
	char **strings, *part;
	int i = 0, j = 0;

	string = malloc(8 * sizeof(char *));
	if (string == NULL)
	{
		perror("can't allocate space");
		exit(1);
	}
	part = strtok(str, " ");
	while (part != NULL)
	{
		while (part[j])
		{
			if (pars[j] == '\n')
				pars[j] = '\0';
			j++;
		}
		arst[i] = pars;
		i++;

		j = 0;
		pars = strtok(NULL, " ");
		/* ^ start reading from the NULL till you get to the delimiter " " */
	}
	arst[i] = NULL;
	return (arst);
}
