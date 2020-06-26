/*
** EPITECH PROJECT, 2017
** shunting_yard.h
** File description:
** the header file for the shunting yard algorithm
*/

#ifndef SHUNTING_YARD_H_
#define SHUNTING_YARD_H_

int in_base(char op, char const *base);
char *stos(char *str, char **endptr, char **b_nop, int neg);
int check_op(char *op, char const *op_str);
int neg_no(char *str, int i, char const *base, char const *op);
int process_operator(char *, struct stack **, struct queue **, char *);
void process_right_p(struct stack **s, struct queue **q, int *n, char *op);
char *del_space(char const *src, char const *base, char const *ops);
void add_op_to_stack(struct stack **s, char *op, int *n, char *ops);
int check_expr(char const *ops, char const *base, char *expr);
char *dump_z(char *str, char const *base);
struct queue *shuting_yard(char *src, char **b_op);

#endif
