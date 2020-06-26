/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file
*/

#include "include/rush2.h"

int main(int ac, char **av)
{
	char	args[ac];
	int	i = 0;
	int	percentage = 0;
	int	nb_occurence = 0;

	if (ac < 3 || my_strlen(av[1]) < 1) {
		my_putstr_err("Error: Not enougth arguments.\n");
		return (84);
	}
	get_args(ac, args, av);
	while (i < my_strlen(args)) {
		nb_occurence = get_occurence(av[1], args[i]);
		percentage = calculate_percentage(av[1], args[i]);
		display_single_occurence(args[i], nb_occurence, percentage);
		i++;
	}
	language_check(av[1]);
	return (0);
}
