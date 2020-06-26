/*
** EPITECH PROJECT, 2017
** tests_my_strcapitalize.c
** File description:
** tests file for strcapitalize
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strcapitalze(char *str);

Test(my_strcapitalize, test_my_strcapitalize_V1)
{
	char *str;

	str = strdup("hey, how are you? 42WORds forty-two; fifty+one");
	cr_assert_str_eq(my_strcapitalize(str), "Hey, How Are You? 42words Forty-Two; Fifty+One");
}
