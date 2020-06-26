/*
** EPITECH PROJECT, 2017
** tree
** File description:
** tree TP function
*/

void my_putchar(char c);

/* enter 1 for last line and 0 for first line
**/
int get_line(int size, int wch_line)
{
	int	multi;
	int	first_line = 7;
	int	i = 1;

	if (wch_line) {
		multi = 6;
		first_line = 7;
	} else {
		multi = 4;
		first_line = 1;
	}
	while (i < size) {
		first_line += multi;
		if (i++ % 2)
			multi+=2;
	}
	return (first_line);
}

void display_content(int max_padding, int first_line, int inc)
{
	int	pad = 0;

	while (pad++ < max_padding) {
		my_putchar(' ');
	}
	pad = 0;
	while (pad++ < first_line+inc) {
		my_putchar('*');
	}
	my_putchar('\n');
}

void print_part(int part_no, int last_part)
{
	int	first_line = get_line(part_no, 0);
	int	max_padding = (get_line(last_part, 1) / 2) - first_line/2;
	int	no_line = 3+part_no;
	int	i = 0;
	int	inc = 0;

	while (i < no_line) {
		display_content(max_padding, first_line, inc);
		i++;
		inc += 2;
		max_padding--;
	}
}

void disp_trunk(int size)
{
	int	i = 0;
	int	ii = 0;
	int	trunck_size = 1;
	int	padding = get_line(size, 1) / 2;

	while (i < size)
		if (i++ % 2)
			trunck_size += 2;
	i = 0;
	padding -= (trunck_size/2);
	while (i++ < size) {
		ii = 0;
		while (ii++ < padding)
			my_putchar(' ');
		ii = 0;
		while (ii++ < trunck_size)
			my_putchar('|');
		my_putchar('\n');
	}
}

void tree(int size)
{
	int	i = 1;

	if (i > 0) {
		while (i <= size) {
			print_part(i, size);
			i++;
		}
		disp_trunk(size);
	}
}
