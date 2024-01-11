#include "shell.h"
/**
 * access_stream - read a line of text from stream file
 * @file: file stream to access
 * Return: dynamical allocated string or NULL if its end of file
 */
char *access_stream(FILE *file)
{
	int bufsize = 1024;
	int x = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr,"buffer allocation error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = fgetc(file); 
		if (character == EOF)
		{
			free(line);
			return (NULL);
		}
		else if (character == '\n')
		{
			line[x] = '\0';
			return (line);
		}
		else
		{
			line[x] = character;
		}
		x++;
		if (x >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "buffer reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
