#include "files.h"
/**
 * print_error - Print error message in the specified format
 * @program_name: The name of the program
 * @line: The line number associated with the error
 * @command: The command that triggered the error
 * Return: void
 */
void print_error(const char *program_name, int line, const char *command)
{
	const char *error_message = ": not found\n";
	size_t program_name_length = _strlen(program_name);
	size_t error_message_length = _strlen(error_message);
	char line_number_str[16];
	int line_number_digits = 0;
	int temp = line;
	char *p;
	const char *file_name, *ls;

	while (temp != 0)
	{
		line_number_digits++;
		temp /= 10;
	}
	p = line_number_str + line_number_digits;
	*p = '\0';
	while (line_number_digits > 0)
	{
		*--p = '0' + (line % 10);
		line /= 10;
		line_number_digits--;
	}
	file_name = command;
	while (*command != '\0')
	{
		if (*command == '/')
			ls = command;
		command++;
	}
	if (ls != NULL)
		file_name = ls + 1;

	write(STDERR_FILENO, program_name, program_name_length);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line_number_str, _strlen(line_number_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "ls: cannot access '", 19);
	write(STDERR_FILENO, file_name, _strlen(file_name));
	write(STDERR_FILENO, "'", 1);
	write(STDERR_FILENO, error_message, error_message_length);
}
