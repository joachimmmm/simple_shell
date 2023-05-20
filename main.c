#include "files.h"
/**
 * input_reader - reads input
 * @command: input
 * @command_length: length of input
 * Return: 1
 */
int input_reader(char *command, size_t command_length)
{
	if (fgets(command, sizeof(command), stdin) == NULL)
	{
		printf("\n");
		return (0);
	}
	command_length = strlen(command);
	if (command[command_length - 1] == '\n')
	{
		command[command_length - 1] = '\0';
	}
	return (1);
}

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
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[3] = command;
		execve(command, args, NULL);
		perror("./shell");
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
	char command[MAX_COMMAND_LENGTH], *args[MAX_ARGS_LENGTH],
	*new_command, full_path[256];
	int index;

	while (1)
	{
		print_prompt();
		if (!input_reader(command, sizeof(command)))
			break;
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
		else if (strcmp(command, "env") == 0)
		{
			print_env();
		}
		else if (check_command_existence(new_command, full_path))
		{
			pidf(full_path, args);
		}
		else
		{
			perror("./shell");
		}
	}
	return (0);
}
