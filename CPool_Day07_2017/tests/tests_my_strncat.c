/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** <..>
*/
#include <criterion/criterion.h>

char *my_strncat(char *dest, char const *src, int nb);

Test(my_strncat, test_concat_n_string_V1)
{
	char	dest[20] = "abcdef ";
	char	dst2[100] = "";
	char	dst3[7] = "CBA";

	cr_assert_str_eq(my_strncat(dest, "ghijklmn", 3), "abcdef ghi");
	cr_assert_str_eq(my_strncat(dst2, "ghijklmn", 9), "ghijklmn");
	cr_assert_str_eq(my_strncat(dst3, "ABCDEFGH", 3), "CBAABC");
}
