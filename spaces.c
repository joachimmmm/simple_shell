#include "files.h"
/**
 * trimString - trims trings
 * @str: pointer to str
 * Return: trimmed string: trimmedStr
*/

char *trimString(char *str)
{
size_t len = _strlen(str);
size_t start = 0;
size_t end = len - 1;
size_t trimmedLen;
char *trimmedStr;

while (start < len && _isspace(str[start]))
{
start++;
}

while (end > start && _isspace(str[end]))
{
end--;
}

trimmedLen = end - start + 1;

trimmedStr = malloc(trimmedLen + 1);

if (trimmedStr == NULL)
{
return (NULL);
}
_strncpy(trimmedStr, &str[start], trimmedLen);
trimmedStr[trimmedLen] = '\0';

return (trimmedStr);
}


/**
 * _isspace - Identifies if c is a space
 * @c: char to check
 * Return: 0 | 1
*/

int _isspace(int c)
{
return (c == ' ' || c == '\t' || c == '\n');
}
