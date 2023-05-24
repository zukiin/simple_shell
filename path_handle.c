#include "main.h"

path_name *add_node(path_name **head, char *str)
{
	path_name *temp;
	path_name *new;

	new = malloc(sizeof(path_name));

	if (!new || !str)
	{
		return (NULL);
	}
	new->dir = str;
	new->ptr = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->ptr)
		{
			temp = temp->ptr;
		}
		temp->ptr = new;
	}
	return (*head);
}

path_name *path_link(char *path)
{
	path_name *head = NULL;
	char *split, *c_path = _strdup(path);

	split = strtok(c_path, ":");
	while (split)
	{
		head = add_node(&head, split);
		split = strtok(NULL, ":");
	}
	return (head);
}

char *find_path(path_name *head, char *filename)
{
	struct stat status;
	char *string;

	path_name *temp = head;
	while (temp)
	{
		string = con_cat(temp->dir, "/", filename);
		if (stat(string, &status) == 0)
		{
			return (string);
		}
		free(string);
		temp = temp->ptr;
	}
	return (NULL);
}

void _freelist(path_name *head)
{
	path_name *temp;

	while (head)
	{
		temp = head->ptr;
		free(head->dir);
		free(head);
		head = temp;
	}
}
