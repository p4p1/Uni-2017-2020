/*
** EPITECH PROJECT, 2017
** %
** File description:
** <..>
*/

#include <criterion/criterion.h>
#include "../include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av);
int my_list_size(linked_list_t const *begin);

Test(my_list_size, testing_list_size)
{
	int	ac = 5;
	char	*av[5] = { "Hello", "world", "a.out", "qwerty", 0};
	linked_list_t	*tmp = 0;

	tmp = my_params_to_list(ac, av);
	cr_assert_eq(my_list_size(tmp), ac);
}
