#include "main.h"

void _exec(char **argv)
{
	int p, status;

	if (argv == NULL || argv[0] == NULL)
		return;

	p = fork();
	if (p == -1)
	{
		perror("Fork ERROR");
	}

	if (p == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh: 1",argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
}
