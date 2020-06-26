/*
** EPITECH PROJECT, 2017
** tests_swap_elem.c
** File description:
** testing_swapelem
*/

#include <criterion/criterion.h>
#include "bubble_sort.h"

Test(swap_elem, index1_greater_than_index2)
{
	int	array[5] = { 1, 2, 3, 4, 5};
	int	index1 = 2;
	int	index2 = 4;

	swap_elem(array, index1, index2);
	cr_assert_eq(array[index1], 5);
	cr_assert_eq(array[index2], 3);
}
