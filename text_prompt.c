#include "main.h"

int text_prompt()
{
	const char *text_prompt = "cisfun$ ";
	int value;

	value = (isatty(STDIN_FILENO));
	if (value == 1)
	write(STDOUT_FILENO, text_prompt, strlen(text_prompt)); /* create a strlen function */
	return (value);
}
