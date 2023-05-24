#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "simple_shell.h"

/**
 * nconcat - a variadic function that concatenate any number of strings
 *
 * @n: number of strings to concatenate
 * @strcat: a pointer to the place where to put the concatenated string
 * Return: 0 (on success) and -1 (on failure)
 */

ssize_t nconcat(int n, char **strcat, ...)
{
	va_list al;
	char *str;
	int i, j = 0, len = 0, cpyat = 0;

	va_start(al, strcat);
	for (i = 0; i < n; i++)
	{
		len += _strlen(va_arg(al, char*));
	}

	va_start(al, strcat);
	*strcat = malloc(sizeof(char) * (len + 1));
	if (*strcat == NULL)
	{
		return (-1);
	}
	for (i = 0; i < n; i++)
	{
		str = va_arg(al, char *);
		if (str == NULL)
		{
			continue;
		}
		while (str[j])
		{
			(*strcat)[cpyat] = str[j];
			cpyat++;
			j++;
		}
		j = 0;
	}
	(*strcat)[len] = '\0';
	return (0);
}

/**
 * print_error - a function that get invoked when a cmd not found
 *
 * @argv: the name of the executable
 * @cmd: the command passed
 * Return: Nothing
 */
void print_error(char *argv, char *cmd)
{
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}


/**
 * free_alloc - a function that frees n allocated variables
 *
 * @n: the number of variables to free
 * @alloc1: the first variable to free
 * Return: Nothing
 */
void free_alloc(int n, char *alloc1, ...)
{
	va_list vp;
	int i = 0;

	va_start(vp, alloc1);
	for (i = 0; i < n; i++)
	{
		free(va_arg(vp, char *));
	}
}

/**
 * handle_cmd - a function that handles a cmd when it's valid
 *
 * @tokens: command passed parsed as tokens
 * @envp: environment parameter
 * @cmd_exec: command executable from path
 * @line: the full command line passed as a string
 * Return: Nothing
 */

void handle_cmd(char **tokens, char **envp, char *cmd_exec, char *line)
{
	if (*tokens[0] == '/')
	{
		exec_cmd(tokens, envp, line);
		free(tokens);
		free(line);
	}
	else
	{
		tokens[0] = realloc(tokens[0], _strlen(cmd_exec) + 1);
		if (tokens[0] == NULL)
		{
			perror("realloc");
		}
		tokens[0] = _strcpy(tokens[0], cmd_exec);
		exec_cmd(tokens, envp, line);
		free(tokens[0]);
		free(tokens);
		free(cmd_exec);
	}
}

