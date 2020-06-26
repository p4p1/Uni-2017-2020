/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** The get_next_line function source code
*/

#include "get_next_line.h"

static char *create_buf(int size)
{
	char	*buf = (char *)malloc(sizeof(char) * (size + 1));
	int	i = 0;

	if (buf == NULL)
		return (NULL);
	while (i < (size + 1))
		buf[i++] = 0;
	return (buf);
}

static char *expand_buf(char *buf, int size)
{
	char	*tmp_buf = create_buf(size);
	int	i = 0;

	if (tmp_buf == NULL)
		return (NULL);
	for (i = 0; i < size; i++) {
		tmp_buf[i] = buf[i];
	}
	tmp_buf[i] = '\0';
	free(buf);
	return (tmp_buf);
}

static int is_line(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n') {
			return (i);
		}
	}
	return (0);
}

static char *trunk_new_line(char **str, int *tmp_no)
{
	int	pos = is_line(*str);
	int	i = 0;
	char	*line = (char *)malloc(sizeof(char) * (pos + 1));

	if (line == NULL || pos == 0)
		return (NULL);
	for (i = 0; i < pos; i++)
		line[i] = (*str)[i];
	line[i] = '\0';
	pos++;
	if ((*str)[i + 1] == '\0') {
		*str = NULL;
		*tmp_no = 0;
	} else {
		for (i = 0; i < *tmp_no; i++)
			(*str)[i] = (*str)[i + pos];
		(*str)[i] = '\0';
		*tmp_no -= pos;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char	*buf = NULL;
	static int	tmp_no = 0;
	char		*tmp_buf = create_buf(READ_SIZE + 1);
	int		no = 0;

	if (buf == NULL)
		buf = create_buf(READ_SIZE);
	if (buf == NULL || tmp_buf == NULL || fd < 0)
		return (NULL);
	while ((no = read(fd, tmp_buf, READ_SIZE)) > 0) {
		if ((tmp_no + no) >= READ_SIZE)
			buf = expand_buf(buf, (tmp_no + no));
		for (int i = tmp_no; i < (tmp_no + no); i++)
			buf[i] = tmp_buf[i - tmp_no];
		tmp_no += no;
		if (is_line(tmp_buf))
			break;
		free(tmp_buf);
		tmp_buf = create_buf(READ_SIZE + 1);
	}
	return ((no > 0 || buf != NULL)? trunk_new_line(&buf, &tmp_no) : NULL);
}
