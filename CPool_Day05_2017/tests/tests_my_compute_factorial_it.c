/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_compute_factorial_it(int nb);

Test(my_compute_factorial_it, test_fact_it_v1)
{
	cr_assert_eq(my_compute_factorial_it(5), 120);
	cr_assert_eq(my_compute_factorial_it(3), 6);
	cr_assert_eq(my_compute_factorial_it(9), 362880);
	cr_assert_eq(my_compute_factorial_it(0), 1);
}
