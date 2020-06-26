/*
** EPITECH PROJECT, 2017
** my_evil_str
** File description:
** <..>
*/
#include <criterion/criterion.h>
#include <string.h>

char *my_evil_str(char *str);

Test(my_evil_str, str_are_equal)
{
	char	*str;

	str = strdup("qwerty");
	cr_assert_str_eq(my_evil_str(str), "ytrewq");
}
