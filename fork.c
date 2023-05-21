#include "main.h"

void forkexe(char **arstr, char **envp)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: Fork issue");
		return
	}
	if (child_pid == 0)
	{
		if (execve(arstr[0], arstr, envp) == -1)
			perror("./shell: No such file or directory\n");
	}
	else
	{
		wait(&status);
	}
}
