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

Test(my_printf, basic_string_test, .init = redirect_all_std)
{
	my_printf("HelloWorld\n");
	cr_assert_stdout_eq_str("HelloWorld\n");
}

Test(my_printf, basic_s_flag_test, .init = redirect_all_std)
{
	my_printf("%s\n", "HelloWorld");
	cr_assert_stdout_eq_str("HelloWorld\n");
}

Test(my_printf, basic_S_flag_test, .init = redirect_all_std)
{
	char	str[] = "HelloWorld";

	str[2] = 6;
	my_printf("%S\n", str);
	cr_assert_stdout_eq_str("He\\006loWorld\n");
}

Test(my_printf, basic_d_flag_test, .init = redirect_all_std)
{
	my_printf("%d\n", 255);
	cr_assert_stdout_eq_str("255\n");
}

Test(my_printf, basic_i_flag_test, .init = redirect_all_std)
{
	my_printf("%i\n", 42);
	cr_assert_stdout_eq_str("42\n");
}
