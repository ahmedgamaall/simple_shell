#include "shell.h"
/**
 * can_not_open_file - handles errors that occur when a file cannot be opened
 * @prog: the name of the program attempting to open the file
 * @count: a counter variable to keep track.
 * @fname: the name of the file that cannot be opened
 *
 * Return : void.
 */
void can_not_open_file(char *prog, int count, char *fname)
{

	char *str_num;

	str_num = convert_int_to_str(count);
	write(2, prog, strlen(prog));
	write(2, ": ", 2);
	write(2, str_num, strlen(str_num));
	write(2, ": ", 2);
	write(2, "Can't open ", 11);
	write(2, fname, strlen(fname));
	write(2, "\n", 1);
}
