#include "files.h"
/**
 * main - entry point
 *
 * Return: 0 (success)
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];
size_t command_length;
char *args[2];
while (1)
{
printf("($) ");
fgets(command, sizeof(command), stdin);
command_length = strlen(command);
if (command[command_length - 1] == '\n')
command[command_length - 1] = '\0';
if (strcmp(command, "exit") == 0)
{
break;
}
else
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
}
return (0);
}
