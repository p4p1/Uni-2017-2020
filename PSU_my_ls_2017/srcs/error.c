/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error detection system
*/

#include "my_ls.h"

struct files *init_simple_files(char *dir_name, char *pname)
{
	struct stat	st;
	struct files	*fi = (struct files *)malloc(sizeof(struct files));

	if (stat(dir_name, &st) == -1) {
		my_printf("%s: cannot access '%s': No such file or directory\n",
				pname, dir_name);
		return (0);
	}
	fi->file_name = my_strdup(dir_name);
	fi->next = (struct files *)malloc(sizeof(struct files));
	return (fi);
}
