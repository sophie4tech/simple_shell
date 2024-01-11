#include "shell.h"
/**
 * tokstr - breaks string into words 
 * @str: a pointer to the string to be tokenize
 * @delim: a set of bytes that delimit the tokens
 * Return: a pointer to the next token, NULL if no more tokens
 */
char *tokstr(char *str, char *delim)
{
	char *begin, *end, *toks = NULL;

	if (str != NULL)
	{
		toks = str;
	}
	else if (toks == NULL)
	{
		return (NULL);
	}
	begin = toks;
	while (*begin != '\0' && _findchar(delim, *begin) == NULL)
	{
		begin++;
	}
	if (*begin == '\0')
	{
		toks = NULL;
		return (NULL);
	}
	end = begin;
	while (*end != '\0' && _findchar(delim, *end) == NULL)
	{
		end++;
	}
	if (*end != '\0')
	{
		*end = '\0';
		toks = ++end;
	}
	else
	{
		toks = NULL;
	}
	return (begin);
}
