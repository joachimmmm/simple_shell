#include "files.h"
/**
 * print_prompt - prints the prompt
 * Return: 0
 */

void print_prompt(void)
{
	printf("($) ");
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

	while (*env != NULL)
	{
		printf("%s\n", *env);
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
char *path = getenv("PATH");
char *dir;
char *path_copy = strdup(path);

dir = strtok(path_copy, ":");
while (dir != NULL)
{
sprintf(full_path, "%s/%s", dir, command);

if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (1);
}
dir = strtok(NULL, ":");
}
free(path_copy);
return (0);
}
