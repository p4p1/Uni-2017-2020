/*
** EPITECH PROJECT, 2017
** current-file-name
** File description:
** <..>
*/

#include <criterion/criterion.h>

int get_len(char **str);

Test(getlen, nbrlen)
{
	char **qq = (char **)malloc(sizeof(char *) * 2);

	qq[0] = strdup("AAAAA");
	qq[1] = strdup("BBBBB");
	cr_assert_eq(get_len(qq), 2);
}
