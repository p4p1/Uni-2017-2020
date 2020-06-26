/*
** EPITECH PROJECT, 2017
** minishell2.h
** File description:
** <..>
*/

#ifndef MINISHELL2_H_
#define MINISHELL2_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "my.h"
#include "my_getopt.h"
#include "gnl.h"
#include "clist.h"

#define PROMPT ("$ ")
#define SEPARATOR ("|&<>;")

enum tk_type {
	SEPARATORS,
	COMMAND
};

typedef struct token {
	struct token	*right;
	struct token	*left;
	enum tk_type	type;
	char		**val;
} token_t;

// Tokenizer
token_t *create_tree(char *);
int count_args(char *);
int is_separator(char);
int next_arg(char *);
int skip_tabs_space(char *);
void disp_tree(token_t *);

// Parser
int parser(token_t *, struct queue **, int);
int ex_command(token_t *, struct queue **);
char *my_strcpy_alphanum(char *, char const *);

// env
struct queue *get_path(struct queue *);
char *extract_path(char *, char *);
int inier_command(char **, struct queue **);
char *get_home(struct queue *);
int setenv_inner(char **, struct queue **);
int unsetenv_inner(char **, struct queue **);

// dir
void change_path(char **, struct queue **);
#endif
