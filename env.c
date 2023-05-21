#include "files.h"

/**
 * _getenv - get an env var
 * @name: name of the var
 * Return: returns a pointer to the value
 * part of the environment variable or NULL
 */

char *_getenv(const char *name)
{
size_t name_len;
char **env;

if (name == NULL || environ == NULL)
return (NULL);

name_len = _strlen(name);

for (env = environ; *env != NULL; env++)
{
if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
return (*env + name_len + 1);
}

return (NULL);
}
