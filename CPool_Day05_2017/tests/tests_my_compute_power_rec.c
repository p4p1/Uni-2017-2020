/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_compute_power_rec(int nb, int p);

Test(my_compute_power_rec, my_power_rec_v1)
{
	cr_assert_eq(my_compute_power_rec(5, 2), 25);
	cr_assert_eq(my_compute_power_rec(3, 2), 9);
}
