/*
** EPITECH PROJECT, 2017
** tests_my_strlowcase.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, test_strlowcase_V1)
{
	char	*str;

	str = strdup("HELLO");
	cr_assert_str_eq(my_strlowcase(str), "hello");
	str = strdup("hello");
	cr_assert_str_eq(my_strlowcase(str), "hello");
	str = strdup("pWd");
	cr_assert_str_eq(my_strlowcase(str), "pwd");
}
