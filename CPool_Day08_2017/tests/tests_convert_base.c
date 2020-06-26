/*
** EPITECH PROJECT, 2017
** convert_base
** File description:
** test to convert to base
*/
#include <criterion/criterion.h>

char *convert_base(char const *nbr, char const *base_from, char const *base_to);

Test(convert_base, convert_to_decimal)
{
	cr_log_info("testing ==> convert_base");
	convert_base("55", "01234567890", "01");
}
