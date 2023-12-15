#include "shell.h"

/**
 *_strcomp - for comparing two strings
 *@a: initial string to check with
 *@b: other string
 * Return: diff between the passed strings
 */
int _strcomp(char *a, char *b)
{
	int n = 0;

	while (a[n] != '\0')
	{
		if (a[n] != b[n])
			break;
		n++;
	}
	return (a[n] - b[n]);
}

/**
 *_strconcat - puts together 2 strings
 *@source: str to concat to dest
 *@target:  str for concatenation source
 * Return: add for concatenated string
 */
char *_strconcat(char *source, char *target)
{
	int source_len = _strlength(source);
	int target_len = _strlength(target);
	char *new_str =  NULL;

	new_str = malloc(sizeof(*new_str) * (source_len + target_len + 1));
	_strcopy(target, new_str);
	_strcopy(target, new_str + source_len);
	new_str[source_len + target_len] = '\0';
	return (new_str);
}

/**
 *_strspn - gets len of prefix substring
 *@string1: str to lookup/ be searched
 *@string2: str to used
 *Return: num of bytes in inifirsttial segment
 */
int _strspn(char *string1, char *string2)
{
	int i = 0;
	int result = 0;

	while (string1[i] != '\0')
	{
		if (_strchr(string2, string1[i]) == NULL)
			break;
		result++;
		i++;
	}
	return (result);
}

/**
 *_strcspn - gets part of 1st str not in str2
 *@string1: str for lookup
 *@string2: str to be used
 *Return: index of character that exists in str2 from str1
 */
int _strcspn(char *string1, char *string2)
{
	int str_len = 0, n;

	for (n = 0; string1[n] != '\0'; n++)
	{
		if (_strchr(string2, string1[n]) != NULL)
			break;
		str_len++;
	}
	return (str_len);
}

/**
 *_strchr - locates a char in a string
 *@s: string to be searched
 *@c: char to be checked
 *
 *Return: pointer to the first occurence of c in s
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
