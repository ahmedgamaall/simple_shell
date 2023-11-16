#include "shell.h"

/**
 * get_cmd_files - coordinates the retrieval of command lines based on
 * the specified mode of operation
 * @mode: An integer indicating the mode of operation
 * @fname: A pointer to a string representing the filename
 * @name: A pointer to a string representing the shell name
 *
 * Return: a pointer to a allocated array of command lines strings
 */
char **get_cmd_files(int mode, char *fname, char *name)
{
	char **cmd_lines;

	if (mode == NON_INTERACTIVE_PIPE)
	{
		cmd_lines = non_interactive_pipes();
		if (!cmd_lines)
			exit(0);
	}
	else if (mode == NON_INTERACTIVE_MODE)
	{
		cmd_lines = non_interactive_files(fname, name);
		if (!cmd_lines)
			exit(0);
	}
	return (cmd_lines);
}
