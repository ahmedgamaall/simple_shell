#include "shell.h"

/**
 * main - Entry point to shell program
 * @ac: Argument counter
 * @av: Argument vector
 * @env: Environment of shell
 *
 * Return: Exit status
 */
int main(int ac, char *av[], char *env[])
{
	int *status, counter = 0, non_interactive_env = 1, st = 0, mode;
	char *cmd, **cmd_lines, **cmd_arr = NULL;
	list_paths *crt;

	status = &st;
	mode = get_mode(ac);
	if (mode != INTERACTIVE_MODE)
		cmd_lines = get_cmd_files(mode, av[1], av[0]);

	crt = convert_to_linked_list();
	while (non_interactive_env && ++counter)
	{
		if (mode == INTERACTIVE_MODE || mode == NON_INTERACTIVE_PIPE)
		{
			if (cmd_lines[counter - 1])
				cmd = cmd_lines[counter - 1];
			else
			{
				free(cmd_lines);
				break;
			}
		}
		else if (mode == INTERACTIVE_MODE)
			cmd = prompt_and_get_cmd(crt);
		if (!cmd)
			continue;
		cmd_arr = convert_to_vector(cmd);
		if (!cmd_arr)
		{
			free(cmd);
			continue;
		}
		if (builtin(cmd, cmd_arr, crt, av[0], counter, status, NULL,
			cmd_lines) != 0)
			non_builtin(cmd_arr, env, status, counter, crt, av);
		free_all_memory(cmd, cmd_arr);
	}
	free_linked_list(crt);
	exit(*status);
}
