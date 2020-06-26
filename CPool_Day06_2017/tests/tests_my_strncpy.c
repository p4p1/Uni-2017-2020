/*
** EPITECH PROJECT, 2017
** tests_my_strncpy.c
** File description:
** test file for my_strncpy function
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, test_my_strncpy_v1)
{
	char	str[7];

	cr_assert_str_eq(my_strncpy(str, "helpme", 7), "helpme");
	cr_assert_str_eq(my_strncpy(str, "helpme", 4), "help");
	cr_assert_str_eq(my_strncpy(str, "HelloABCDEFG", 6), "HelloA");
}
