#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>

ssize_t _getline(char **line, size_t *n, FILE *stream);

char *_strtok(char *str, char *delim);

char **split(char *str, char *delim);

char *_getenv(char **envp, char *var, unsigned int n);

void exec_cmd(char **parsed_cmd, char **envp);

/* str_utils functions' prototype */
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
