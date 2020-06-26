/*
** EPITECH PROJECT, 2017
** nolen and get_digit
** File description:
**	Util functions for all my_print_comb functions
*/

int number_len(int nb)
{
	int	len = 0;
	int	n = nb;

	while (n != 0) {
		n /= 10;
		len++;
	}
	return (len);
}

int get_digit(int nb, int loc)
{
	int	size;
	int	i = 0;

	size = number_len(nb) - (loc + 1);
	while (i++ < size)
		nb /= 10;
	return (nb % 10);
}

int init_max_and_num(int *start_num, int *max_no, int n)
{
	int	i = 0;

	while (i++ < (n - 2))
		*start_num *= 10;
	i = 0;
	while (i++ < n)
		*max_no *= 10;
	return (0);
}
