#include "shell.h"
/**
 * main - entry point
 * Return: 0 on success, -1 on error
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		_interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
