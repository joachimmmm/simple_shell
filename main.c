#include "files.h"
/**
 * pidf - id function
 * @command: input to shell.
 * @args: arr of arguments
 * Return: void
 */
void pidf(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = command;
		execve(command, args, NULL);
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * main - entry point
 * Return: 0 (success)
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH], *args[2], *new_command;
	size_t command_length;
	int index;

	while (1)
	{
		print_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command_length = strlen(command);
		if (command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}
		new_command = strtok(command, " ");
		if (new_command == NULL)
		{
			continue;
		}
		args[0] = new_command;
		for (index = 1; index < MAX_COMMAND_LENGTH - 1; index++)
		{
			args[index] = strtok(NULL, " ");
			if (args[index] == NULL)
				break;
		}
		args[index] = NULL;
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else
		{
			pidf(command, args);
		}
	}
	return (0);
}
