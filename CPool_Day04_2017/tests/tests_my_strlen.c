/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** <..>
*/

#include <criterion/criterion.h>

int my_strlen(char const *str);

Test (my_strlen, return_value_is_good)
{
	cr_assert_eq(my_strlen("toto"), 4);
	cr_assert_eq(my_strlen(0), -1);
}

