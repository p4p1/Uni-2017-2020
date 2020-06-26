/*
** EPITECH PROJECT, 2017
** gnl.c
** File description:
** besta gnl
*/

#include "gnl.h"

int act = 1;

static int find_nl(char *str, int len)
{
	int	no = 0;

	for (no = 0; no < len; no++)
		if (str[no] == '\n')
			return (no);
	return (0);
}

static char *increase_buffer(char *str, int pos)
{
	char	*tmp = NULL;

	++act;
	tmp = malloc(sizeof(char) * (READ_SIZE * act));
	if (tmp == NULL)
		return (NULL);
	for (int i = 0; i < READ_SIZE * act; i++)
		tmp[i] = 0;
	for (int i = 0; i < pos; i++)
		tmp[i] = str[i];
	free(str);
	return (tmp);
}

static char *my_strdup_ln(const char *str, int ln)
{
	char	*buf = malloc(sizeof(char) * (ln + 1));
	int	i = 0;

	if (buf == NULL)
		return (NULL);
	for (i = 0; i < ln; i++)
		buf[i] = 0;
	if (str != NULL) {
		for (i = 0; str[i] && i < ln; i++)
			buf[i] = str[i];
		buf[i] = '\0';
	}
	return (buf);
}

static char *shifter(char *str, int *no)
{
	char	*tmp = my_strdup_ln(str, find_nl(str, *no));
	int	i = 0;
	int	end = find_nl(str, *no) + 1;

	if (tmp == NULL)
		return (NULL);
	if (end != *no) {
		for (i = 0; i < *no; i++)
			str[i] = str[i + end];
		str[i] = '\0';
	}
	*no = *no - end;
	return (tmp);
}

char *gnl(int fd)
{
	static char	*str = NULL;
	static int	pos = 0;
	char		*tmp = my_strdup_ln(NULL, READ_SIZE);
	int		no = 0;

	if (str == NULL)
		str = my_strdup_ln(NULL, READ_SIZE);
	if (str == NULL || tmp == NULL)
		return (NULL);
	while ((no = read(fd, tmp, READ_SIZE)) > 0) {
		if (pos + no > (READ_SIZE * act))
			str = increase_buffer(str, pos);
		for (int i = 0; i < no; i++)
			str[pos + i] = tmp[i];
		pos += no;
		if (find_nl(str, pos) || no == 0)
			break;
		free(tmp);
		tmp = my_strdup_ln(NULL, READ_SIZE);
	}
	return ((pos == 0) ? NULL : shifter(str, &pos));
}
