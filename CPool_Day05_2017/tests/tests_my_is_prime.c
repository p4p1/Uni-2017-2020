/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_is_prime(int nb);

Test(my_is_prime, prime_v1)
{
	cr_assert_eq(my_is_prime(29), 1);
	cr_assert_eq(my_is_prime(30), 0);
}
