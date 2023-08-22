#include "shell.h"

int main(int argc, char **argv, char **envp) {
	char *input_buffer = NULL, **command_tokens = NULL;
	size_t buffer_size = 0;
	ssize_t chars_read = 0;
	int cycles = 0;
	(void)argc; // Unused argument

	while (1) {
		cycles++;
		show_prompt();
		signal(SIGINT, handle_ctrl_c);

		chars_read = getline(&input_buffer, &buffer_size, stdin);

		if (chars_read == EOF) {
			handle_eof(input_buffer);
		} else if (*input_buffer == '\n') {
			free(input_buffer);
		} else {
			input_buffer[chars_read - 1] = '\0'; // Remove trailing newline
			command_tokens = tokenize_input(input_buffer, " \0"); // Tokenize input
			free(input_buffer);

			if (compare_strings(command_tokens[0], "exit") == 0) {
				shell_exit(command_tokens);
			} else if (compare_strings(command_tokens[0], "cd") == 0) {
				change_directory(command_tokens[1]);
			} else {
				launch_child_process(command_tokens, argv[0], envp, cycles);
			}
		}

		input_buffer = NULL;
		buffer_size = 0;
	}

	if (chars_read == -1) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void show_prompt(void) {
	if (is_terminal(STDIN_FILENO)) {
		write(STDOUT_FILENO, "Simple_Shell>> ", 15);
	}
}

void handle_ctrl_c(int signal) {
	(void)signal; // Unused argument
	write(STDOUT_FILENO, "\nSimple_Shell>> ", 16);
}

void handle_eof(char *buffer) {
	if (buffer) {
		free(buffer);
	}

	if (is_terminal(STDIN_FILENO)) {
		write(STDOUT_FILENO, "\n", 1);
	}

	free(buffer);
	exit(EXIT_SUCCESS);
}

void shell_exit(char **command) {
	int status = 0;

	if (command[1] == NULL) {
		free_tokens(command);
		exit(EXIT_SUCCESS);
	}

	status = convert_to_integer(command[1]);
	free_tokens(command);
	exit(status);
}

