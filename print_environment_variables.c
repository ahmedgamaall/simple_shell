#include"shell.h"

/**
 * print_environment_variables - print the environment variables to the
 * standard output
 * @st: a pointer to an integer representing the exit status
 *
 * Return: void
 */
void print_environment_variables(int *st)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
	*st = 0;
}
