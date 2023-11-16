#include"shell.h"

/**
 * my_exit - Checks if the command is an "exit" command and handles it.
 * @cmd: The original command entered by the user.
 * @cmd_arr: An array of strings containing the command and its arguments
 * @path: A pointer to a list_paths struct representing the current path.
 * @name: The name of the shell program.
 * @count: The command count.
 * @st: A pointer to an integer variable representing the status.
 * @cmd_lines: An array of strings representing command lines
 * @env: an array of strings representing the environment variables
 *
 * Return: void
 */
void my_exit(char *cmd, char **cmd_arr, list_paths *path, char *name,
int count, int *st, list_paths *env, char **cmd_lines)
{
	int exit_number;

	if (strcmp(cmd_arr[0], "exit") == 0)
	{
		if (cmd_arr[1] == NULL)
		{
			cleanup_memory(cmd_lines, count, env, path,
			cmd, cmd_arr);
			exit(*st);
		}
		else if (cmd_arr[1] != NULL)
		{
			if (strlen(cmd_arr[1]) <= 9)
			{
				exit_number = _atoi(cmd_arr[1]);
				if (exit_number != -1)
				{
					cleanup_memory(cmd_lines, count, env,
					path, cmd, cmd_arr);
					exit(exit_number);
				}
				else
				{
					*st = EXIT_ERROR;
					print_error_message(name, count, cmd_arr[1], EXIT_ERROR);
				}
			}
			else
			{
				*st = EXIT_ERROR;
				print_error_message(name, count, cmd_arr[1], EXIT_ERROR);
			}
		}
	}
}

/**
 * cleanup_memory - cleanup function to free the memory allocated for
 * different components
 * @cmd: A string representing a command
 * @cmd_arr: an array of strings containing the command and its arguments
 * @path: a pointer to a list_paths struct representing the current path
 * @count: The command count
 * @cmd_lines: an array of strings representing command lines
 * @env: a linked list representing environment variables
 *
 * Return: void
 */
void cleanup_memory(char **cmd_lines, int count, list_paths *env,
		list_paths *path, char *cmd, char **cmd_arr)
{
	if (cmd_lines)
	{
		free(cmd_lines[count]);
		if (cmd_lines)
			free(cmd_lines);
	}
	free_linked_list(env);
	free_linked_list(path);
	free_all_memory(cmd, cmd_arr);
}
