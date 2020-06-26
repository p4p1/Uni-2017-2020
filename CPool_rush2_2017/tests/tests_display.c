/*
** EPITECH PROJECT, 2017
** %
** File description:
** <..>
*/

#include "../include/rush2.h"
#include <criterion/criterion.h>

Test(display_single_occurence, test_display_occurence_V1)
{
	display_single_occurence('Z', 25, 10000);
	display_single_occurence('a', 3, 599);
	display_single_occurence('w', 25, 3510);
}
