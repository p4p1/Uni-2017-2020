/*
** EPITECH PROJECT, 2017
** rush.h
** File description:
** header file for rush2 functions
*/

#ifndef RUSH_H_
#define RUSH_H_

#include "my.h"
#include <stdio.h>

int get_occurence(char *str, char letter);
char set_to_lower_case(char *str, char letter);
void language_check(char *str);
int get_args(int size, char arguments[size], char **av);
void display_single_occurence(char letter, int num, int percentage);
void my_putchar_err(char c);
void my_putstr_err(char *str);
int calculate_percentage(char *str, char letter);
int percentage_is_better(char *str);
int get_lang_percent(char *str, int lang_c);

#endif
