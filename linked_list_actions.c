#include "shell.h"

/**
 * paths_to_linked_list - convert the PATH environment variable into
 * a linked list of paths
 *
 * Return: a linked list of paths
 */
list_paths *convert_to_linked_list()
{
	list_paths *linked_lists;
	char *cpd_var, *path_var, *tok;

	linked_lists = NULL;

	path_var = getenv("PATH");
	if (path_var == NULL)
		return (NULL);
	cpd_var = strdup(path_var);
	if (cpd_var == NULL)
		return (NULL);
	tok = strtok(cpd_var, ":");
	while (tok != NULL)
	{
		add_linked_list_node(&linked_lists, tok);
		tok = strtok(NULL, ":");
	}
	free(cpd_var);
	return (linked_lists);
}

/**
 * add_linked_list_node - add a node to the beginning of a linked list of paths
 * @hd: pointer to the head of list with the type list_paths
 * @p: pointer to path.
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_paths *add_linked_list_node(list_paths **hd, char *p)
{
	list_paths *new_node;
	int i = 0;
	char *str_path;

	while (p[i] != '\0')
	{
		i++;
	}
	new_node = malloc(sizeof(list_paths));
	if (new_node == NULL)
		return (NULL);

	if (p)
	{
	str_path = strdup(p);
	if (str_path == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = i;
	new_node->path = str_path;
	}
	else
	{
		new_node->len = 0;
		new_node->path = NULL;
	}
	new_node->next = (*hd);

	*hd = new_node;
	return (new_node);
}

/**
 * free_linked_list - free the memory associated with a linked list of paths
 * @hd: a pointer to the head of the linked list (list_paths)
 *
 * Return: void
 */
void free_linked_list(list_paths *hd)
{
	list_paths *pointer = hd;
	list_paths *next_node;

	while (pointer != NULL)
	{
		next_node = pointer->next;
		free(pointer->path);
		free(pointer);
		pointer = next_node;
	}
}

/**
 * print_linked_list - printing the contents of a linked list of paths
 * @hd: A pointer to the head of the linked list
 *
 * Return: count of nodes in the linked list
 */
size_t print_linked_list(const list_paths *hd)
{
	int count;

	if (hd == NULL)
	{
		return (0);
	}
	count = 0;

	while (hd)
	{
		if (hd->path == NULL)
		{
			printf("[0] (nil)\n");
			fflush(stdout);
		}
		else
		{
			printf("[%d] %s\n", hd->len, hd->path);
			fflush(stdout);
		}
		hd = hd->next;
		count++;
	}
	return (count);
}
