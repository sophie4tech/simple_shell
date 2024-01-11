#include "shell.h"
/**
 * get_working_dir - retrieves current working directory path
 * Return: dynamically allocated string with the current working
 * directory path, or Null on error
 */
char *get_working_dir(void)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("Error fetching current directory");
		exit(EXIT_FAILURE);
	}
	return (cwd);
}

/**
 * show_prompt - display shell prompt in current working dir
 */
void show_prompt(void)
{
	char *cwd = get_working_dir();

	printf("sophie@ubuntu:~%s_$ ", cwd);
	free(cwd);
}
