/*
** EPITECH PROJECT, 2017
** tests_char_to_int.c
** File description:
**test file for char to int
*/

#include <criterion/criterion.h>
#include "../include/infin_add.h"

Test(ch_to_i, test_convertion_to_int)
{
	int	i = 0;

	cr_assert_eq(ch_to_i('9'), 9);
	cr_assert_eq(ch_to_i('a'), 0);
	for (i = 0; i < 10; i++)
		cr_assert_eq(ch_to_i(i + '0'), i);
}

Test(i_to_ch, test_convertion_to_char)
{
	int	i =0;

	cr_assert_eq(i_to_ch(9), '9');
	cr_assert_eq(i_to_ch(22), 0);
	for (i = 0; i < 10; i++)
		cr_assert_eq(i_to_ch(i), (i + '0'));
}
