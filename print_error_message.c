#include"shell.h"

/**
 * print_error_message - Prints an error message to the standard error stream.
 * @name: a string representing the name of the shell
 * @count: an integer representing the count of the command
 * @cmd_arr: a string representing command or argument causing the error
 * @error_type:  an integer representing the type of error encountered
 *
 * Return: void
 */
void print_error_message(char *name, int count, char *cmd_arr, int error_type)
{
	char *counter_str;

	counter_str = convert_int_to_str(count);

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter_str, strlen(counter_str));
	write(STDERR_FILENO, ": ", 2);

	if (error_type == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, cmd_arr, strlen(cmd_arr));
		write(STDERR_FILENO, "\n", 1);
	}
	else if (error_type == NOT_FOUND)
	{
		write(STDERR_FILENO, "not found\n", 10);
	}
	else if (error_type == PERMISSION_DENIED)
	{
		write(STDERR_FILENO, "Permission denied\n", 18);
	}

	free(counter_str);
}
