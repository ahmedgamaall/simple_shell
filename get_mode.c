#include"shell.h"

/**
 * get_mode - checks the mode of terminal
 * @ac: arguments count
 *
 * Return: 1 interactive, 0 non interactive, -1 on error
 */
int get_mode(int ac)
{
	struct stat stdin_stat;

	fstat(STDIN_FILENO, &stdin_stat);
	if (ac == 1 && isatty(STDIN_FILENO))
		return (INTERACTIVE_MODE);
	if ((!isatty(STDIN_FILENO) && ac == 1))
		return (NON_INTERACTIVE_PIPE);
	if (ac >= 1)
		return (NON_INTERACTIVE_MODE);
	return (ERROR);
}
