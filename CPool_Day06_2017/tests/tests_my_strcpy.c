/*
** EPITECH PROJECT, 2017
** tests_my_strcpy.c
** File description:
** test file for my_strcpy...
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char *src);

Test(my_strcpy, my_strcpy_test_V1)
{
	char	str[5];
	char	str2[10];

	my_strcpy(str, "1234");
	cr_assert_str_eq(str, "1234");
	my_strcpy(str2, "qwerty");
	cr_assert_str_eq(str2, "qwerty");
}
