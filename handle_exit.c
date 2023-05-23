#include <stdlib.h>
#include "simple_shell.h"

/**
 * exit_shell - a function that handle exit command
 *
 * @ctokens: an array of cmd tokens
 * @line: the lines of commands entered in the shell
 * return: Nothing
 */
void exit_shell(char **ctokens, char *line)
{
	int status;

	if (ctokens[1] == NULL)
	{
		free(ctokens);
		free(line);
		exit(0);
	}
	else
	{
		status = atoi(ctokens[1]);
		free(ctokens);
		free(line);
		exit(status);
	}
}
