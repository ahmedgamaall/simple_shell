#include"shell.h"
/**
 * _atoi - converts a string to an integer.
 * @ch: string to be converted.
 *
 * Return: the number in String  ,otherwise -1 on error.
 */
int _atoi(char *ch)
{
	unsigned int num, i;

	i = 0;
	num = 0;

	while (ch[i] != '\0')
	{
		if (((ch[i] >= '0') && (ch[i] <= '9')))
		{
			num = (num * 10) + (ch[i] - '0');
		}
		else if (ch[i] == '+')
		{
			continue;
		}
		else
		{
			return (-1);
		}

		i++;
	}

	return (num);
}
