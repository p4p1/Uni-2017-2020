/*
** EPITECH PROJECT, 2017
** my_printf.h
** File description:
** the printf header file
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *, ...);
int my_v_printf(char *, va_list);
int my_printf_S_padding(int);
int my_printf_d_padding(int, char *);
int my_printf_s(va_list, char *);
int my_printf_S(va_list, char *);
int my_printf_i(va_list, char *);
int my_printf_c(va_list, char *);
int my_printf_d(va_list, char *);
int my_printf_o(va_list, char *);
int my_printf_u(va_list, char *);
int my_printf_x(va_list, char *);
int my_printf_X(va_list, char *);
int my_printf_b(va_list, char *);
int my_printf_p(va_list, char *);

#endif
