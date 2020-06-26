/*
** EPITECH PROJECT, 2017
** cat
** File description:
** cat a file
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"

void my_putchar_err(char c)
{
	write(2, &c, 1);
}

void my_putstr_err(char *str)
{
	while (*str != 0) {
		my_putchar_err(*str);
		str++;
	}
}

void read_from_file(int fd)
{
	char	buf[30];
	int	i = 0;

	for (i = 0; i < 30; i++)
		buf[i] = 0;
	while (read(fd, buf, 29) > 0) {
		my_putstr(buf);
		for (i = 0; i < 30; i++)
			buf[i] = 0;
	}
}

int get_args(int ac, char **av)
{
	int	fd = 0;
	int	i = 0;
	int	err = 0;

	for (i = 1; i < ac; i++) {
		fd = open(av[i], O_RDONLY);
		if (fd < 0) {
			my_putstr_err("cat: No such file or directory.\n");
			err = -1;
		} else {
			read_from_file(fd);
		}
	}
	return (err);
}

int main(int ac, char **av)
{
	if (ac < 2) {
		read_from_file(0);
	} else {
		if (get_args(ac, av) < 0) {
			return (84);
		}
	}
	return (0);
}
