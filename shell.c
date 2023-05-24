#include "files.h"
/**
 * print_prompt - prints the prompt
 * Return: 0
 */

void print_prompt(void)
{
	const char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	fflush(stdout);
}

/**
 * print_env - print the current environment
 *
 * Return: void
 */

void print_env(void)
{
	char **env = environ;
	const char *line;
	size_t length;

	while (*env != NULL)
	{
		line = *env;
		length = _strlen(line);
		write(STDOUT_FILENO, line, length);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * check_command_existence - check if the command exists
 * in the PATH and return its full path
 * @command: command to check
 * @full_path: pointer to store the full path of the command
 * Return: 1 if command exists, 0 otherwise
 */
int check_command_existence(const char *command, char *full_path)
{
	char *path = _getenv("PATH");
	char *dir;
	char *path_copy = _strdup(path);
	size_t command_len = _strlen(command);

	if (command[0] == '~' || command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			_strncpy(full_path, command, command_len);
			return (1);
		}
	}
	else
	{
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			size_t dir_len = _strlen(dir);
			size_t full_path_len = dir_len + 1 + command_len;

			_strncpy(full_path, dir, dir_len);
			full_path[dir_len] = '/';
			_strncpy(full_path + dir_len + 1, command, command_len + 1);
			full_path[full_path_len] = '\0';

			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (1);
			}

			dir = strtok(NULL, ":");
		}
	free(path_copy);
	}
	return (0);
}

/**
 * is_full_path - adds a node to the start of the list
 * @command: user input
 *
 * Return: 1 if true 0 if not full path
 */
int is_full_path(char *command)
{
	if (command[0] == '/' || command[0] == '~')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
