#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "simple_shell.h"

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
	size_t n = 0;
	char *line = NULL, **tokens;
	char *prmpt = "$ ";

	while (1)
	{
		write(STDOUT_FILENO, prmpt, _strlen(prmpt));	
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
			exit (0);
		}
	}
	return (0);
}
