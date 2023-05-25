#include "main.h"

void *_realloc(void *p, size_t old, size_t new)
{
	void *temp;
	size_t a = 0;

	if (p == NULL)
	{
		temp = malloc(new);
		return (temp);
	}
	else if (new == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	else if (new == old)
		return (p);
	else
	{
		temp = malloc(new);
		if (temp != NULL)
		{
			while (a < min(old, new))
			{
				*((char *)temp + a) = *((char *)p + a);
				a++;
			}
			free(p);
			return (temp);
		}
		else
			return (NULL);
	}
}
