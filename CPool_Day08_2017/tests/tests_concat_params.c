/*
** EPITECH PROJECT, 2017
** concat_params
** File description:
** test file for concat params
*/
#include <criterion/criterion.h>

void concat_params(int ac, char **av);

Test(concat_params, testing_concat_params)
{
	char	*av[] = { "./a.out", "toto", "titi" };
	char	*av2[] = { "ls", "-l", "--colors=always" };

	concat_params(3, av);
	concat_params(3, av2);
	concat_params(-1, 0);
}
