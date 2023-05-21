#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"


/**
 * exec_cmd - this function will execute the commands entered
 *
 * Description: to execute the command, a forked process is created
 *	and depending the pid returned by fork() we execute the
 *	command in the chold process and wait for it in the parent process
 * @parsed_cmd: an array representing the command to exec along with args
 * Return: Nothing
 */

void exec_cmd(char **parsed_cmd, char **envp, char *line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(parsed_cmd[0], parsed_cmd, envp);

		/* The following will only be executed if execve failed */
		perror(parsed_cmd[0]);
		if (line)
		{
			free(line);
		}
		free(parsed_cmd);
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
