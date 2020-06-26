/*
** EPITECH PROJECT, 2017
** time.c
** File description:
** all time functions
*/

#include "my_ls.h"

void print_time(struct stat st)
{
	char	*time = ctime(&st.st_mtime);

	time[my_strlen(time) - 9] = '\0';
	my_printf(" %s", time + 4);
}
