#include "shell.h"

/**
 * count_char_occurrences - count the number of occurrences for character
 * @str: the input string.
 * @ch: the character to be counted.
 *
 * Return: The number of occurrences of the character in the string.
 */
unsigned int count_char_occurrences(char *str, char ch)
{
	unsigned int num = 0;

	while (*str != '\0')
	{
		if (*str != ch && *(str + 1) == ch)
			num++;
		str++;
	}
	return (num + 1);
}
