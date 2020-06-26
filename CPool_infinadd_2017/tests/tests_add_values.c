/*
** EPITECH PROJECT, 2017
** tests_add_values.c
** File description:
** testing value addition
*/

#include <criterion/criterion.h>
#include "infin_add.h"

Test(do_op, testing_opperation_unit)
{
	cr_assert_eq(do_op('5', '3', 0, 1, 1), 8);
	cr_assert_eq(do_op('0', '0', 0, 1, 1), 0);
	cr_assert_eq(do_op('1', '1', 1, 1, 1), 3);
	cr_assert_eq(do_op('5', '3', 0, -1, 1), 18);
}


Test(inc, testing_incrementation)
{
	char	*str1;
	char	*str2;

	str1 = my_strdup("helloWorld!\n");
	str2 = my_strdup("qwertyuiop\n");
	inc(&str1, &str2);
	cr_assert_str_eq(str1, "elloWorld!\n");
	cr_assert_str_eq(str2, "wertyuiop\n");
}

Test(add_values, testing_addition)
{
	char	*str = add_values("1234", "4321", 1, 1);

	cr_assert_str_eq(str, "5555");
}
