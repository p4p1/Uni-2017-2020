/*
** EPITECH PROJECT, 2017
** tests_color.c
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void redirect_all_std(void);

Test(my_printf, basic_red, .init = redirect_all_std)
{
	my_printf("%rRredcolor%R");
	cr_assert_stdout_eq_str(KRED "redcolor" KNRM);
}

Test(my_printf, basic_blue, .init = redirect_all_std)
{
	my_printf("%lRbluecolor%R");
	cr_assert_stdout_eq_str(KBLU "bluecolor" KNRM);
}

Test(my_printf, basic_green, .init = redirect_all_std)
{
	my_printf("%gRgreencolor%R");
	cr_assert_stdout_eq_str(KGRN "greencolor" KNRM);
}
