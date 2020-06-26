/*
** EPITECH PROJECT, 2017
** my_print_comb
** File description:
** the my_print_comb ex
*/

void my_putchar(char c);
int number_len(int nb);
int get_digit(int nb, int loc);

int c_check_no(int no)
{
	int	id = 0;
	int	i = 0;
	int	tmp;

	tmp = get_digit(no, number_len(no));
	while (i++ < number_len(no)) {
		if (get_digit(no, number_len(no) - i) < tmp)
			id++;
		tmp = get_digit(no, number_len(no)-i);
	}
	if (id == number_len(no)-1)
		return (1);
	return (0);
}

int c_disp_no(int no)
{
	int	dif;
	int	i = 0;

	dif = 3 - number_len(no);
	while (i++ < dif)
		my_putchar('0');
	i = 0;
	while (i < number_len(no))
		my_putchar(get_digit(no, i++) + '0');
	return (0);
}

int c_check_over(int no)
{
	int	i = 0;

	if (number_len(no) != 3)
		return (0);
	while (i < 3) {
		if (get_digit(no, ((number_len(no) - 1) - i)) >= 10 - (i + 1))
			i++;
		else
			return (0);
	}
	return (1);
}

int c_disp_coma(int no)
{
	if (c_check_no(no)) {
		if (c_check_over(no))
			return (1);
		my_putchar(',');
		my_putchar(' ');
	}
	return (0);
}

int my_print_comb()
{
	int	num = 10;

	while (num < 1000) {
		if (c_check_no(num)) {
			c_disp_no(num);
		}
		if (c_disp_coma(num))
			break;
		num++;
	}
	return (0);
}
