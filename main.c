#include "files.h"
#include <sys/wait.h>
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
	pid_t pid;

	while (1)
	{
		display_prompt();
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		read_input(input);
		pid  = fork();
		if (pid == -1)
		{
			perror("fork");
			return (0);
		}
		else if (pid == 0)
		{
			display_prompt();
			read_input(input);
			args[0] = input;
			args[1] = NULL;
			execve(input, args, env);
			perror("execve");
		}
		else
		{
			wait(NULL);
			display_prompt();
			read_input(input);
		}
	}
	return (0);
}
