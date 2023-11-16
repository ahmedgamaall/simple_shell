#include"shell.h"
/**
 * free_all_memory - cleanup function designed to deallocate the memory
 * @cmd: a pointer to a character string representing the command
 * @cmd_arr: a pointer to character representing the array of command arguments
 * This function frees the memory allocated.
 * command and its arguments.
 *
 * Return: void
 */
void free_all_memory(char *cmd, char **cmd_arr)
{
	free(cmd);
	free_allocated_str_array(cmd_arr);
}

/**
 * free_allocated_str_array - free the memory associated with a
 * dynamically allocated array of strings
 * @av: The array of strings to be freed.
 *
 * Return: void
 */
void free_allocated_str_array(char **av)
{
	char **current_char;

	if (av == NULL)
	{
		return;
	}

	current_char = av;

	while (*current_char != NULL)
	{
		free(*current_char);
		current_char++;
	}

	free(av);
}
