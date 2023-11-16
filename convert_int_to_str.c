#include"shell.h"

/**
 * convert_int_to_str - converts an integer to a string
 * @num: an integer to be converted
 *
 * Return: string
 */
char *convert_int_to_str(int num)
{
	int count = 0, tpy = num;
	char *copied_num;

	if (num == 0)
		count = 1;
	else
	{
		while (tpy != 0)
		{
			tpy = tpy / 10;
			count++;
		}
	}

	copied_num = malloc(sizeof(char) * (count + 1));
	if (!copied_num)
	{
		perror("malloc error");
		return (NULL);
	}

	copied_num[count] = '\0';

	while (count != 0)
	{
		count--;
		copied_num[count] = '0' + num % 10;
		num = (num / 10);
	}

	return (copied_num);
}
