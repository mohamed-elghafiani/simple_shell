#include <string.h>
#include "simple_shell.h"

/**
 * get_path - a function that extract the PATH variables
 *
 * Return: a string of the PATH variables
 */

char *_getenv(char **envp, char *var, unsigned int n)
{
	char *path = NULL;

	while (*envp)
	{
		if (strncmp(*envp, var, n) == 0)
		{
			path = *envp + n;
			break;
		}
		envp++;
	}
	return (path);
}

