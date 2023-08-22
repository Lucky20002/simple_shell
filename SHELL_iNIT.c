#include "shell.h"

/**
 * main - Our shell's main function
 * @ac: The number of arguments entered.
 * @av: The array of arguments that have been input is pointed to by
 * @env: An array of environmental variables' pointer
 * Return: Always return a value of 0.
 *
 */

int main(int argc, char **argv, char **envp)

	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;
	int cycles = 0;

	(void)argc;
while (1)
	cycles++;
	displayPrompt();
	signal(SIGINT, handleCtrlC);

	chars_read = getline(&buffer, &buf_size, stdin);

	if (chars_read == EOF) {
		handleEndOfFile(buffer);
	} else if (*buffer == '\n') {
		free(buffer);
	} else {
		buffer[chars_read - 1] = '\0';
		command = tokenizeInput(buffer, " \0");
		free(buffer);

		if (areStringsEqual(command[0], "exit")) {
			exitShell(command);
		} else if (areStringsEqual(command[0], "cd")) {
			changeDirectory(command[1]);
		} else {
			launchChildProcess(command, argv[0], envp, cycles);
		}
	}

fflush(stdin);
buffer = NULL;
buf_size = 0;
}

if (chars_read == -1) {
	return EXIT_FAILURE;
}

return EXIT_SUCCESS;
}

void displayPrompt(void) {
	if (isTerminal(STDIN_FILENO)) {
		write(STDOUT_FILENO, "Hell_Shell>> ", 13);
	}
}

void handleCtrlC(int signal) {
	(void)signal;
	write(STDOUT_FILENO, "\nHell_Shell>> ", 14);
}

void handleEndOfFile(char *buffer) {
	if (buffer) {
		free(buffer);
	}

	if (isTerminal(STDIN_FILENO)) {
		write(STDOUT_FILENO, "\n", 1);
	}

	free(buffer);
	exit(EXIT_SUCCESS);
}

void exitShell(char **command) {
	int status = 0;

	if (command[1] == NULL) {
		freeCommandArray(command);
		exit(EXIT_SUCCESS);
	}

	status = convertStringToInteger(command[1]);
	freeCommandArray(command);
	exit(status);
}

