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
	char *line = NULL, **tokens, *cmd_exec, *prmpt = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
		{
			write(STDOUT_FILENO, prmpt, _strlen(prmpt));
		}
		line = NULL;
		readline(&line, n);
		tokens = split(line, " ");
		exit_shell(tokens, line);

		cmd_exec = get_cmd_exec(tokens[0], envp);
		if (cmd_exec == NULL)
		{
			print_error(argv[0], tokens[0]);
			free(tokens);
			free(line);
			continue;
		}
		else
		{
			handle_cmd(tokens, envp, cmd_exec, line);
		}
		if (isatty(STDIN_FILENO) == 0)
		{
			exit(0);
		}
	}
	return (0);
}
