#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>

ssize_t _getline(char **line, size_t *n, FILE *stream);

char *_strtok(char *str, char *delim);

char **split(char *str, char *delim);

char *_getenv(char **envp, char *var, unsigned int n);

void exec_cmd(char **parsed_cmd, char **envp, char *line);

void readline(char **line, size_t len);

char *cmd_stat(char *cmd, char **envp);

char *get_cmd_exec(char *cmd, char **envp);

void exit_shell(char **ctokens, char *line);


/* str_utils functions' prototype */
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

/* Other util functions' prototype */
ssize_t nconcat(int n, char **strcat, ...);
void print_error(char *argv, char *cmd);
void free_alloc(int n, char *alloc1, ...);
void handle_cmd(char **tokens, char **envp, char *cmd_exec, char *line);



#endif
