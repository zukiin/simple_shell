#include "main.h"

/**
  * prompt - waits for user input
  * av: arr vector
  * env: env variable
  */
void prompt(char **av, char **env) {
	ssize_t char_num;
	size_t size = 0;
	char **buffer = NULL;
	bool not_term = false;

	while (!not_term && 1)
	{
		if (text_prompt() == 0)
			not_term = true;

		char_num = getline(&buffer, &size, stdin);

		if (char_num == -1) {
			free(buffer);
			perror("Getline failed");
			exit(EXIT_FAILURE);
		}

		execute_command(av, env, buffer);
	}
}
