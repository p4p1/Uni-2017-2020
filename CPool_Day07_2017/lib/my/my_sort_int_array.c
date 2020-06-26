/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** my_sort_int_array file
*/

void my_putchar(char c);

int tab_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (0);
}

void is_smaller(int *tab, int ii)
{
	if (tab[ii] > tab[ii+1]) {
		tab_swap(&tab[ii], &tab[ii+1]);
	}
}

void last_loop(int size, int *tab, int i)
{
	int	ii = 0;

	while (ii < (size - i - 1)) {
		is_smaller(tab, ii);
		++ii;
	}
}

void my_sort_int_array(int *tab, int size)
{
	int	i;

	if (tab != 0 && size > 0) {
		while (i < (size - 1)) {
			last_loop(size, tab, i);
			++i;
		}
	}
}
