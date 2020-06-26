/*
** EPITECH PROJECT, 2017
** my_sort_word_array
** File description:
** sort a array of strings
*/

void my_putchar(char c);

void is_smaller(char **tab, int ii)
{
	char	*temp;
	if (tab[ii][0] > tab[ii+1][0]) {
		temp = tab[ii];
		tab[ii] = tab[ii+1];
		tab[ii+1] = temp;
	}
}

int get_tab_len(char **tab)
{
	int	len = 0;

	while (tab[len] != 0)
		len++;
	return (len);
}

int my_sort_word_array(char **tab)
{
	int	i;
	int	ii;
	int	size = get_tab_len(tab);

	if (tab == 0)
		return (0);
	while (i < (size - 1)) {
		ii = 0;
		while (ii < (size - i - 1)) {
			is_smaller(tab, ii);
			++ii;
		}
		++i;
	}
	return (0);
}

