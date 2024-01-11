#include "shell.h"
/**
 * exit_shell - exits the shell
 * @args: an array of arguments passed
 * Return: none
 */
void quit_shell(char **args)
{
	(void)args;
	exit(0);
}

/**
 * display_environ - prints the environment variables
 * @args: an array of arguments passed to the function
 * Return: none
 */
void display_environ(char **args)
{
	char **env;
	(void)args;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

/**
 * change_dir - changes the current working directory
 * @args: an array of arguments passed to the function
 * Returns: none
 */
void change_dir(char **args)
{
	char *new_dir_ = NULL;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		char *home_dir = getenv("HOME");

		if (home_dir != NULL)
			new_dir_ = strdup(home_dir);
		else
		{
			return;
		}
	}
	else if (strcmp(args[1], "~") == 0)
	{
		char *prev_dir = getenv("OLDPWD");
		
		if (prev_dir != NULL)
			new_dir_ = strdup(prev_dir);
		else
			return;
	}
	else
		new_dir_ = strdup(args[1]);
	if (chdir(new_dir_) == -1)
	{
		perror("Error: could not change the requested directory");
	}
	else
	{
		char *current_dir = getcwd(NULL, 0);

		if (current_dir != NULL)
		{
			setenv("PWD", current_dir, 1);
			setenv("OLDPWD", new_dir_, 1);
			free(current_dir);
		}
	}
	free(new_dir_);
}

/**
 * struct Built_In_Command - lists of built-in commands
 * @quit_shell: exit the shell
 * @display_environ: print environment
 * @change_dir: change directory
 */
struct Built_In_Command b_i_c[] = {
	{"exit", quit_shell},
	{"env", display_environ},
	{"cd", change_dir},
	{NULL, NULL}
};

