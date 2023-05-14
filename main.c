#include "files.h"

/**
 * main - entry point
 *
 * Return: 0 (success)
 */

int main()
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		display_prompt();
		read_input(input);
	}
	return 0;
}
