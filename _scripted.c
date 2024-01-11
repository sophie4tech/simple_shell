#include "shell.h"
/**
 * non_interactive - runs the command from script
 */
void non_interactive(void)
{
	char *input;

	while (1)
	{
		input = get_input();
		handle_input(input);
		free(input);
	}
}
