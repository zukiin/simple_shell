#include "shell.h"

/**
*_strcmp - compare two strings
*@s1: first string
*@s2: second string
*
* Return: their difference
*/

int _strcmp(char *s1, char *s2)
{
	int a = 0;

	for (;s1[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			break;
	}
	return (s1[a] - s2[a]);
}

/**
*_strcat - concatenates two strings
*@to: string to be concatenated to
*@from:  string to concatenate
*
* Return: new string's address.
*/

char *_strcat(char *from, char *to)
{
	char *new =  NULL;
	int len1 = _strlen(from);
	int len_2 = _strlen(to);

	new = malloc(sizeof(*new) * (len1 + len_2 + 1));
	_strcpy(from, new);
	_strcpy(to, new + len1);
	new[len1 + len_2] = '\0';
	return (new);
}

/**
*_strspn - gets the length of a prefix substring
*@s1: string to be searched
*@s2: string to be used
*
*Return: number of bytes
*/

int _strspn(char *s1, char *s2)
{
	int a = 0;
	int count = 0;

	while (s1[a] != '\0')
	{
		if (_strchr(s2, s1[a]) == NULL)
			break;
		count++;
		a++;
	}
	return (count);
}

/**
*_strcspn - finds what members of a string is in another.
*@s1: string to be searched
*@s2: string to be used
*
*Return: index at which a char in str1 exists in str2
*/


int _strcspn(char *s1, char *s2)
{
	int count = 0, a = 0;

	for (; s1[a] != '\0'; a++)
	{
		if (_strchr(s2, s1[a]) != NULL)
			break;
		count++;
	}
	return (count);
}

/**
*_strchr - finds a character in an array of characters
*@a: string to be searched
*@c: char to be checked
*
*Return: pointer to the first occurence of c in s
*/

char *_strchr(char *a, char c)
{
	int ind = 0;

	for (; a[ind] != c && a[ind] != '\0'; ind++);
	if (a[ind] == c)
		return (a + ind);
	else
		return (NULL);
}
