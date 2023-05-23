#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include "simple_shell.h"

/**
 * get_cmd_exec - a function that checks the status of the entered command
 *
 * @cmd: command entered
 * @envp: the environment variable
 * Return: the path of the command to execute if it exists and NULL otherwise
 */

char *get_cmd_exec(char *cmd, char **envp)
{
	int i = 0;
	char *path, *env, *env_cpy, **parsed_env;
	struct stat cstat;

	if (*cmd == '/')
	{
		if (stat(cmd, &cstat) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	else
	{
		env = _getenv(envp, "PATH=", 5);
		env_cpy = malloc(_strlen(env) + 1);
		if (env_cpy == NULL)
		{
			return (NULL);
		}
		env_cpy = _strcpy(env_cpy, env);

		parsed_env = split(env_cpy, ":");
		while (parsed_env[i])
		{
			nconcat(3, &path, parsed_env[i], "/", cmd);
			if (stat(path, &cstat) == 0)
			{
				free(parsed_env);
				free(env_cpy);
				return (path);
			}
			free(path);
			i++;
		}
	}
	free(env_cpy);
	free(parsed_env);
	return (NULL);
}
