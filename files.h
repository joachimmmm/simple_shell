#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS_LENGTH 10
#define BUFFER_SIZE 1024
int _putchar(char ch);
int main(int argc, char *argv[]);
void print_prompt(void);
void pidf(char *command, char *args[]);
void print_env(void);
int check_command_existence(const char *command, char *full_path);
extern char **environ;
int is_full_path(char *command);
size_t _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_getenv(const char *name);
char *_strdup(const char *source);
char *_strncpy(char *destination, const char *source, size_t num);
int _strncmp(const char *str1, const char *str2, size_t num);
void print_error(const char *program_name, int line, const char *command);
int atoi_func(const char *str);
void exit_func(char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
