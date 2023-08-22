.\" Manpage for simple_shell
.\"
.\" Contact khongelani8@gmail.com to correct errors or typos
.\"
simple_shell  "22-08-2023"  "simple_shell"

.SH NAME
\fBsimple_shell\fR - A Simple UNIX shell simulator for handling commands

.SH SYNOPSIS
\fB./Hell_Shell\fR [OPTIONS] [COMMAND_STRING | file]
ALX school

.SH DESCRIPTION
This program simulates a command interpreter similar to Unix and GNU/Linux with basic commands.
Users inte6ract with this \fBsimple_shell\fR through a terminal emulator and executable shell scripts.
This simple_shell is not an exact imitation of the original Unix Shell and does not cover all original instructions.

.SH OVERVIEW
This program is designed to complete the Holberton School project 0x16 - C Simple Shell.
A comprehensive documentation is available in the README.md file.

.SH INVOCATION
.br
.\&
.RS
\&> ./Hell_Shell

The prompt 'Hell_Shell>> ' will appear on the terminal. Enter commands after the prompt.
Multiple commands using ';' '&&' '||' specifiers are not supported. Execute commands by pressing 'ENTER'.

.SH FEATURES
* Displays a prompt and waits for user input ending with a new line (ENTER key).
* Prompt is displayed after executing each command.
* Entering 'exit' terminates the shell with status 0.
* 'exit [status]' terminates the shell with the input status (0 to 255).
* Pressing Ctrl+D (end of file) stops the program.
* Handles command lines with arguments and pathways.
* Does not quit on Ctrl+C (Ctrl+Z).
* Prints the current environment with 'env' command.
* Executes common shell commands (ls, grep, find, pwd, rm, cp, mv, exit, env, history, etc.) with arguments.
* Displays error message and prompt if executable is not found.
* Supports comments using '#'.
* Does NOT support wildcard characters (e.g., ls *.dat), pipes (|), logical operators (&&, ||), or command separators (;).

.SH EXAMPLES - BUILDING COMMANDS
Here are some example commands and their respective outputs:

\fBls [OPTIONS..]\fR - Lists files and directories in the current directory.
Hell_Shell>> ls
AUTHORS  Hell_Shell  README.md  auxiliar_functions.c  create_child.c  execute.c  free_mem.c  generateAUTHORS  man_1_simple_shell  shell.h  shell_init.c  tokening.c

\fBecho [OPTIONS..] string..\fR - Displays a line of text.
Hell_Shell>> echo Hello World
Hello World

\fBpwd [OPTIONS..]\fR - Prints the working directory.
Hell_Shell>> pwd
/home/vagrant/alx/simple_shell

Ctrl + D - Quits the program.
Hell_Shell>> ^D
vagrant@vagrant-ubuntu-trusty-64:~/alx/simple_shell$

\fBexit\fR - Exits the shell.
Hell_Shell>> exit
vagrant@vagrant-ubuntu-trusty-64:~/alx/simple_shell$

.SH BUGS
No known bugs at this time.

.SH AUTHOR(S)
	Shabangu Lucky - luckyshabangu2000@gmail.com

	Kholophe Rabelani - khongelani8@gmail.com
