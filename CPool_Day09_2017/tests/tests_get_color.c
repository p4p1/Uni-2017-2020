/*
** EPITECH PROJECT, 2017
** get_color
** File description:
** testing the getcolor funciton
*/
#include <criterion/criterion.h>

int get_color(unsigned char red, unsigned char green, unsigned char blue);

Test(get_color, testing_get_color_V1)
{
	cr_assert_eq(get_color(255, 255, 255), 16777215);
	cr_assert_eq(get_color(0, 0, 0), 0);
}
