#include "files.h"

/**
 * main - entry point
 *
 * Return: 0 (success)
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[2];
	char *env[] = {NULL};

	while (1)
	{
		display_prompt();
		read_input(input);
		args[0] = input;
		args[1] = NULL;
		execve(input, args, env);
		perror("execve");
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
	}
	return (0);
}
