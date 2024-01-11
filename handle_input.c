#include "shell.h"
/**
 * handle_command - split command string into tokens
 * @inpout: command string to handle
 * Return: an array of dynamically allocated strings
 * representing tokens of command, or NULL on error
 */
char **handle_command(char *input)
{
	int tok_count = 0;
	char *token;
	char **tokens = (char **)malloc(MAX_INPUT_SIZE *sizeof(char *));

	if (tokens == NULL)
	{
		perror("Error reserving memory for tokens");
		exit(EXIT_FAILURE);
	}
	token =tokstr(input, "\n");

	while (token != NULL)
	{
		tokens[tok_count] = strdup(token);
		if (tokens[tok_count] == NULL)
		{
			perror("Error reserving memory for tokens");
			exit(EXIT_FAILURE);
		}
		tok_count++;
		token = tokstr(NULL, "\n");
	}
	tokens[tok_count]= NULL;
	return (tokens);
}
