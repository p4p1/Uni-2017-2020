/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** <..>
*/
#include <criterion/criterion.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src);

Test(my_strcat, concatenating_strings_V1)
{
	char	dest[15] = "Hello";
	char	str1[10] = "";
	char	str2[10] = "12";
	char	str3[21] = "0123456789";

	cr_assert_str_eq(my_strcat(dest, ", World!"), "Hello, World!");
	cr_assert_str_eq(my_strcat(str1, "0123456789"), "0123456789");
	cr_assert_str_eq(my_strcat(str2, "qwerty"), "12qwerty");
	cr_assert_str_eq(my_strcat(str3, "9876543210"), "01234567899876543210");
}
