#include "simple_shell.h"

/**
 * _strcpy - a function that copies the string pointed to by src, including
 *	the null byte (\0), to the buffer pointed to by dest
 *
 * @src: the source string to be copied
 * @dest: the destination buffer
 * Return: a pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strncpy - a function that copies n bytes from @src to @dest
 *
 * @src: source string
 * @dest: destination string
 * @n: the number of bytes to copy
 * Return: a pointer to the resulted string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strcmp - a function that compares tow strings
 *
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 * Return: an int less than, equal, or greater than 0 if, respectively,
 *	@s1 is found less, equal, or greater than @s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strlen - a function that computes the length of a string
 *
 * @s: a pointer the string whose length would be computed
 * Return:  the length of the string passed
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
