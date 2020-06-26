/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "rush3.h"

#define BUFF_SIZE (4096)

int main(void)
{
	char	buff[BUFF_SIZE + 1];
	int	offset = 0;
	int	len;

	while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
		offset += len;
		if (offset >= (BUFF_SIZE))
			break;
	}
	if (offset < (BUFF_SIZE))
		buff[offset] = '\0';
	if (len < 0)
		return (84);
	if (offset < (BUFF_SIZE))
		rush3(buff);
	else
		write(2, "none\n", 5);
	return (0);
}
