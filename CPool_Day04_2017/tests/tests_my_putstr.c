/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_putstr(char const *str);

Test(my_putstr, str_are_equal)
{
	my_putstr("HELLOWORLD");
	my_putstr(0);
}
