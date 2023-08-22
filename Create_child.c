#include "shell.h"

/**
 * execute - function that puts a command into action
 * @command: is a pointer to a tokenized command
 * @name: shell's name.
 * @env: The environmental variables' pointer
 * @cycles: The quantity of completed cycles.
 * Return: no response.
 */
void execute(char **command, char *name, char **env, int cycles)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_environment(env);

	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_and_exit(command);
		}
	}
	else
	{
		pathways = get_pathways_from_env(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_dp(pathways);
					free_and_exit(command);
				}
				return;
			}
		}
		print_command_not_found(name, cycles, command);
		free_dp(pathways);
	}
}

/**
 * print_environment - prints all environmental variables.
 * @env: The environmental variables' pointer.
 * Return: no response
 */
void print_environment(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * get_pathways_from_env - variables with the help of the function get_pathways_from_env.
 * @env: The pointer to environmental variables
 * Return: All command tokenized paths.
 */
char **get_pathways_from_env(char **env)
{
	char *path_value = NULL, **pathways = NULL;
	unsigned int i = 0;

	path_value = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(path_value, "PATH") == 0)
		{
			path_value = strtok(NULL, "\n");
			pathways = tokenizing(path_value, ":");
			return (pathways);
		}
		i++;
		path_value = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * print_command_not_found - A function that prints "command not found" message.
 * @name: shell's name
 * @cycles: Number of cycles.
 * @command: The pointer to a tokenized command.
 * Return: No response
 */
void print_command_not_found(char *name, int cycles, char **command)
{
	char c;

	c = cycles + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

