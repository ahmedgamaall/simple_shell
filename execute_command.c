#include "shell.h"

/**
 * execute_command - execution of a command
 * @p: a string representing the path to the program to be executed.
 * @av: an array of strings representing the command and its arguments
 * @env: an array of strings representing the environment variables
 * @st: a pointer to an integer representing the exit st of the child process
 *
 * Returns: void.
 */
void execute_command(char *p, char **av, char **env, int *st)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork has failed");
		exit(1);
	}
	if (pid == 0)
	{
		execve(p, av, env);
		perror("Execve has failed");
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, st, WUNTRACED);
		*st  = WEXITSTATUS(*st);
	}
}
