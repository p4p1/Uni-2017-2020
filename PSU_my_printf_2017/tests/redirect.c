/*
** EPITECH PROJECT, 2017
** redirect.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}
