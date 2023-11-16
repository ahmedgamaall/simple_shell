#include"shell.h"

/**
 * non_builtin - responsible for handling non built-in commands
 * @cmd_arr: An array of strings representing the command and its arguments
 * @env: An array of strings representing the environment variables
 * @st: A pointer to an integer representing the exit status
 * @count: An integer representing the command count
 * @crt: A pointer to the list_paths structure
 * @av: An array of strings representing the command-line arguments
 *
 * Return : void
*/
void non_builtin(char **cmd_arr, char *env[], int *st, int count,
list_paths *crt, char *av[])
{
	char *new_path_var;

	if (access(cmd_arr[0], X_OK) == 0)
		execute_command(cmd_arr[0], cmd_arr, env, st);
	else
	{
		new_path_var = check_execute_permission(cmd_arr[0], crt);
		if (new_path_var)
		{
			execute_command(new_path_var, cmd_arr, env, st);
			free(new_path_var);
		}
		else
		{
			print_error_message(av[0], count, cmd_arr[0], NOT_FOUND);
			*st = NOT_FOUND;
		}
	}
}
