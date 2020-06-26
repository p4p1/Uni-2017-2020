/*
** EPITECH PROJECT, 2017
** match
** File description:
** <..>
*/
#include <criterion/criterion.h>

int match(char const *s1, char const *s2);

Test(match, test_matching_str_V1)
{
	cr_assert_eq(math("", ""), 1);
}
