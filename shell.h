#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <stddef.h>
#include <sys/stat.h>

/* Macros */
#define MAX_INPUT_SIZE 1024
#define SIZE 128
extern char **environ;

/* Structures */
/**
 * struct Built_In_Command - represent built-in command in shell
 * @name: The name of the command
 * @function: A pointer to the command function
 */

struct Built_In_Command
{
	char *name;
	void (*function)(char **args);
};

extern struct Built_In_Command b_i_c[];

/* functions */
void show_prompt(void);
char *get_input(void);
void execve_command(char *command, char *args[]);
char *search_exec(char *command);
char **handle_command(char *input);
void handle_input(char *input);
char *get_working_dir();
void comsep(char *args[]);
void _interactive(void);
char *access_stream(FILE *file);
void non_interactive(void);
ssize_t _readline(char **lineptr, size_t *n, FILE *stream);
char *_findchar(char *s, char c);
char *tokstr(char *str, char *delim);

/* Built-in functions */
void quit_shell(char **args);
void change_dir(char **args);
void display_environ(char **args);

#endif /* SHELL_H */
