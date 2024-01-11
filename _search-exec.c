#include "shell.h"
/**
 * search_exec - searches the executable files for given command
 * @command: name of commnd to search
 * Return: full path of the executable file or NULL if not found
 */
char *search_exec(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = tokstr(path_copy, ":");

	if (access(command, F_OK | X_OK) == 0)
	{
		return (strdup(command));
	}
	while (path_token != NULL)
	{
		char exec_path[MAX_INPUT_SIZE];

		snprintf(exec_path, sizeof(exec_path),"%s/%s", path_token, command);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			free(path_copy);
			return (strdup(exec_path));
		}
		path_token = tokstr(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
