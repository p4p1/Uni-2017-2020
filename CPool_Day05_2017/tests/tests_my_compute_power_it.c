/*
** EPITECH PROJECT, 2017
** my_compute_power_it
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_compute_power_it(int nb, int p);

Test(my_compute_power_it, power_it_v1)
{
	cr_assert_eq(my_compute_power_it(2, 2), 4);
	cr_assert_eq(my_compute_power_it(3, 2), 9);
}
