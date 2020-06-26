/*
** EPITECH PROJECT, 2017
** rush1-1.c
** File description:
** rush project.
*/

void my_putchar(char c);
void my_putstr_err(char const *str);
int disp_single_line(int x, int y);

/*
** flag = 0 -> last line
** flag = 1 -> top line
*/
void disp_top_and_bottom(int x, int flag)
{
	int	i = 0;

	if (flag)
		my_putchar('o');
	else
		my_putchar('o');
	while (i++ < (x-2)) {
		my_putchar('-');
	}
	if (flag)
		my_putchar('o');
	else
		my_putchar('o');
}

void disp_normal_line(int x)
{
	int	i = 0;

	my_putchar('|');
	while (i++ < (x-2))
		my_putchar(' ');
	my_putchar('|');
}

int disp_line(int x, int y, int current_line)
{
	if (x == 1 || y == 1) {
		disp_single_line(x, y);
		return (1);
	}
	if (current_line == 0) {
		disp_top_and_bottom(x, 1);
	} else if (current_line == y-1) {
		disp_top_and_bottom(x, 0);
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
