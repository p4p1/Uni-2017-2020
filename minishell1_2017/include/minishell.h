/*
** EPITECH PROJECT, 2017
** minishell.h
** File description:
** minishell header file
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "my.h"
#include "prompt.h"

#define PROMPT "$> "
#define BUFSIZE 1024

struct tokenz {
	struct tokenz	*right;
	struct tokenz	*left;
	void		*token;
};

struct shell_info {
	struct tokenz	*tk;
	int		in_shell;
	char		*prompt;
	char		*pwd;
	char		**path;
};

struct shell_info *init_shell(void);
int destroy_shell(struct shell_info *);

#endif
