#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define ERROR -1
#define TOKEN " \t\r\n\a\""

#define EXIT_ERROR 2
#define PERMISSION_DENIED 126
#define NOT_FOUND 127

#define NON_INTERACTIVE_MODE 0
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPE 2

/**
 * struct list_paths - a struct made for nodes out of environment variable path
 * @path: environment  variable path
 * @len: length of the path
 * @next: points to the next node
*/
typedef struct list_paths
{
	char *path;
	unsigned int len;
	struct list_paths *next;
} list_paths;

extern char **environ;
int get_mode(int ac);
list_paths *convert_to_linked_list();
char **get_cmd_files(int mode, char *fname, char *name);
char **non_interactive_pipes();
char **non_interactive_files(char *fname, char *name);
char **convert_to_array(char *txt);
unsigned int count_char_pipe(char *str, char ch);
void can_not_open_file(char *prog, int count, char *fname);
size_t print_linked_list(const list_paths *hd);
list_paths *add_linked_list_node(list_paths **hd, char *p);
char *prompt_and_get_cmd(list_paths *crt);
void free_linked_list(list_paths *hd);
char **convert_to_vector(char *cmd);
unsigned int count_char_occurrences(char *str, char ch);
char *token_handler(char *tok, char *cmd, char **arg_vector);
int builtin(char *cmd, char **cmd_arr, list_paths *path, char *name,
int count, int *st, list_paths *env_list, char **cmd_lines);
void print_environment_variables(int *st);
void my_exit(char *cmd, char **cmd_arr, list_paths *path, char *name,
int count, int *st, list_paths *env, char **cmd_lines);
int _atoi(char *ch);
void non_builtin(char **cmd_arr, char *env[], int *st,
int count, list_paths *crt, char *av[]);
void free_all_memory(char *cmd, char **cmd_arr);
void free_allocated_str_array(char **av);
void print_error_message(char *name, int count, char *cmd_arr, int error_type);
char *check_execute_permission(char *cmd, list_paths *crt);
void execute_command(char *p, char **av, char **env, int *st);
char *convert_int_to_str(int num);
void cleanup_memory(char **cmd_lines, int count, list_paths *env,
list_paths *path, char *cmd, char **cmd_arr);

#endif
