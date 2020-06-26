/*
** EPITECH PROJECT, 2017
** grep
** File description:
** the grep command line func
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"

void my_putchar_err(char c);
void my_putstr_err(char *str);

int str_in_buf(char *buf, char *str)
{
	int	i = 0;
	int	j = 0;
	int	len_str = my_strlen(str);

	while (*(buf+i) != '\0') {
		for (j = 0; buf[i+j] == str[j]; j++)
			;
		if (j == len_str)
			return (1);
		i++;
	}
	return (0);
}

void read_from_file(int fd, char *str)
{
	char	buf[30];
	int	i = 0;

	for (i = 0; i < 30; i++)
		buf[i] = 0;
	while (read(fd, buf, 29) > 0) {
		if (str_in_buf(buf, str))
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

	for (i = 2; i < ac; i++) {
		fd = open(av[i], O_RDONLY);
		if (fd < 0) {
			my_putstr_err("grep: No such file or directory.\n");
			err = -1;
		} else {
			read_from_file(fd, av[1]);
		}
	}
	return (err);
}

int main(int ac, char **av)
{
	if (ac == 2) {
		read_from_file(0, av[1]);
	} else {
		if (get_args(ac, av) < 0) {
			return (84);
		}
	}
	return (0);
}
