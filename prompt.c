#include "shell.h"

/**
 * prompt - shows the shell prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}

/**
 * print_error - shows an error according to the command and how many times
 *              the shell looped.
 * @input: User input.
 * @counter: Simple shell loop counter
 * @argv: name of the program
 * Return: Void.
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

