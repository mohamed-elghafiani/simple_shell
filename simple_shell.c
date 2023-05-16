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
	int status;
	size_t n = 0;
	char *line = NULL, **tokens;
	char *prmpt = "(cisfun)$ ";
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, prmpt, _strlen(prmpt));
		line = NULL;	
		_getline(&line, &n, stdin);

		tokens = split(line, " ");
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(tokens);
			free(line);
			exit(0);
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				execve(tokens[0], tokens, envp);

				/* The following will only be executed if execve failed */
				perror(tokens[0]);
				free(line);
				free(tokens);
				exit(0);
			}
			else if (pid > 0)
			{
				wait(&status);
			}
			else
			{
				perror("fork");
			}
		}

		free(tokens);
		free(line);
	}
	return (0);
}
