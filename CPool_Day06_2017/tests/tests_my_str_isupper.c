/*
** EPITECH PROJECT, 2017
** tests_my_str_isupper.c
** File description:
** testing my_str_isupper.c
*/

#include <criterion/criterion.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, test_upper_case_str_V1)
{
	cr_assert_eq(my_str_isupper(""), 1);
	cr_assert_eq(my_str_isupper("ADSFS"), 1);
	cr_assert_eq(my_str_isupper("sakjdsf"), 0);
	cr_assert_eq(my_str_isupper("hjksfhdsAfDSFS"), 0);
}
