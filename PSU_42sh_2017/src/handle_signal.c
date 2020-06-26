/*
** EPITECH PROJECT, 2018
** handle_signal.c
** File description:
** handle signal
*/

#include "my.h"

int handle_signal(int status)
{
	signal(SIGINT, manage_sig);
	if (WIFSIGNALED(status) && __WCOREDUMP(status)) {
		if (status == 139)
			my_putstr("Segmentation fault (core dumped)\n");
		if (status == 136)
			my_putstr("Floating exception (core dumped)\n");
	}
	if (WIFSIGNALED(status) && !__WCOREDUMP(status)) {
		if (status == 139)
			my_putstr("Segmentation fault\n");
		if (status == 136)
			my_putstr("Floating exception\n");
	}
	return (status);
}
