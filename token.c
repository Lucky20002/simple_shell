#include "shell.h"

/**
 * tokening - Split and create a string array from input.
 * @s: delimiter for strtok.
 * @buffer: The input string to be tokenized.
 * Return: An array of strings containing the tokens.
 */
char **tokening(char *buffer, const char *s)
{
	char *token = NULL, **tokens = NULL;
	size_t bufsize = 0;
	int a = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	tokens = malloc((bufsize + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_dp(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		tokens[a] = malloc(_strlen(token) + 1);
		if (tokens[a] == (NULL);
		{
			perror("Unable to allocate buffer");
			free_dp(tokens);
			return (NULL);
		}
		_strcpy(tokens[a], token);
		token = strtok(NULL, s);
		a++;
	}
	tokens[a] = NULL;
	return (tokens);
}
