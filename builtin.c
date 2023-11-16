#include "shell.h"

/**
 * builtin -  handling built-in commands in a shell program
 * @cmd: string representing the original command
 * @cmd_arr: An array of strings containing the parsed command
 * @path: A pointer to a list_paths struct representing the current path
 * @name: A string representing the name of the shell
 * @count: An integer representing the command count
 * @st: A pointer to an integer representing the exit status
 * @env_list: A linked list representing environment variables
 * @cmd_lines: An array of strings representing command lines
 *
 * Return: 0 on successful, -1 an error
 */
int builtin(char *cmd, char **cmd_arr, list_paths *path, char *name,
int count, int *st, list_paths *env_list, char **cmd_lines)
{
	int i, cm = -1;
	char *built_in[] = {"env", "exit"};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(built_in[i], cmd_arr[0]) == 0)
		{
			cm = i;
			break;
		}
	}
	if (cm == -1)
		return (cm);

	switch (cm)
	{
		case 0:
			print_environment_variables(st);
			break;
		case 1:
			my_exit(cmd, cmd_arr, path, name, count, st, env_list,
			cmd_lines);
			break;
		default:
			return (-1);
	}
	return (0);
}
