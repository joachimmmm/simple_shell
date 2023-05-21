#include "files.h"
/**
 * _strlen - return the length of str
 * @str: string
 *
 * Return: length
 */
size_t _strlen(const char *str)
{
const char *s = str;
while (*s)
++s;
return (s - str);
}
/**
 * _strcmp -  compares two strings
 * @str1: string 1
 * @str2: string 2
 *
 * Return: 0 if equal
 */
int _strcmp(const char *str1, const char *str2)
{
while (*str1 && (*str1 == *str2))
{
str1++;
str2++;
}
return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strncpy - copies str
 * @destination: the destination
 * @source: the source
 * @num: size of str
 * Return: destination
 */
char *_strncpy(char *destination, const char *source, size_t num)
{
char *dest = destination;

while (num > 0 && *source != '\0')
{
*dest++ = *source++;
num--;
}

while (num > 0)
{
*dest++ = '\0';
num--;
}
return (destination);
}

/**
 * _strdup - duplicates string
 * @source: str source
 *
 * Return: duplicate
 */
char *_strdup(const char *source)
{
size_t length = 0;
const char *temp = source;
char *duplicate, *dest;

while (*temp != '\0')
{
length++;
temp++;
}

duplicate = (char *)malloc((length + 1) * sizeof(char));
if (duplicate == NULL)
{
return (NULL);
}

dest = duplicate;
while (*source != '\0')
{
*dest++ = *source++;
}
*dest = '\0';

return (duplicate);
}

/**
 * _strncmp - compares at most num characters
 * of two strings
 * @str1: Pointer to the first string to be compared
 * @str2: Pointer to the second string to be compared
 * @num: Maximum number of characters to compare
 *
 *
 * Return: it returns:
 *   - Less than 0: str1 is less than str2.
 *   - 0: str1 is equal to str2.
 *   - Greater than 0: str1 is greater than str2.
 */

int _strncmp(const char *str1, const char *str2, size_t num)
{
while (num > 0)
{
if (*str1 != *str2)
return (*str1 - *str2);

if (*str1 == '\0')
return (0);

str1++;
str2++;
num--;
}

return (0);
}
