#include "shell.h"
/*
 * _readline - reads a line from file
 * @lineptr: a pointer to pointer to buffer to save read line
 * @n: pointer to buffer size
 * @stream: pointer to file to read from
 * Return: characters read, or -1 on failure
 */
ssize _readline(char **lineptr, size_t *n, FILE *stream)
{
	if (!(lineptr || n || stream))
	{
		return (-1);
	}

	if (!*lineptr || * n == 0)
	{
		*n = SIZE;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}

	size_t y = 0;
	int character;

	while ((character = fgetc(stream)) != EOF && character != '\n')
	{
		if (y >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		(*lineptr)[y++] = (char)character;
		if (charater == '\n')
		{
			break;
		}
	}
	(*lineptr)[y] = '\0';
	if (y == 0)
	{
		return (-1);
	}
}
	
