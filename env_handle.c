#include "main.h"

void term_exit(char **argv)
{
	int index1, index2;

	if (argv[1])
	{
		index1 = _atoi(argv[1]);
		if (index1 <= -1)
			index1 = 2;
		free_argv(argv);
		exit(index1);
	}
	for (index2 = 0; argv[index2]; index2++)
		free(argv[index2]);
	free(argv);
	exit (0);
}

char *_getenv(const char *file)
{
	int a = 0, b;
	char *result;

	if (file == NULL)
		return (NULL);

	for (; environ[a]; a++)
	{
		b = 0;
		if (file[b] == environ[a][b])
		{
			while (file[b])
			{
				if (file[b] != environ[a][b])
					break;
				b++;
			}
			if (file[b] == '\0')
			{
				result = (environ[a] + b + 1);
				return (result);
			}
		}
	}
	return (0);
}


void set_env(char **argv)
{
	int a = 0, b, c;
	
	environ = (char **) malloc(_strlen(argv[0] + strlen(argv[1] + 2)));
	if (environ == NULL)
	{
		perror("Memory allocation error");
		return;
	}
	if (!argv[1] || !argv[2])
	{
		perror(_getenv("-"));
		return;
	}
	for (; environ[a]; a++)
	{
		b = 0;
		if (argv[1][b] == environ[a][b])
		{
			while (argv[1][b])
			{
				if (argv[1][b] != environ[a][b])
					break;
				b++;
			}
			if (argv[1][b] == '\0')
			{
				c = 0;
				while (argv[2][c])
				{
					environ[a][b + 1 + c] = argv[2][c];
					c++;
				}
				environ[a][b + 1 + c] = '\0';
				free(environ);
				return;
			}
		}
	}
	if (!environ[a])
	{
		environ[a] = con_cat(argv[1], "=", argv[2]);
		environ[a + 1] = NULL;
	}
}
void _unsetenv(char **argv)
{
	int a = 0, b;

	if (!argv[1])
	{
		perror("Error (unsetenv)");
		return;
	}
	for (; environ[a]; a++)
	{
		b = 0;
		if (argv[1][b] == environ[a][b])
		{
			while (argv[1][b])
			{
				if (argv[1][b] != environ[a][b])
					break;
				b++;
			}
			if (argv[1][b] == '\0')
			{
				free(environ[a]);
				environ[a] = environ[a + 1];

				while (environ[a])
				{
					environ[a] = environ[a + 1];
					a++;
					return;
				}
			}		
		}
	}
}

void _printenv(char **argv __attribute__ ((unused)))
{
	int index = 0;

	while (environ[index])
	{
		_puts(environ[index]);
		_puts("\n");
		index++;
	}
}
