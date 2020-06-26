/*
** EPITECH PROJECT, 2017
** dir.c
** File description:
** directory listing
*/

#include "my_ls.h"

static void basic_disp_dir(int argc, char **argv)
{
	int	i = 0;

	if (my_optind == 0) {
		my_printf("%s\n", ".");
		my_optind = argc;
	}
	for (i = my_optind; i < argc; i++) {
		my_printf("%s\n", argv[i]);
	}
}

static void lflag_disp_dir(char *fname)
{
	struct group	*grp;
	struct passwd	*pwd;
	struct stat	st;

	stat(fname, &st);
	grp = getgrgid(st.st_gid);
	pwd = getpwuid(st.st_uid);
	show_rights(&st);
	my_printf(" %d %s %s %d", st.st_nlink, pwd->pw_name,
			grp->gr_name, st.st_size);
	print_time(st);
	my_printf(" %s\n", fname);
}

void disp_dir(int argc, char **argv, struct arguments *arg)
{
	int	i = 0;

	if (arg->l_fl) {
		if (my_optind == 0) {
			lflag_disp_dir(".");
			my_optind = argc;
		}
		for (i = my_optind; i < argc; i++) {
			lflag_disp_dir(argv[i]);
		}
	} else {
		basic_disp_dir(argc, argv);
	}
}
