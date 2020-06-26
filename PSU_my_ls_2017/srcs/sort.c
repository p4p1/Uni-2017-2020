/*
** EPITECH PROJECT, 2017
** sort.c
** File description:
** sorting functions
*/

#include "my_ls.h"

static int cmp(char *str1, char *str2)
{
	char	*s1 = my_strdup(str1);
	char	*s2 = my_strdup(str2);
	int	len = (my_strlen(s1) < my_strlen(s2)) ?
				my_strlen(s1) : my_strlen(s2);
	int	i = 0;

	if (*s1 >= 'A' && *s1 <= 'Z')
		*s1 += 32;
	if (*s2 >= 'A' && *s2 <= 'Z')
		*s2 += 32;
	while (*s1 == *s2 && i++ < len) {
		++s1;
		++s2;
		if (*s1 >= 'A' && *s1 <= 'Z')
			*s1 += 32;
		if (*s2 >= 'A' && *s2 <= 'Z')
			*s2 += 32;
	}
	return (*s1 - *s2);
}

static void exchange(char **str1, char **str2)
{
	char	*tmp = *str1;

	*str1 = *str2;
	*str2 = tmp;
}

static void swap(struct files **fi, struct arguments *arg)
{
	struct stat	st;
	struct stat	st2;

	if (arg->r_fl && !arg->t_fl) {
		if (cmp((*fi)->file_name, (*fi)->next->file_name) < 0)
			exchange(&(*fi)->file_name, &(*fi)->next->file_name);
	} else if (arg->t_fl) {
		stat(dup_path((*fi)->file_name, (*fi)->path), &st);
		stat(dup_path((*fi)->next->file_name, (*fi)->next->path), &st2);
		if (!arg->r_fl && st.st_mtim.tv_sec <= st2.st_mtim.tv_sec)
			exchange(&(*fi)->file_name, &(*fi)->next->file_name);
		else if (arg->r_fl && st.st_mtim.tv_sec > st2.st_mtim.tv_sec)
			exchange(&(*fi)->file_name, &(*fi)->next->file_name);
	} else {
		if (cmp((*fi)->file_name, (*fi)->next->file_name) > 0)
			exchange(&(*fi)->file_name, &(*fi)->next->file_name);
	}
}

void sort(struct files **fi, struct arguments *arg)
{
	int		len = 0;
	int		i = 0;
	int		j = 0;
	struct files	*tmp = *fi;

	while (tmp->next != 0) {
		tmp = tmp->next;
		len++;
	}
	tmp = *fi;
	for (i = 0; i < len - 1; i++) {
		*fi = tmp;
		for (j = 0; j < len - i - 1; j++) {
			swap(fi, arg);
			(*fi) = (*fi)->next;
		}
	}
	*fi = tmp;
}
