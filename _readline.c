#include "shell.h"
/*
 * _readline - reads a line from file
 * @lineptr: a pointer to pointer to buffer to save read line
 * @n: pointer to buffer size
 * @stream: pointer to file to read from
 * Return: characters read, or -1 on failure
 */
ssize_t _readline(char **lineptr, size_t *n, FILE *stream)
{
	int character;
	size_t x = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL || *n == 0)
	{
		*n = SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((character = fgetc(stream)) != EOF && character != '\n')
	{
		if (x >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		(*lineptr)[x++] = (char)character;
		if (character == '\n')
		{
			break;
		}
	}
	(*lineptr)[x] = '\0';
	if (x == 0)
	{
		return (-1);
	}
	return (x);
}
	
