/*
** EPITECH PROJECT, 2017
** tests_basic.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void redirect_all_std(void);

Test(my_printf, basic_o_flag_test, .init = redirect_all_std)
{
	my_printf("%o\n", 42);
	cr_assert_stdout_eq_str("52\n");
}

Test(my_printf, basic_u_flag_test, .init = redirect_all_std)
{
	my_printf("%u\n", 5);
	cr_assert_stdout_eq_str("5\n");
}

Test(my_printf, basic_x_flag_test, .init = redirect_all_std)
{
	my_printf("%x\n", 255);
	cr_assert_stdout_eq_str("ff\n");
}

Test(my_printf, basic_X_flag_test, .init = redirect_all_std)
{
	my_printf("%X\n", 255);
	cr_assert_stdout_eq_str("FF\n");
}

Test(my_printf, basic_b_flag_test, .init = redirect_all_std)
{
	my_printf("%b\n", 2);
	cr_assert_stdout_eq_str("10\n");
}
