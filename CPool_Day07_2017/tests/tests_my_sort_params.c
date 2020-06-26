/*
** EPITECH PROJECT, 2017
** tests_my_sort_params.c
** File description:
** test file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void my_sort_char_array(char **tab, int size);

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_sort_char_array, testing_my_sort_params, .init = redirect_all_std)
{
	char	*str[] = { "hello" };

	my_sort_char_array(str, 1);
}
