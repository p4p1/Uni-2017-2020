/*
** EPITECH PROJECT, 2017
** concat_params
** File description:
** contact the parameters given and add \n between each parameter
*/

#include <stdlib.h>

#include "include/libmy.h"

void my_putchar(char c);

char *concat_params(int argc, char **argv)
{
	int	total_len = 0;
	int	i = -1;
	char	*final_str = 0;

	if (argc <= 0 || argv == 0)
		return (0);
	while (++i < argc)
		total_len += my_strlen(*(argv+i));
	i = 0;
	final_str = (char *)malloc(sizeof(char) + total_len + argc);
	while (i < argc) {
		my_strcat(final_str, *(argv+i));
		if (my_strlen(*(argv+i)) != 0)
			my_strncat(final_str, "\n", 1);
		++i;
	}
	return (final_str);
}
