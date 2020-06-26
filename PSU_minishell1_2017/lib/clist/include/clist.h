/*
** EPITECH PROJECT, 2017
** clist.h
** File description:
** clist, a linked list library made by Leo Smith
** It has 2 main linked list a stack and a queue
*/

#ifndef CLIST_H_
#define CLIST_H_

struct stack {
	struct stack	*next;
	char	*token;
};

struct queue {
	struct queue	*next;
	char	*token;
};

#include <stdlib.h>
#include <unistd.h>

#include "stack.h"
#include "queue.h"

void pop_stack_to_queue(struct stack **, struct queue **);
void dump_stack_to_queue(struct stack **, struct queue **);

int prnb_number_len(int nb);
int prnb_get_digit(int nb, int loc);
int prnb_invert_sign(int nb);
int my_print_nbr(int nb);
void my_putachar(char c);
int my_putastr(char const *str);
char *my_strdp(char const *str);

#endif
