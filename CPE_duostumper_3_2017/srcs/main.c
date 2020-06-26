/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "cesar.h"

static cesar_t *arg_handle(cesar_t *self, char **ch)
{
	if (ch[1][1] == 'f') {
		self->fp = open(ch[2], O_RDONLY);
		if (self->fp < 0)
			return (NULL);
	} else if (ch[1][1] == 's') {
		self->str = my_strdup(ch[2]);
		if (self->str == NULL)
			return (NULL);
	} else {
		return (NULL);
	}
	return (self);
}

static cesar_t *init(int ac, char **av)
{
	cesar_t	*self = malloc(sizeof(cesar_t));

	if (self == NULL)
		return (NULL);
	my_memset(self, 0, sizeof(cesar_t));
	if (ac != 4)
		return (NULL);
	if (my_strlen(av[1]) != 2 || arg_handle(self, av) == NULL)
			return (NULL);
	self->number = my_atoi(av[3]);
	return (self);
}

static int get_file(int fd, cesar_t *cesar)
{
	char	*str = malloc(sizeof(char) * BUFSIZ);

	if (str == NULL)
		return (FAILED);
	while (read(cesar->fp, str, BUFSIZ) > 0) {
		for (int i = 0; i < BUFSIZ; i++)
			write_char(fd, cesar_move(str[i], cesar));
	}
	free(str);
	return (SUCCESS);
}

static void destroy(cesar_t *self)
{
	if (self->fp > 0)
		close(self->fp);
	if (self->str != NULL)
		free(self->str);
	free(self);
}

int main(int ac, char **av)
{
	cesar_t	*cesar = init(ac, av);
	int	fd = open(FILE_NAME, O_WRONLY | O_TRUNC | O_CREAT, 0444);

	if (cesar == NULL || fd < 0)
		return (FAILED);
	if (cesar->str == NULL) {
		get_file(fd, cesar);
	} else {
		for (int i = 0; cesar->str[i]; i++)
			write_char(fd, cesar_move(cesar->str[i], cesar));
		write_char(fd, '\n');
	}
	destroy(cesar);
	close(fd);
	return (SUCCESS);
}
