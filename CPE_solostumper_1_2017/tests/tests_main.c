/*
** EPITECH PROJECT, 2017
** tests_main.c
** File description:
** main test file
*/

#include "hidenp_test.h"

Test(debug_main, debuging_main_simple_case, .init = redirect_all_std)
{
	int	ac = 3;
	char	*av[3] = { "./units", "qwe", "qwe" };

	debug_main(ac, av);
	cr_assert_stdout_eq_str("1\n");
}

Test(debug_main, pdf_first_case, .init = redirect_all_std)
{
	int	ac = 3;
	char	*av[3] = { "./units", "padinton",
			"paqefwtdjetyiytjneytjoeyjnejeyj" };

	debug_main(ac, av);
	cr_assert_stdout_eq_str("1\n");
}

Test(debug_main, pdf_second_case, .init = redirect_all_std)
{
	int	ac = 3;
	char	*av[3] = { "./units", "ddf6vewg64f",
			"gtwthgdwthdwfteewhrtag6h4ffdhsd" };

	debug_main(ac, av);
	cr_assert_stdout_eq_str("0\n");
}

Test(debug_main, pdf_third_case, .init = redirect_all_std)
{
	int	ac = 1;
	char	*av[1] = { "./hidenp" };

	debug_main(ac, av);
	cr_assert_stderr_eq_str("Usage:\t./hidenp needle haystack\n");
}

Test(debug_main, alphabet, .init = redirect_all_std)
{
	int	ac = 3;
	char	*av[3] = { "./units", "g", "abcdefghijklmnopqrstuvwxyz" };

	debug_main(ac, av);
	cr_assert_stdout_eq_str("1\n");
}
