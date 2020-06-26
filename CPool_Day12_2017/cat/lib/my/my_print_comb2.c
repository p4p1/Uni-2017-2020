/*
** EPITECH PROJECT, 2017
** my_print_comb2
** File description:
**	the my_print_comb2 ex
*/

void my_putchar(char c);
int number_len(int nb);
int get_digit(int nb, int loc);

int c2_disp_no(int no)
{
	int	dif = 0;
	int	i = 0;
	int	ch_count = 0;

	dif = 4 - number_len(no);
	while (i++ < dif) {
		my_putchar('0');
		ch_count++;
		if (ch_count == 2)
			my_putchar(' ');
	}
	i = 0;
	while (i < number_len(no)) {
		my_putchar(get_digit(no, i++) + '0');
		ch_count++;
		if (ch_count == 2)
			my_putchar(' ');
	}
	return (0);
}

int c2_disp_coma(int no)
{
	if (no == 9899)
		return (1);
	my_putchar(',');
	my_putchar(' ');
	return (0);
}

int c2_inc_hundred(int *num, int *dum_inc)
{
	if (!(*num % 100)) {
		*num += *dum_inc;
		*dum_inc += 1;
	}
	return (0);
}

int my_print_comb2()
{
	int	num = 1;
	int	dum_inc = 2;

	while (num < 10000) {
		c2_inc_hundred(&num, &dum_inc);
		c2_disp_no(num);
		if (c2_disp_coma(num))
			break;
		num++;
	}
	return (0);
}
