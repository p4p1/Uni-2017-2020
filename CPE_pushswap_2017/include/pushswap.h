/*
** EPITECH PROJECT, 2017
** pushswap.h
** File description:
** the pushswap header file
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include "my.h"
#include "my_getopt.h"

typedef struct pushswap	pushswap_t;

struct gear {
	int		value;
	struct gear	*next;
	struct gear	*back;
};

struct pushswap {
	struct gear	*la;
	struct gear	*lb;
	char		*buffer;
	int		pos;
	int		buf_siz;
	unsigned int	verbose;
};

struct pushswap *init_pushswap(int *, char **);
int pa(pushswap_t *);
int pb(pushswap_t *);
void put_in_b(pushswap_t *);
void add_str(char const *, pushswap_t *);
int rra(pushswap_t *);
int is_sorted(struct gear *);
void reverse_list(pushswap_t *);
int ra(pushswap_t *);

#endif
