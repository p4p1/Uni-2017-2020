/*
** EPITECH PROJECT, 2017
** %
** File description:
** <..>
*/

void my_sort_char_array(char **tab, int size);

int main(int ac, char **av)
{
	int	i = 0;

	my_sort_char_array(av, ac);
	while (i < ac) {
		my_putstr(*(av+i));
		my_putchar('\n');
		i++;
	}
}
