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

int main(int __attribute__((unused)) argc, char **argv, char **envp)
{
	size_t n = 0;
	char *line = NULL, **tokens, *cmd;
	char *prmpt = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
		{
			write(STDOUT_FILENO, prmpt, _strlen(prmpt));
		}
		line = NULL;
		readline(&line, n);

		tokens = split(line, " ");
		
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(tokens);
			free(line);
			exit(0);
		}
		cmd = get_cmd_exec(tokens[0], envp);
		if (cmd == NULL)
		{
			free(tokens);
			free(line);
			perror(argv[0]);
			continue;
		}
		else
		{
			if (*tokens[0] == '/')
			{
				exec_cmd(tokens, envp, line);
				free(line);
			}
			else
			{
				tokens[0] = realloc(tokens[0], _strlen(cmd) + 1);
				if (tokens[0] == NULL)
				{
					perror("realloc");
				}
				tokens[0] = _strcpy(tokens[0], cmd);
				exec_cmd(tokens, envp, line);
				free(tokens[0]);
				free(cmd);
			}
		}
		free(tokens);
		if (isatty(STDIN_FILENO) == 0)
		{
			exit(0);
		}
	}
	return (0);
}
