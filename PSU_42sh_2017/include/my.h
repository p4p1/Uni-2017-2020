/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** prototype de toute la lib
*/

#ifndef MY
#define MY
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct args_t
{
	char *filename;
	int nb_args;
	char **arg;
	char **env;
	char **envini;
	char **path;
	char *cwd;
	int symbol;
	int status;
	int exit;
	int fork;
	struct args_t *next;
} args;

void my_cd(args *);
void my_setenv(args *);
void my_unsetenv(args *);
void my_env(args *);
void my_exit(args *);
void add_one_env(args *, int);
void add_last(args *, int, int);
void delete_env(args *, int, int);
void go_home(args *);
void get_pwd(args *);
char *concat(char *, char*);
int check_error_set(args *);
int handle_signal(int);
int check_built(args *);
int already_exist(args *);
char *make_good(char *);
void manage_sig(int);
void create_nb_args(char *, int, args *);
void control_d(char *, int);
void search_bin(args *);
void modif_name(args *);
int strcmp(char *, char *);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
char *my_revstr(char *str);
int my_strlen(char *);
char *get_next_line(int);
char *get_the_line(int *, int);
int do_struct_command(args *command, char *buff, char **envp, int *status);
void create_struct(args *command, char *str, char **envp, int ch);
void execut_fork(args *command, char *str);
void do_pipe(char *str, char **envp);
char *get_pipe(char *str);

#endif
