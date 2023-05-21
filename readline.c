#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"


/**
 * readline - a wrapper function for _getline function
 *
 * @line: a buffer that holds the read line
 * @len: a variable that holds the length of the line
 * Return: Nothing
 */

void readline(char **line, size_t len)
{
	if (_getline(line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
}
