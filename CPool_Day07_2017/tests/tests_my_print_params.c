/*
** EPITECH PROJECT, 2017
** tests_my_print_params.c
** File description:
** testing my print params
*/

#include <criterion/criterion.h>

void my_print_params(int ac, char **av);

/*
void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}*/

Test(my_print_params, testing_my_print_params)
{
	char	*av[] = { "Hello", "world", "qwert", "poiuy", 0 };

	my_print_params(5, av);
	//cr_assert_eq_str("Hello\npouiuy\nqwert\nworld\n");
}
