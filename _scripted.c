#include "shell.h"
/**
 * _scripted - runs the command from script
 */
void _scripted(void)
{
	char *input;

	while (1)
	{
		input = get_input();
		handle_input(input);
		free(input);
	}
}
