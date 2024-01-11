#include "shell.h"
/**
 * handle_input - process user input
 * @input: users input
 * Return: nothing
 */
void handle_input(char *input)
{
	char *exec_path;
	char **tokens = handle_command(input);
	int x, y;

	if (tokens[0] != NULL)
	{
		int x = 0;

		while (b_i_c[x].name != NULL)
		{
			if (strcmp(tokens[0], b_i_c[x].name) == 0)
			{
				b_i_c[x].function(tokens);
				for (y = 0; tokens[y] != NULL; y++)
				{
					free(tokens[y]);
				}
				free(tokens);
				return;
			}
			x++;
		}
	}
	exec_path = search_exec(tokens[0]);
	if (exec_path != NULL)
	{
		execve_command(exec_path, tokens);
		free(exec_path);
	}
	else
	{
		printf("%s: No such file or directory\n", tokens[0]);
	}
	for (x = 0; tokens[x] != NULL; x++)
	{
		free(tokens[x]);
	}
	free(tokens[x]);
}
