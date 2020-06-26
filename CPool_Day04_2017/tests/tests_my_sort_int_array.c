/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** <..>
*/
#include <criterion/criterion.h>

void my_sort_int_array(int *array, int size);

Test(my_sort_int_array, same_array)
{
	int	arr[5] = {5, 3 ,4, 2, 1};
	int	correct_arr[5] = {1, 2, 3, 4, 5};

	my_sort_int_array(arr, 5);
	//cr_assert_arr_eq(arr, correct_arr, 5 * sizeof(int));
}
