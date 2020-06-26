/*
** EPITECH PROJECT, 2017
** tests_my_strstr.c
** File description:
** test file for my strst
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strstr(char const *str, char const *to_find);

Test(my_strstr, tests_my_strstr_V1)
{
	char	*ay;

	ay = strdup("Hello, World");
	cr_assert_str_eq(my_strstr(ay, "World"), "World");
	ay = strdup("Hello, fish.....");
	cr_assert_str_eq(my_strstr(ay, "fish"), "fish.....");
	ay = strdup("Hello, fish.....");
	cr_assert_eq(my_strstr(ay, "pond"), 0);
}
