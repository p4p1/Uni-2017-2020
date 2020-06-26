/*
** EPITECH PROJECT, 2017
** my_params_to_array
** File description:
** <..>
*/

#include <criterion/criterion.h>

struct info_param
{
	int length;
	char *str;
	char *copy;
	char **word_array;
};

int my_show_array(struct s_stock_par const *par);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info__param const *par);

Test(my_params_to_array, testing_my_parmas_to_array_V1)
{
	int	i = 0;
	char	*argv[6] = { "Hello", "World", "qwerty", "azerty", "pouya", 0 };
	struct info__param *i_p = my_params_to_array(6, argv);

	cr_assert_eq(i_p[0].length, 5);
	cr_assert_eq(i_p[1].length, 5);
	cr_assert_eq(i_p[2].length, 6);
	cr_assert_eq(i_p[3].length, 6);
	cr_assert_eq(i_p[4].length, 5);
	cr_assert_str_eq(i_p[0].str, "Hello");
	cr_assert_str_eq(i_p[1].str, "World");
	cr_assert_str_eq(i_p[2].str, "qwerty");
	cr_assert_str_eq(i_p[3].str, "azerty");
	cr_assert_str_eq(i_p[4].str, "pouya");
	cr_assert_str_eq(i_p[0].copy, "Hello");
	cr_assert_str_eq(i_p[1].copy, "World");
	cr_assert_str_eq(i_p[2].copy, "qwerty");
	cr_assert_str_eq(i_p[3].copy, "azerty");
	cr_assert_str_eq(i_p[4].copy, "pouya");
	cr_assert_str_eq(i_p[0].word_array[0], "Hello");
	cr_assert_str_eq(i_p[1].word_array[0], "World");
	cr_assert_str_eq(i_p[2].word_array[0], "qwerty");
	cr_assert_str_eq(i_p[3].word_array[0], "azerty");
	cr_assert_str_eq(i_p[4].word_array[0], "pouya");
}
