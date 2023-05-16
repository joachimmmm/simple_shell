#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX_INPUT_LENGTH 100

void display_prompt();

void read_input(char *input);

int main();

#endif
