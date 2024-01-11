#include "shell.h"
/**
 * _findchar - locate a character in string
 * @s: the string
 * @c: the character
 * Return: character found
 */
char *_findchar(char *str, char c)
{
	int x = 0;
	int y;

	while (str[x])
	{
		x++;
	}
	for (y = 0; y <= x; y++)
	{
		if (c == str[y])
		{
			str += y;
			return (str);
		}
	}
	return (NULL);
}
