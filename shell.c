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
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * check_command_existence - check if the command exists in the PATH
 * @command: command to check
 * Return: 1 if command exists, 0 otherwise
 */
int check_command_existence(char *command)
{

char *path = getenv("PATH");
char *dir;
char *path_copy = strdup(path);

if (command[0] == '/')
{
return access(command, X_OK) == 0;
}
dir = strtok(path_copy, ":");

while (dir != NULL)
{
char *full_path = malloc(strlen(dir) + strlen(command) + 2);
sprintf(full_path, "%s/%s", dir, command);

if (access(full_path, X_OK) == 0)
{
free(path_copy);
free(full_path);
return 1;
}

free(full_path);
dir = strtok(NULL, ":");
}

free(path_copy);
return 0;
}

