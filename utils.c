#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "simple_shell.h"

/**
 * nconcat - a variadic function that concatenate any number of strings
 *
 * @n: number of strings to concatenate
 * @strcat: a pointer to the place where to put the concatenated string
 * Return: 0 (on success) and -1 (on failure)
 */

ssize_t nconcat(int n, char **strcat, ...)
{
	va_list al;
	char *str;
	int i, j = 0, len = 0, cpyat = 0;

	va_start(al, strcat);
	for (i = 0; i < n; i++)
	{
		len += _strlen(va_arg(al, char*));
	}

	va_start(al, strcat);
	*strcat = malloc(sizeof(char) * (len + 1));
	if (*strcat == NULL)
	{
		return (-1);
	}
	for (i = 0; i < n; i++)
	{
		str = va_arg(al, char *);
		if (str == NULL)
		{
			continue;
		}
		while (str[j])
		{
			(*strcat)[cpyat] = str[j];
			cpyat++;
			j++;
		}
		j = 0;
	}
	(*strcat)[len] = '\0';
	return (0);
}


