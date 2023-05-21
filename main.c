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
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = command;
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
	char *command = NULL, *args[MAX_ARGS_LENGTH], *new_command, full_path[256];
	size_t command_length;
	int index, interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive_mode)
			print_prompt();
		if (getline(&command, &command_length, stdin) == -1)
			break;
		command_length = _strlen(command);
		if (command[command_length - 1] == '\n')
			command[command_length - 1] = '\0';
		new_command = strtok(command, " ");
		if (new_command == NULL)
			continue;
		args[0] = new_command;
		for (index = 1; index < MAX_COMMAND_LENGTH - 1; index++)
		{
			args[index] = strtok(NULL, " ");
			if (args[index] == NULL)
				break;
		}
		args[index] = NULL;
		if (_strcmp(command, "exit") == 0)
			break;
		else if (_strcmp(command, "env") == 0)
			print_env();
		else if (is_full_path(command))
			pidf(command, args);
		else if (check_command_existence(new_command, full_path))
			pidf(full_path, args);
		else
			perror("./shell");
	}
	return (0);
}
