#include "shell.h"

/**
  * check_execute_permission - attempts to locate and validate the executable
  * path for a given command within a list of specified paths
  * @crt: a linked list representing a list of paths
  * @cmd: a string representing the command to be checked for execution
  *
  * Return: full path, NULL if fails
  */
char *check_execute_permission(char *cmd, list_paths *crt)
{
	char *ful_path;
	int fnd_path, len, cmd_len, path_len;

	if (crt == NULL)
		return (NULL);
	while (crt)
	{
		path_len = strlen(crt->path);
		cmd_len = strlen(cmd);
		len = (path_len + cmd_len + 2);
		ful_path = (char *)malloc(len * sizeof(char));
		strcpy(ful_path, crt->path);
		strcat(ful_path, "/");
		strcat(ful_path, cmd);
		fnd_path = 0;
		if (access(ful_path, X_OK) == 0)
		{
			fnd_path = 1;
			break;
		}
		else
			free(ful_path);
		crt = crt->next;
	}
	if (fnd_path)
		return (ful_path);
	else
		return (NULL);
}
