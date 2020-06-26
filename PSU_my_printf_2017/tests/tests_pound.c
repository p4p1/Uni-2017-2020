/*
** EPITECH PROJECT, 2017
** tests_pound.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void redirect_all_std(void);

Test(my_printf, basic_hexa_pound_test, .init = redirect_all_std)
{
	my_printf("%#x\n", 255);
	cr_assert_stdout_eq_str("0xff\n");
}

Test(my_printf, basic_bX_pound_test, .init = redirect_all_std)
{
	my_printf("%#X\n", 255);
	cr_assert_stdout_eq_str("0xFF\n");
}

Test(my_printf, basic_o_pound_test, .init = redirect_all_std)
{
	my_printf("%#o\n", 255);
	cr_assert_stdout_eq_str("0377\n");
}

Test(my_printf, mixed_string_number, .init = redirect_all_std)
{
	my_printf("%%%s%%%sAstek42%$", "s", "d");
	cr_assert_stdout_eq_str("%s%dAstek42%$");
}

Test(my_printf, more_mixed_string_number, .init = redirect_all_std)
{
	my_printf("%s%d%s%d%s%5d%s%s%s", "hello", 5, "world", 52, "fifty", 1,
			"cent", "qwerty", "azert");
	cr_assert_stdout_eq_str("hello5world52fifty    1centqwertyazert");
}
