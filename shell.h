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
#define MAX_LENGTH_INPUT 1024
#define SIZE 128
extern char **environ;

/* Structures */
/**
 * struct Built_In_Command - typedef for struct
 * @name: The name of the command
 * @function: A pointer to the command function
 */

typedef struct Built_In_Command
{
	char *name;
	void (*function)(char **args);
};

extern struct Built_In_Command b_i_c[];

/* functions */
void show_prompt(void);
char *get_input(void);
void execve_command(char *command, char *args[]);
char *find_executable(char *command);
char **parse_command(char *input);
void handle_input(char *input);
char *get_current_directory();
void comsep(char *args[]);
void _interactive(void);
char *read_stream(FILE *file);
void _scripted(void);
ssize_t _readline(char **lineptr, size_t *n, FILE *stream);
char *_strchr(char *s, char c);
char *_strtok(char *str, char *delim);

/* Built-in functions */
void exit_shell(char **args);
void change_directory(char **args);
void print_environment(char **args);

#endif /* SHELL_H */
