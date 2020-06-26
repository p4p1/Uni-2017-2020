/*
** EPITECH PROJECT, 2017
** disp.c
** File description:
** display funcitons
*/

#include "my_ls.h"

static void basic_display(struct files *fi, struct arguments *args)
{
	struct stat	st;

	while (fi->next != 0) {
		stat(dup_path(fi->file_name, fi->path), &st);
		if ((fi->file_name[0] != '.' || args->a_fl) && !args->d_fl)
			my_printf("%s\n", fi->file_name);
		if ((fi->file_name[0] != '.' || args->a_fl) && args->d_fl &&
				(st.st_mode & S_IFMT) == 16384)
			my_printf("%s\n", fi->file_name);
		fi = fi->next;
	}
}

static void complex_display(struct files *fi, int padding)
{
	struct group	*grp;
	struct passwd	*pwd;
	struct stat	st;

	stat(dup_path(fi->file_name, fi->path), &st);
	grp = getgrgid(st.st_gid);
	pwd = getpwuid(st.st_uid);
	if (grp != NULL && pwd != NULL) {
		show_rights(&st);
		my_printf(" %d %s %s", st.st_nlink, pwd->pw_name,
				grp->gr_name);
		print_padding(padding, st.st_size);
		print_time(st);
		my_printf(" %s\n", fi->file_name);
	}
}

static void lfalg_disp(struct files *fi, char *fname, struct arguments *args)
{
	int	total = count_files(fname);
	int	padding = set_padding(fi);
	struct stat	st;

	if (total > 0)
		my_printf("total %d\n", total);
	while (fi->next != 0) {
		stat(dup_path(fi->file_name, fi->path), &st);
		if ((fi->file_name[0] != '.' || args->a_fl) && !args->d_fl)
			complex_display(fi, padding);
		if ((fi->file_name[0] != '.' || args->a_fl) && args->d_fl &&
				(st.st_mode & S_IFMT) == 16384)
			complex_display(fi, padding);
		fi = fi->next;
	}
}

int diplay_dir(struct files *fi, struct arguments *arg, char *fname)
{
	if (fi == 0)
		return (0);
	sort(&fi, arg);
	if (arg->l_fl)
		lfalg_disp(fi, fname, arg);
	else
		basic_display(fi, arg);
	return (0);
}
