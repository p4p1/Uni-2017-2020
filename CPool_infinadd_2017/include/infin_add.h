/*
** EPITECH PROJECT, 2017
** infin_add.h
** File description:
** infin_add header file
*/

#ifndef INFIN_ADD_H_
#define INFIN_ADD_H_

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int ch_to_i(char ch);
int i_to_ch(int i);
char *add_values(char *str1, char *str2, int sign1, int sign2);
int get_sign(char *str);
void inc(char **str1, char **str2);
void display_value(char *res);
int display_sign(char **v1, char **v2);

#endif
