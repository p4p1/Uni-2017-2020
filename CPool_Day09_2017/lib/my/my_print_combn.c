/*
** EPITECH PROJECT, 2017
** my_print_combn
** File description:
**	the my_print_combn ex
*/

void my_putchar(char c);
int number_len(int nb);
int get_digit(int nb, int loc);
int init_max_and_num(int *start_num, int *max_no, int n);

int cn_check_no(int no)
{
	int	id = 0;
	int	i = 0;
	int	tmp;

	tmp = get_digit(no, number_len(no));
	while (i++ < number_len(no)) {
		if (get_digit(no, number_len(no) - i) < tmp)
			id++;
		tmp = get_digit(no, number_len(no) - i);
	}
	if (id == (number_len(no) - 1))
		return (1);
	return (0);
}

int cn_disp_no(int no, int n)
{
	int	dif, i;

	i = 0;
	dif = n - number_len(no);
	while (i++ < dif)
		my_putchar('0');
	i = 0;
	while (i < number_len(no))
		my_putchar(get_digit(no, i++) + '0');
	return (0);
}

int cn_check_over(int no, int n)
{
	int	i = 0;

	if (number_len(no) != n)
		return (0);
	while (i < n) {
		if (get_digit(no, ((number_len(no) - 1) - i)) >= 10 - (i + 1))
			++i;
		else
			return (0);
	}
	return (1);
}

int cn_disp_coma(int no, int n)
{
	if (cn_check_over(no, n))
		return (1);
	my_putchar(',');
	my_putchar(' ');
	return (0);
}

int my_print_combn(int n)
{
	int	num = 1;
	int	max_no = 1;

	if (n <= 0)
		return (-1);
	init_max_and_num(&num, &max_no, n);
	while (num < max_no) {
		if (cn_check_no(num)) {
			cn_disp_no(num, n);
			if (cn_disp_coma(num, n))
				break;
		}
		++num;
	}
	return (0);
}
