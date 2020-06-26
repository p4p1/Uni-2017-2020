/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** testing strdup
*/
#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test(my_strdup, dup_str_to_mem_V1)
{
	char	*str;

	cr_log_info("testing => my_strdup");
	str = my_strdup("HelloWorld");
	cr_assert_str_eq(str, "HelloWorld");
	/*str = my_strdup(0);
	cr_assert_str_eq(str, 0);*/
	str = my_strdup("dsfdsgf\0fdsgfdsg");
	cr_assert_str_eq(str, "dsfdsgf");
}
