/*
** EPITECH PROJECT, 2017
** simple_1x1.c
** File description:
** <..>
*/

#include "tests.h"

Test(debug, debuging_main_program_1_1_0)
{
	char	**av = (char **)malloc(sizeof(char *) * 3);
	char	**map;

	av[0] = my_strdup("./debug");
	av[1] = my_strdup("maps/1x1/test_1_1_0.txt");
	map = debug(2, av);
	if (map != NULL)
		cr_assert_eq(map[0][0], 'x');
}

Test(debug, debuging_main_program_1_1_100)
{
	char	**av = (char **)malloc(sizeof(char *) * 3);
	char	**map;

	av[0] = my_strdup("./debug");
	av[1] = my_strdup("maps/1x1/test_1_1_100.txt");
	map = debug(2, av);
	cr_assert_eq(map[0][0], 'o');
}
