/*
** EPITECH PROJECT, 2017
** fractals.h
** File description:
** <..>
*/

#ifndef FRACTALS_H_
#define FRACTALS_H_

#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int check_params(int, char **);
char *expand_buf(char *, char *, int *);
char *my_return_replace(char *);
char *my_fract_replace(char *, char *, char *);


#endif
