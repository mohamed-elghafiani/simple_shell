#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * print_environment - Prints the current environment variables.
 */
void print_environment(void)
{
	extern char **environ;
	char **env = environ;
	int fd = STDOUT_FILENO;

	while (*env != NULL)
	{
		write(fd, *env, strlen(*env));
		write(fd, "\n", 1);
		env++;
	}
}

/**
 * main - main function of the simple_shell
 *
 * @argc: number of arguments
 * @argv: arguments vector
 * @envp: environment variable list
 * Return: Always 0
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv, char **envp)
{
	#define MAX_INPUT_LENGTH 100
	#define MAX_TOKEN_LENGTH 20
	size_t n = 0;
	char *line = NULL, **tokens;
	char *prmpt = "$ ";
	char input[MAX_INPUT_LENGTH];
	char *token;
	int fd = STDOUT_FILENO;

	while (1)
	{
		write(STDOUT_FILENO, prmpt, strlen(prmpt));
		line = NULL;
		readline(&line, n);

		tokens = split(line, " ");
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(tokens);
			free(line);
			exit(0);
		}
		else
		{
			exec_cmd(tokens, envp, line);
		}
		free(tokens);
		free(line);
		if (isatty(STDIN_FILENO) == 0)
		{
			exit(0);
		}

		while (1)
		{
			write(fd, "$ ", 2);
			read(STDIN_FILENO, input, sizeof(input));

			input[strcspn(input, "\n")] = '\0';
			token = strtok(input, " ");

			if (token == NULL)
			{
				continue;
			}

			if (strcmp(token, "env") == 0)
			{
				print_environment();
			}
			else if (strcmp(token, "exit") == 0)
			{
				break;
			}
		}
	}

	return (0);
}

