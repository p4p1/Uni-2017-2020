/*
** EPITECH PROJECT, 2017
** rush1-4.c
** File description:
** rush project.
*/

void my_putchar(char c);
void my_putstr_err(char const *str);
void disp_single_line(char ch, int x, int y);

void disp_top_and_bottom(int x)
{
	int	i = 0;

	my_putchar('A');
	while (i++ < (x-2)) {
		my_putchar('B');
	}
	my_putchar('C');
}

void disp_normal_line(int x)
{
	int	i = 0;

	my_putchar('B');
	while (i++ < (x-2))
		my_putchar(' ');
	my_putchar('B');
}

int disp_line(int x, int y, int current_line)
{
	if (x == 1 || y == 1) {
		disp_single_line('B', x, y);
		return (1);
	}
	if (current_line == 0) {
		disp_top_and_bottom(x);
	} else if (current_line == y-1) {
		disp_top_and_bottom(x);
	} else {
		disp_normal_line(x);
	}
	my_putchar('\n');
	return(0);
}

void rush(int x, int y)
{
	int	current_line = 0;

	if (x <= 0 || y <= 0) {
		my_putstr_err("Invalid size\n");
	} else {
		while (current_line < y) {
			if (disp_line(x, y, current_line))
				break;
			current_line += 1;
		}
	}
}
