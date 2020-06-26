/*
** EPITECH PROJECT, 2017
** swap_elem.c
** File description:
** swap two elements from an array
*/

#include "bubble_sort.h"

void swap_elem(int *array, int index1, int index2)
{
	int	temp = array[index1];

	array[index1] = array[index2];
	array[index2] = temp;
}
