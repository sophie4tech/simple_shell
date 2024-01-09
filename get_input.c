#include "shell.h"
/**
 * get_input - reads a line of input from user
 * Return: dynamic allocated string from user input, or NULL as error
 */

char *get_input()
{
	char *input = NULL;
	size_t input_length = 0;

	if (_readline(&input, &input_length, stdin) == -1)
	{
		perror("Error getting user input");
		exit(EXIT_FAILURE);
	}

	if (feof(stdin))
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Error while getting input from stdin");
		exit(EXIT_FAILURE);
	}

	return (input);
}
