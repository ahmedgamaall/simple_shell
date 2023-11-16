#include"shell.h"

/**
 * prompt_and_get_cmd - display a command prompt, read a command from the user
 * @crt: A linked list representing paths or directories to be used in shell
 *
 * Return: the entered command
 */
char *prompt_and_get_cmd(list_paths *crt)
{
	ssize_t nread;
	size_t len = 0;
	char *cmd = NULL;

	write(1, "($) ", 4);
	nread = getline(&cmd, &len, stdin);
	if (nread == -1)
	{
		write(1, "\n", 1);
		free_linked_list(crt);
		free(cmd);
		exit(0);
	}
	if (nread == 1 && cmd[0] == '\n')
	{
		free(cmd);
		return (NULL);
	}

	cmd[nread - 1] = '\0';

	return (cmd);
}
