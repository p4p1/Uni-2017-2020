/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** my_show_word_array testing
*/
#include <criterion/criterion.h>

int my_show_word_array(char const * const *tab);

Test(my_show_word_array, testing_show_word_array)
{
	char const * const	test_word[] = { "I", "Love", "Fishing", 0 };
	char const * const	test2[] = { "qwertyuiop", "asdfghjkl", "zxcvbnm", 0 };

	my_show_word_array(test_word);
	my_show_word_array(test2);
	my_show_word_array(0);
}
