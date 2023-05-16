#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - implimentation of the getline function
 *
 * @line: holds the line read from the stream
 * @n: the size of line
 * @stream: the source from where to read
 * Return: number of read bytes and -1 if error
 */

ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	ssize_t r;

	r = read(fileno(stream), buffer, BUFFER_SIZE);
	if (r <= 0)
	{
		return (-1);
	}
	else if (buffer[r - 1] == '\n')
	{
		*n = r;
		*line = realloc(*line, sizeof(char) * r);
		if (*line == NULL)
		{
			return (-1);
		}
		_strncpy(*line, buffer, r);
		(*line)[r - 1] = '\0';
		return (r - 1);
	}
	else
	{
		while (r != -1)
		{
			*n += r;
			*line = realloc(*line, sizeof(char) * (*n));
			if (*line == NULL)
			{
				return (-1);
			}
			*line = _strncpy(*line + (*n - r), buffer, r);
			if (buffer[r - 1] == '\n')
			{
				break;
			}
			r = read(fileno(stream), buffer, BUFFER_SIZE);
		}

	}
	return (*n - 1);
}

