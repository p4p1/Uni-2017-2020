/*
** EPITECH PROJECT, 2017
** tests_my_revstr.c
** File description:
** testing file for my_revstr
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, test_my_revstr_1)
{
	char	str[6] = "hello\0";
	char	str2[6] = "world\0";

	cr_assert_str_eq(my_revstr(str), "olleh");
	cr_assert_eq(my_revstr(0), 0);
	cr_assert_str_eq(my_revstr(str2), "dlrow");
}
