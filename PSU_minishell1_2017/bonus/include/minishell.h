/*
** EPITECH PROJECT, 2017
** minishell.h
** File description:
** minishell header file
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "my.h"
#include "clist.h"
#include "my_getopt.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define PROMPT "$> "
#define BUFSIZE 50

enum token_types {
	COMMAND = 1,
	ARGUMENT = 2
};

struct shell_info {
	struct queue	*envi;
	char		**token;
	int		*token_type;
	char		*prompt;
	char		*(*get_command)(struct shell_info *);
	int		(*process_command)(struct shell_info *);
};

struct shell_info *init_shell(char **);
struct queue *get_path(struct queue *);
char *get_cmd_fp(struct shell_info *);
char *my_strdup_ln_space(char *, int *);
char *extract_path(char *, char *);
int inier_command(struct shell_info *);
int arg_no(char *);
int proc_cmd_fp(struct shell_info *);
int setenv_inner(struct shell_info *);
int unsetenv_inner(struct shell_info *);
void check_signal(int);
void destroy_shell(struct shell_info *);

#endif
