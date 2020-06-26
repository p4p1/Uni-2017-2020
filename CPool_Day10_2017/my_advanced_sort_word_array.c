/*
** EPITECH PROJECT, 2017
** my_advanced_sort_word_array
** File description:
** sort an array with a given function
*/

void my_putchar(char c);

void adv_is_smaller(char **tab, int ii, int(*cmp)(char *, char *))
{
	char	*temp;
	if (cmp(tab[ii], tab[ii+1])) {
		temp = tab[ii];
		tab[ii] = tab[ii+1];
		tab[ii+1] = temp;
	}
}

int adv_get_tab_len(char **tab)
{
	int	len = 0;

	while (tab[len] != 0)
		len++;
	return (len);
}

int my_advanced_sort_word_array(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	ii;
	int	size = adv_get_tab_len(tab);

	if (tab == 0)
		return (0);
	while (i < (size - 1)) {
		ii = 0;
		while (ii < (size - i - 1)) {
			adv_is_smaller(tab, ii, cmp);
			++ii;
		}
		++i;
	}
	return (0);
}
