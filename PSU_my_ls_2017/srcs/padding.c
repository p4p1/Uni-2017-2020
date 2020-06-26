/*
** EPITECH PROJECT, 2017
** padding.c
** File description:
** padding functions
*/

#include "my_ls.h"

int set_padding(struct files *fi)
{
	int	pad = 0;
	struct stat	st;

	while (fi->next != 0) {
		stat(fi->file_name, &st);
		if (pad < number_len(st.st_size))
			pad = number_len(st.st_size);
		fi = fi->next;
	}
	return (pad);
}

void print_padding(int pad, int no)
{
	int	i = 0;

	pad -= number_len(no);
	for (i = 0; i <= pad; i++)
		my_putchar(' ');
	my_printf("%d", no);
}

char *dup_path(char *str, char *path)
{
	char	*src = (char *)malloc(sizeof(char) *
			(my_strlen(str) + my_strlen(path) + 2));
	int	i = 0;
	int	ji = 0;

	if (src == NULL)
		return (NULL);
	while (path != NULL && path[i] != '\0') {
		src[i] = path[i];
		++i;
	}
	if (path != NULL && src[i - 1] != '/')
		src[i++] = '/';
	while (str != NULL && str[ji] != '\0') {
		src[i] = str[ji];
		++i;
		++ji;
	}
	src[i] = '\0';
	return (src);
}
