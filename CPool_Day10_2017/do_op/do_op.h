/*
** EPITECH PROJECT, 2017
** do-op.h
** File description:
** <..>
*/

#ifndef DO_OP_H_
#define DO_OP_H_

#include "../include/my.h"
#include <unistd.h>

int get_no(char *str);
void my_putchar_err(char c);
void my_putstr_err(char *str);
int do_operation(int V1, char token, int V2);
char is_token(char ch);
char token_scanner(char *str);


#endif
