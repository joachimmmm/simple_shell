#include "files.h"
/**
 * _putchar - puts char to stdout.
 * @ch: the char
 * Return: 1(succesful).
 */
int _putchar(char ch)
{
	int result;

	result = write(1, &ch, 1);
	return (result);
}
