#include "shell.h"

/**
 * convert_to_vector - convert a command string into an array of strings
 * @cmd: a string representing the command to be converted
 *
 * Return: a pointer to a char array.
 */
char **convert_to_vector(char *cmd)
{
	char *cpd_line, *tok, **arg_vector, *cmmd;
	int i = 0, char_count;

	if (cmd[0] == '\0')
		return (NULL);
	cpd_line = strdup(cmd);
	if (cpd_line == NULL)
		return (NULL);
	char_count = count_char_occurrences(cpd_line, ' ');
	arg_vector = malloc((char_count + 1) * sizeof(char *));
	tok = strtok(cpd_line, TOKEN);

	cmmd = token_handler(tok, cmd, arg_vector);
	arg_vector[i++] = cmmd;
	while (tok != NULL)
	{
		tok = strtok(NULL, TOKEN);
		if (tok != NULL)
		{
			cmmd = strdup(tok);
			arg_vector[i++] = cmmd;
		}
	}
	arg_vector[i] = NULL;
	free(cpd_line);
	return (arg_vector);
}

/**
 * token_handler - handle token
 * @tok: a pointer to a token obtained during tokenization
 * @cmd: a pointer to a command
 * @arg_vector: An array of strings representing the vector of tokens
 *
 * Return: string or NULL
*/
char *token_handler(char *tok, char *cmd, char **arg_vector)
{
	char *cmmd, *cpd_line;

	cpd_line = cmd;
	if (tok == NULL)
	{
		free(arg_vector);
		free(cpd_line);
		return (NULL);
	}
	cmmd = strdup(tok);

	return (cmmd);
}
