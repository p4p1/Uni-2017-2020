/*
** EPITECH PROJECT, 2017
** signal_error.c
** File description:
** <..>
*/

#include "minishell.h"

void check_signal(int wstatus)
{
	if (WTERMSIG(wstatus) == SIGSEGV)
		my_printf("Segmentation fault (core dumped)\n");
}
