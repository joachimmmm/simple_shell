#include "files.h"
/**
 * display_prompt - prints the shell prompt
 * Return: void
 */

void display_prompt()
{
	printf("($) ");
	fflush(stdout);
}

/**
 * read_input - reads the user input
 * @input: the inpu
 * Return: void
 */
void read_input(char *input)
{
	fgets(input, MAX_INPUT_LENGTH, stdin);
	input[strcspn(input, "\n")] = '\0';
}