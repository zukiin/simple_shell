#include "main.h"

void text_prompt()
{
	const char *text_prompt = "cisfun$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, text_prompt, strlen(text_prompt));
}
