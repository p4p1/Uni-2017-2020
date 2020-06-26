/*
** EPITECH PROJECT, 2017
** %
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include "infin_add.h"

Test(get_sign, testing_if_correct_sign)
{
	cr_assert_eq(get_sign("-1234567890"), -1);
	cr_assert_eq(get_sign("1234567890"), 1);
}
