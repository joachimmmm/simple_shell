#include "files.h"
/**
 * atoi_func - converts a to int
 * @str: str to be converted
 * Return: result
 */
int atoi_func(const char *str)
{
	int index = 0, sign, result = 0;

	if (str[0] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[0] == '+')
	{
		index++;
	}
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			result = result * 10 + (str[index] - '0');
			index++;
		}
		else
		{
			break;
		}
	}
	return ((result * sign));
}
