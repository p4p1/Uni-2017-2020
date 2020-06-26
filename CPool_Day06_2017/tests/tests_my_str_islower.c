/*
** EPITECH PROJECT, 2017
** tests_my_str_islower.c
** File description:
** test file for my_str_islower.c
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, testing_low_str_V1)
{
	cr_assert_eq(my_str_islower("hfsgdsfgjdsgfds"), 1);
	cr_assert_eq(my_str_islower("ertyjDFGHJjhfds"), 0);
	cr_assert_eq(my_str_islower(""), 1);
}
