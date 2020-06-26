/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_find_prime_sup(int nb);

Test(my_find_prime_sup, find_primt_sup_v1)
{
	cr_assert_eq(my_find_prime_sup(5), 7);
}
