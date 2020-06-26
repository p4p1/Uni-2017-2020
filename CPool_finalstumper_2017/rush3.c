/*
** EPITECH PROJECT, 2017
** rush3.c
** File description:
** the main file for the rush3
*/

#include "rush3.h"

void display_rush(int no, int width, int height, int counter)
{
	if (counter != 0)
		my_putstr(" || ");
	my_putstr("[rush1-");
	my_put_nbr(no);
	my_putstr("] ");
	my_put_nbr(width);
	my_putchar(' ');
	my_put_nbr(height);
}

int check_shape(char **str, int height, int fp_index, int *nb)
{
	int	i = 0;
	char	*(*rush_l[])(int, int, int) = { &rush1_line, &rush2_line,
		&rush3_line, &rush4_line, &rush5_line, 0};
	char	*tmp_str = 0;

	for (i = 0; str[i] != 0; i++) {
		tmp_str = rush_l[fp_index](my_strlen(str[i]), height, i);
		if (my_strcmp(tmp_str, str[i]) != 0) {
			return (0);
		}
	}
	display_rush((fp_index + 1), my_strlen(str[0]), height, *nb);
	*nb += 1;
	return (i);
}

void rush3(char *str)
{
	char	**buf = my_str_to_word_array(str);
	int	width = my_strlen(buf[0]);
	int	height = get_len(buf);
	int	i = 0;
	int	nbr_displayed = 0;
	char	*(*rush_l[])(int, int, int) = { &rush1_line, &rush2_line,
		&rush3_line, &rush4_line, &rush5_line, 0};

	if (height > 0 && width > 0) {
		for (i = 0; rush_l[i] != 0; i++) {
			check_shape(buf, height, i, &nbr_displayed);
		}
		if (nbr_displayed)
			my_putchar('\n');
	} else {
		write(2, "none\n", 5);
	}
}
