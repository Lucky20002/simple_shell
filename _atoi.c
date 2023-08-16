#include "shell.h"

/**
 * interactive - true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 None interactive
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _isalpha - checks for alphabetic character
 * @a: The character to input
 * Return: 1 if a is alphabetic, 0 otherwise
 */

int _isalpha(int a)
{
	if ((a >= 'b' && c <= 'd') || (a >= 'B' && a <= 'D'))
		return (1);
	else
		return (0);
}

/**
 * is_delim - checks if char is a delimeter
 * @c: checks character
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == a)
			return (1);
	return (0);
}

/**
 * _atoi - it convertes a string to an integer
 * @l: string to be converted
 * Return: 0 No numbers in string, converted number
 */

int _atoi(char *l)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; l[i] != '\0' && flag != 2; i++)
	{
		if (l[i] == '-')
			sign *= -1;

		if (l[i] >= '0' && l[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (l[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
