#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS_LENGTH 10
int main();
void print_prompt(void);
void pidf(char *command, char *args[]);
void command_executor(char *command, char *args[]);
void print_env(void);
int check_command_existence(const char *command, char *full_path);
extern char **environ;
#endif
