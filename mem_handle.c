#include "main.h"
/**
 * re_alloc - This reallocates a memory block.
 * @ptr: pointer to previously allocated memory.
 * @old_size:ptr size
 * @new_size:size of the newly created memory.
 *
 * Return: a pointer to the newly allocated memory.*/

void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new, *former;
	unsigned int num = 0;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new  = malloc(new_size);
	former = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (; num < old_size; num++)
			new[num] = former[num];
		free(ptr);

		for (num = old_size; num < new_size; num++)
			new[num] = '\0';
	}
	if (new_size < old_size)
	{
		for (num = 0; num < new_size; num++)
			new[num] = former[num];
		free(ptr);
	}
	return (new);
}
/**
 * free_argv: frees an array of strings.
 * @arg: array to be freed.
 *
 * Return: nothing
 */
void free_argv(char **arg)
{
	int a;

	for (a = 0; arg[a]; a++)
		free(arg[a]);
	free(arg);
}
