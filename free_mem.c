#include "shell.h"

/**
 * free_command_memory - frees all the memory allocated for command.
 * @command: the address of the command memory that should be freed.
 * Return: Nothing.
 */
void free_command_memory(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	free(command);
}

/**
 * free_and_exit - frees all the memory allocated and exits.
 * @command: the address of the command memory that should be freed
 * Return: Nothing.
 */
void free_and_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	free(command);
	exit(EXIT_FAILURE);
}
