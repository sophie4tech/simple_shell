#include "shell.h"
/**
 * _interactive - allows user to interact with shell until exit
 */
void _interactive(void)
{
	char *input;

	while (1)
	{
		show_prompt();
		input = get_input();
		handle_input(input);
		free(input);
	}
}
