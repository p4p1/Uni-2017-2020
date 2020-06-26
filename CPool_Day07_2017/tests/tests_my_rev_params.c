/*
** EPITECH PROJECT, 2017
** tests_my_rev_params.c
** File description:
** reverse all params
*/

#include <criterion/criterion.h>

void my_rev_params(int ac, char **av);

Test(my_rev_params, test_rev_params)
{
	char	*str[5] = { "debard", "qwerty", "poiu", "gfd", 0};

	my_rev_params(5, str);
}
