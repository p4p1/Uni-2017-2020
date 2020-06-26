/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_compute_square_root(int nb);

Test(my_compute_square_root, my_square_root)
{
	cr_assert_eq(my_compute_square_root(625), 25);
}
