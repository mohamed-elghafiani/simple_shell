#include <stdlib.h>
#include "simple_shell.h"



/**
 * get_num_delim - a function that calculate the number
 *	of occurance of delim in str
 *
 * @str: a string
 * @delim: a delimeter
 * Return: the number of occurence of @delim
 */

int get_num_delim(char *str, char *delim)
{
	int i = 0, ndelim = 0;

	while (str[i])
	{
		if (str[i] == delim[0])
		{
			ndelim++;
		}
		i++;
	}
	return (ndelim);
}


/**
 * split - a function that splits a string @str into individual tokens
 *	delimeted by @delim
 *
 * @str: a string
 * @delim: a delimeter
 * Return: a list of tokens
 */

char **split(char *str, char *delim)
{
	char *start, *end;
	unsigned int i = 0, ndelim = 0, n = 0;
	char **splt;

	ndelim = get_num_delim(str, delim);
	splt = malloc(sizeof(char *) * (ndelim + 2));
	i = 0;
	start = str;
	end = str;
	while (str[i])
	{
		if (str[i] == delim[0])
		{
			str[i] = '\0';
			splt[n] = start;
			if (str[i + 1])
			{
				start = &str[i + 1];
				end = &str[i + 1];
				n++;
				i++;
			}
			else
			{
				start = NULL;
				break;
			}
			continue;
		}
		end++;
		i++;
	}
	if (start)
	{
		splt[n] = start;
	}
	splt[n + 1] = NULL;

	return (splt);
}
