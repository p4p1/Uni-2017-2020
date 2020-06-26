/*
** EPITECH PROJECT, 2017
** tests_my_strupcase.c
** File description:
** test file for my_strupcase
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strupcase(char *str);

Test(my_strupcase, tests_my_strupcase_V1)
{
	char	*str;

	str = strdup("hello");
	cr_assert_str_eq(my_strupcase(str), "HELLO");
	str = strdup("HELLO");
	cr_assert_str_eq(my_strupcase(str), "HELLO");
}
