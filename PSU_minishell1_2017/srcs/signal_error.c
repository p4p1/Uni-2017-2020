/*
** EPITECH PROJECT, 2017
** signal_error.c
** File description:
** <..>
*/

#include "minishell.h"

void check_signal(int wstatus)
{
	if (WTERMSIG(wstatus)) {
		if (WTERMSIG(wstatus) == SIGABRT)
			my_pustr_err("Aborted");
		if (SIGSEGV == WTERMSIG(wstatus))
			my_pustr_err("Segmentation fault");
		if (WTERMSIG(wstatus) == SIGBUS)
			my_pustr_err("Bus error");
		if (WTERMSIG(wstatus) == SIGFPE)
			my_pustr_err("Floating exception");
		my_pustr_err((WCOREDUMP(wstatus)) ? " (core dumped)\n" : "\n");
	}
}
