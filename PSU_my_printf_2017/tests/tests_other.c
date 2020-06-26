/*
** EPITECH PROJECT, 2017
** tests_other.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void redirect_all_std(void);

Test(my_printf, basic_c_flag_test, .init = redirect_all_std)
{
	my_printf("%c\n", 'A');
	cr_assert_stdout_eq_str("A\n");
}

Test(my_printf, basic_b_second_flag_test, .init = redirect_all_std)
{
	my_printf("%b\n", 5);
	cr_assert_stdout_eq_str("101\n");
}

Test(my_printf, negative_b_flag_test, .init = redirect_all_std)
{
	my_printf("%b\n", -5);
	cr_assert_stdout_eq_str("1101\n");
}
