/*
** EPITECH PROJECT, 2017
** %
** File description:
** <..>
*/

#include <criterion/criterion.h>

#include "../include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av);
void my_rev_list(linked_list_t **begin);

Test(my_rev_list, testing_my_params)
{
	int	ac = 5;
	char	*av[5] = { "Hello", "world", "a.out", "qwerty", 0};
	linked_list_t	*tmp = 0;

	tmp = my_params_to_list(ac, av);
	my_rev_list(&tmp);
	cr_assert_eq(tmp->data, 0);
	tmp = tmp->next;
	cr_assert_str_eq(tmp->data, "Hello");
	tmp = tmp->next;
	cr_assert_str_eq(tmp->data, "world");
	tmp = tmp->next;
	cr_assert_str_eq(tmp->data, "a.out");
	tmp = tmp->next;
	cr_assert_str_eq(tmp->data, "qwerty");
	tmp = tmp->next;
	cr_assert_eq(tmp->data, 0);
}
