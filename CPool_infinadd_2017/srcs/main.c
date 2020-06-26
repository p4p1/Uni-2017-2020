/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for the infin_add
*/

#include "infin_add.h"

void display_value(char *res)
{
	my_putstr(my_revstr(res));
	my_putchar('\n');
}

static char *add_sign(char *res, int is_neg)
{
	char	*tmp_res = (char *)malloc((my_strlen(res) + 2) * sizeof(char));
	int	i = 0;

	if (res[0] == '0')
		return (res);
	if (is_neg)
		tmp_res[i++] = '-';
	while (*res != '\0')
		tmp_res[i++] = *res++;
	return (tmp_res);
}

static char *remove_zero(char *res)
{
	int	i = 0;

	for (i = my_strlen(res) - 1; i != 0 && res[i] == '0'; i--)
		res[i] = '\0';
	return (res);
}

char *infadd(char *v1, char *v2)
{
	char	*res = 0;
	char	*value1 = my_strdup(v1);
	char	*value2 = my_strdup(v2);
	int	si1 = 0;
	int	si2 = 0;
	int	is_neg = 0;

	si1 = get_sign(value1);
	si2 = get_sign(value2);
	is_neg = display_sign(&value1, &value2);
	my_revstr(value1);
	my_revstr(value2);
	res = add_values(value1, value2, si1, si2);
	res = remove_zero(res);
	res = add_sign(my_revstr(res), is_neg);
	return (res);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (84);
	my_putstr(infadd(argv[1], argv[2]));
	my_putchar('\n');
	return (0);
}
