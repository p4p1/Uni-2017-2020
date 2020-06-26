/*
** EPITECH PROJECT, 2017
** redirect.c
** File description:
** the stdout and stderr redirection function
*/

#include "hidenp_test.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}
