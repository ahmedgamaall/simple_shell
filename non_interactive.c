#include"shell.h"

/**
 * non_interactive_pipes - read input in a non-interactive mode
 *
 * Return: a pointer to a array of command lines strings, or returns NULL
 */
char **non_interactive_pipes()
{
	char c[2048], *txt, **cmd_lines;
	size_t count_chars = 0;
	ssize_t byts;
	int i, fg;

	fg = 0;
	cmd_lines = NULL;
	txt = NULL;
	while ((byts = read(STDIN_FILENO, c, 2048)) > 0)
	{
		count_chars = count_chars + byts;
	}
	if (byts == -1)
	{
		perror("reading error");
		exit(ERROR);
	}
	if (count_chars > 2048)
		c[2048 - 1] = '\0';
	else
		c[count_chars - 1] = '\0';

	for (i = 0; c[i]; i++)
	{
		if (c[i] != ' ')
			fg = 1;
	}
	if (fg == 0)
		return (NULL);
	count_chars = strlen(c);
	txt = (char *)malloc(sizeof(char) * (count_chars + 1));
	if (txt != NULL)
	{
		strcpy(txt, c);
		txt[count_chars] = '\0';
		cmd_lines = convert_to_array(txt);
	}
	return (cmd_lines);
}

/**
 * non_interactive_files - a file in a non-interactive mode, process the input
 * @fname: A pointer to a string representing the filename of shell
 * @name: A pointer to a string representing the shell name
 *
 * Return: pointer to char array with output, opens file, reads each line.
 */
char **non_interactive_files(char *fname, char *name)
{
	struct stat fstat;
	char *txt, **cmd_lines;
	size_t lts;
	int fd;

	if (stat(fname, &fstat) != -1)
	{
		if (S_ISREG(fstat.st_mode))
		{
			fd = open(fname, O_RDONLY);
			if (fd  == -1)
				exit(ERROR);
			if (fstat.st_size == 0)
				exit(0);
			txt = malloc((fstat.st_size + 1) * sizeof(char));
			if (!txt)
				return (NULL);
			lts = read(fd, txt, fstat.st_size);
			if ((int) lts == -1)
			{
				perror("reading error");
			}
			close(fd);
			txt[lts - 1] = '\0';
			if (txt)
				cmd_lines = convert_to_array(txt);
			return (cmd_lines);
		}
		else
			exit(0);
	}
	else
	{
		can_not_open_file(name, 0, fname);
		exit(127);
	}
	return (NULL);
}
