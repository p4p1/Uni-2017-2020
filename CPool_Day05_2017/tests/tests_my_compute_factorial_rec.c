/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_compute_factorial_rec(int nb);

Test(my_compute_factorial_rec, comute_factorial_rec_v1)
{
	cr_assert_eq(my_compute_factorial_rec(5), 120);
	cr_assert_eq(my_compute_factorial_rec(3), 6);
	cr_assert_eq(my_compute_factorial_rec(9), 362880);
	cr_assert_eq(my_compute_factorial_rec(0), 1);
}
