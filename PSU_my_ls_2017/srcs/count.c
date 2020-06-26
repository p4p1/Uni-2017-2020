/*
** EPITECH PROJECT, 2017
** count.c
** File description:
** counting functions
*/

#include "my_ls.h"

void show_rights(struct stat *st)
{
	my_putstr(((st->st_mode & S_IFMT) == 16384) ? "d" : "-");
	my_putstr((st->st_mode & S_IRUSR) ? "r" : "-");
	my_putstr((st->st_mode & S_IWUSR) ? "w" : "-");
	my_putstr((st->st_mode & S_IXUSR) ? "x" : "-");
	my_putstr((st->st_mode & S_IRGRP) ? "r" : "-");
	my_putstr((st->st_mode & S_IWGRP) ? "w" : "-");
	my_putstr((st->st_mode & S_IXGRP) ? "x" : "-");
	my_putstr((st->st_mode & S_IROTH) ? "r" : "-");
	my_putstr((st->st_mode & S_IWOTH) ? "w" : "-");
	my_putstr((st->st_mode & S_IXOTH) ? "x" : "-");
}

int count_files(char *fname)
{
	DIR	*dirp = NULL;
	struct dirent	*dptr = NULL;
	struct stat	st;
	int		count = 0;

	if ((dirp = opendir(fname)) == NULL) {
		return (0);
	}
	while ((dptr = readdir(dirp)) != NULL) {
		stat(dup_path(dptr->d_name, fname), &st);
		if (dptr->d_name[0] != '.')
			count += st.st_blocks;
	}
	closedir(dirp);
	return (count / 2);
}
