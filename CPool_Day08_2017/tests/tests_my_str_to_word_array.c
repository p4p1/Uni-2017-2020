/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** testing my_sort_word_array
*/
#include <criterion/criterion.h>
#include "../include/libmy.h"

char **my_str_to_word_array(char const *str);

Test(my_str_to_word_array, test_my_sort_word_array)
{
	char	**var = my_str_to_word_array("Hello, World - skafs");
	char	**var2 = my_str_to_word_array("I....Am....Dumb");
	char	**var3 = my_str_to_word_array(0);

	for (int i  = 0; var[i] != 0; i++) {
		my_putstr(var[i]);
		my_putchar('\n');
	}
	for (int i  = 0; var2[i] != 0; i++) {
		my_putstr(var2[i]);
		my_putchar('\n');
	}
}
