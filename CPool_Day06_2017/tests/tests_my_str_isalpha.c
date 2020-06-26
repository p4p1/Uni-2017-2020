/*
** EPITECH PROJECT, 2017
** tests_my_str_isalpha.c
** File description:
** test file for my_str_isalpha.c
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, test_alpha_str_V1)
{
	cr_assert_eq(my_str_isalpha("hjsfdskFDSFS"), 1);
	cr_assert_eq(my_str_isalpha("456789dshfkj"), 0);
	cr_assert_eq(my_str_isalpha(""), 1);
}
