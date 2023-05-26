#include "files.h"

/**
 * _getenv - get an env var
 * @name: name of the var
 * Return: returns a pointer to the value
 * part of the environment variable or NULL
 */

char *_getenv(const char *name)
{
size_t len;
char **env;

if (name == NULL || *environ == NULL)
return (NULL);

len = _strlen(name);

for (env = environ; *env != NULL; env++)
{
if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
return (*env + len + 1);
}

return (NULL);
}
