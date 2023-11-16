#include"shell.h"

/**
 * convert_to_array - given string text based on the newline character '\n'
 * @txt: a pointer to a string representing the input text to be tokenized
 *
 * Return: a pointer to a allocated array of strings
 */
char **convert_to_array(char *txt)
{
	char *tok, *cmd;
	char **cmd_lines;
	int i;
	unsigned int char_count;

	char_count = 0;
	cmd_lines = NULL;
	i = 0;
	char_count = count_char_pipe(txt, '\n');
	cmd_lines = (char **)malloc((char_count + 1) * sizeof(char *));
	tok = strtok(txt, "\n");
	cmd = strdup(tok);
	cmd_lines[i++] = cmd;
	while (tok != NULL)
	{
		tok = strtok(NULL, "\n");
		if (tok != NULL)
		{
			cmd = strdup(tok);
			cmd_lines[i++] = cmd;
		}
	}
	free(txt);
	cmd_lines[i] = NULL;
	return (cmd_lines);
}

/**
 * count_char_pipe - count the number of occurrences a char in a string
 * @str: A pointer to the null-terminated string in which occurrences of
 * the specified character are counted
 * @ch: The character whose occurrences are counted
 *
 * Return: unsigned integer number of occurrences
 */
unsigned int count_char_pipe(char *str, char ch)
{
	unsigned int num = 0;

	while (*str != '\0')
	{
		if (*str == ch)
			num++;
		str++;
	}
	return (num + 1);
}
