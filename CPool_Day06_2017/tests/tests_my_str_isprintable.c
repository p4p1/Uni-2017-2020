/*
** EPITECH PROJECT, 2017
** tests_my_str_isprintable.c
** File description:
** <..>
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, test_printable_chars_V1)
{
	cr_assert_eq(my_str_isprintable("euwfd$%#"), 1);
	cr_assert_eq(my_str_isprintable(""), 1);
	cr_assert_eq(my_str_isprintable("\n\t"), 0);
}
