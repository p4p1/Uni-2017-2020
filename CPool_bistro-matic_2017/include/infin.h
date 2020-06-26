/*
** EPITECH PROJECT, 2017
** infin_add.h
** File description:
** infin_add header file
*/

#ifndef INFIN_H_
#define INFIN_H_

#include "bistro.h"

struct operands {
	char *op1;
	char *op2;
	char *tmp;
	char *save;
	int size;
};

char *addinf_2(char *, char *, char const *, char const *);
int errors(int);
int check_neg(char const *, char);
char *str_malloc(char *, char *);
char *subinf_2(char *, char *, char const *, char const *);
char *multinf(char *, char *, char const *, char const *);
char to_base(int, char const *);
int from_base(char, char const *);
void my_memset(char *, int);
void delete_zeros(char *, char const *);
char *put_minus(char *, char const *, char const *);
char *subinf(char *s1, char *s2, char const *base);
char *my_strcpy_div(char *, char const *);
char *addinf(char *s1, char *s2, char const *base);
int cmp_base(char *s1, char *s2, char const *base);
int cmp_base_n(char *s1, char *s2, char const *base, int n);
void init_op(struct operands *op, char *s1, char *s2, int size);
int check_exception(char *result, char *s1, const char *base);
char *n_mult(struct operands *op, int *nb, char const *base, int j);
int is_bigger(char *s1, char *s2, char const *base, int n);
int is_bigger(char *s1, char *s2, char const *base, int n);
int do_division(struct operands *op, char const *base, int j);
char *divide(char *s1, char *s2, char const *base);
char *modulo_div(char *s1, char *s2, char const *base);
char *negatives(char *result, char const *op);
char *checking_negatives(char **s1, char **s2, char const *op);
char *divinf_2(char *s1, char *s2, char const *base, char const *op);
char *modulo_2(char *s1, char *s2, char const *base, char const *op);
char *modulo(char *s1, char *s2, char const *base, char const *op);
char *my_strndup(char const *src, int n);
int zero_condition(char *s1, char *s2, char const *base);
int len(char *str);

#endif
