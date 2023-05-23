#include <string.h>
#include "simple_shell.h"

/**
 * _getenv - a function that extract the PATH variables
 *
 * @envp: the environment variable
 * @var: the variable we would like to retrieve from the environement
 * @n: the length of @var
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

