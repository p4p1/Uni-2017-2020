/*
** EPITECH PROJECT, 2017
** finalestumper.h
** File description:
** the header file of the finalstumper
*/

#ifndef FINALSTUMPER_H_
#define FINALSTUMPER_H_

#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int get_len(char **str);
int get_shape(char *str, int size, int height);
int check_shape(char **str, int height, int fp_index, int *nb);
char *rush1_line(int size, int height, int line);
char *rush2_line(int size, int height, int line);
char *rush3_line(int size, int height, int line);
char *rush4_line(int size, int height, int line);
char *rush5_line(int size, int height, int line);
void rush3(char *);
void display_rush(int no, int width, int height, int counter);
void rush2(char *str, int size, int height);
void rushB(char *str, int size, int height);
void rush1(char *str, int size, int height, int len);

#endif
