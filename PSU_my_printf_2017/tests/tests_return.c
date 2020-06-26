/*
** EPITECH PROJECT, 2017
** tests_return.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void redirect_all_std(void);

Test(my_printf, basic_return_code_test, .init = redirect_all_std)
{
	cr_assert_eq(my_printf("HelloWorld\n"), 11);
	cr_assert_eq(my_printf("%d%s\n", 55, "HelloWorld"), 13);
}

Test(my_printf, n_flag_test, .init = redirect_all_std)
{
	int	ret = 0;

	my_printf("HelloWorld%n\n", &ret);
	cr_assert_eq(ret, 10);
}
