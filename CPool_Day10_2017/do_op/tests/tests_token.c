/*
** EPITECH PROJECT, 2017
** tests_token.c
** File description:
** <..>
*/

#include <criterion/criterion.h>

char token_scanner(char *str);

Test(get_token, test_get_token_V1)
{
	cr_assert_eq(token_scanner("+jiberish"), '+');
	cr_assert_eq(token_scanner("adsa-dsfsd"), '-');
	cr_assert_eq(token_scanner("adsa*"), '*');
	cr_assert_eq(token_scanner("/"), '/');
	cr_assert_eq(token_scanner(""), '\0');
	cr_assert_eq(token_scanner("w2er678gv"), '\0');
}
