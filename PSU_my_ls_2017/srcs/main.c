/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/

#include "my_ls.h"

struct files *init(char *dir_name, char *pname)
{
	DIR	*dirp = NULL;
	struct dirent	*dptr = NULL;
	struct files	*fi = (struct files *)malloc(sizeof(struct files));
	struct files	*head = fi;

	if ((dirp = opendir(dir_name)) == NULL) {
		return (init_simple_files(dir_name, pname));
	}
	while ((dptr = readdir(dirp)) != NULL) {
		fi->file_name = my_strdup(dptr->d_name);
		fi->path = my_strdup(dir_name);
		if (dptr != NULL) {
			fi->next = (struct files *)malloc(sizeof(struct files));
			fi = fi->next;
		}
	}
	closedir(dirp);
	return (head);
}

static int set_arg(struct arguments *arg, char ch)
{
	if (ch == 'l')
		arg->l_fl = 1;
	if (ch == 'R')
		arg->R_fl = 1;
	if (ch == 't')
		arg->t_fl = 1;
	if (ch == 'r')
		arg->r_fl = 1;
	if (ch == 'd')
		arg->d_fl = 1;
	if (ch == 'a')
		arg->a_fl = 1;
	if (ch == 'h')
		arg->h_fl = 1;
	if (ch == '?') {
		return (-1);
	}
	return (0);
}

static struct arguments *init_arg(void)
{
	struct arguments	*arg  = 0;

	arg = (struct arguments *)malloc(sizeof(struct arguments));
	if (arg == 0)
		return (0);
	arg->l_fl = 0;
	arg->R_fl = 0;
	arg->r_fl = 0;
	arg->t_fl = 0;
	arg->d_fl = 0;
	arg->a_fl = 0;
	arg->h_fl = 0;
	return (arg);
}

static void my_ls(struct files *fi, struct arguments *ar, int argc, char **argv)
{
	int	mult = (my_optind != (argc - 1)) ? 1 : 0;

	if (ar->R_fl) {
		my_printf("%s:\n", argv[my_optind]);
		fi = init(argv[my_optind], argv[0]);
		diplay_dir(fi, ar, argv[my_optind]);
		my_printf("\n");
	}
	while (my_optind < argc) {
		if (ar->R_fl) {
			recursive_call(argv[my_optind++], ar, argv[0]);
		} else {
			if (mult)
				my_printf("%s:\n", argv[my_optind]);
			fi = init(argv[my_optind], argv[0]);
			diplay_dir(fi, ar, argv[my_optind++]);
			if (mult)
				my_printf("\n");
		}
	}
}

int main(int argc, char **argv)
{
	struct files		*fi = 0;
	struct arguments	*arg = init_arg();
	char			ch = 0;

	while ((ch = my_getopt(argc, argv, "hlRtrda")) != -1)
		if (set_arg(arg, ch) < 0)
			return (84);
	if (arg->d_fl) {
		disp_dir(argc, argv, arg);
	} else if (my_optind == 0) {
		if (arg->R_fl) {
			recursive_call(".", arg, argv[0]);
		} else {
			fi = init(".", argv[0]);
			diplay_dir(fi, arg, ".");
		}
	} else {
		my_ls(fi, arg, argc, argv);
	}
	return (0);
}
