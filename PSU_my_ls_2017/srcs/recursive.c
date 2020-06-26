/*
** EPITECH PROJECT, 2017
** recursive.c
** File description:
** recursive funcitons
*/

#include "my_ls.h"

int recursive_call(char *dir, struct arguments *arg, char *fname)
{
	struct stat	st;
	struct files	*fi;
	DIR	*dirp = opendir(dir);
	struct dirent	*dptr = 0;

	while (dirp != NULL && (dptr = readdir(dirp)) != NULL) {
		stat(dup_path(dptr->d_name, dir), &st);
		if (dptr->d_type == DT_DIR && (dptr->d_name[0] != '.'
				|| arg->a_fl) && my_strcmp(dptr->d_name, "..")
				&& my_strcmp(dptr->d_name, ".")) {
			my_printf("%s:\n", dup_path(dptr->d_name, dir));
			fi = init(dup_path(dptr->d_name, dir), fname);
			diplay_dir(fi, arg, dup_path(dptr->d_name, dir));
			my_printf("\n");
			recursive_call(dup_path(dptr->d_name, dir), arg, fname);
		}
	}
	closedir(dirp);
	return (0);
}
