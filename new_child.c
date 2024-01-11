#include "shell.h"
/**
 * execve_command - carry out a given command with it arguments
 * @command:executable comamand
 * @args: array of arguments to pass to the command
 */
void execve_command(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error while forking process");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execv(command, args) == -1)
		{
			perror("Error in command execution");
			exit(EXIT_FAILURE);
		}
	}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
}
