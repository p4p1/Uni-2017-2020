/*
** EPITECH PROJECT, 2017
** my_ls.h
** File description:
** header file for my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include "my.h"
#include "my_getopt.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

struct files {
	char		*file_name;
	char		*path;
	int		permitions;
	struct files	*next;
};

struct arguments {
	int	l_fl;
	int	a_fl;
	int	h_fl;
	int	R_fl;
	int	t_fl;
	int	r_fl;
	int	d_fl;
	char	*arg;
};

void sort(struct files **, struct arguments *);
int count_files(char *fname);
int set_padding(struct files *f);
void print_padding(int pad, int no);
void show_rights(struct stat *st);
void print_time(struct stat st);
char *dup_path(char *str, char *path);
int diplay_dir(struct files *f, struct arguments *ar, char *fname);
int recursive_call(char *dir, struct arguments *arg, char *fname);
struct files *init(char *dir_name, char *pname);
void disp_dir(int argc, char **argv, struct arguments *arg);
struct files *init_simple_files(char *dir_name, char *pname);

#endif
