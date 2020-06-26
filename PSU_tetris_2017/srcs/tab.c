/*
** EPITECH PROJECT, 2017
** tab.c
** File description:
** <..>
*/

#include "tetris.h"

int call_tab(char ch, struct args *self)
{
	struct args *(*tab_func[])(struct args *) = {
		&argument_big_d, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		&argument_big_l, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, &argument_smo_d, NULL,
		NULL, NULL, &argument_smo_h, NULL, NULL, NULL, &argument_smo_l,
		&argument_smo_m, NULL, NULL, &argument_smo_p, &argument_smo_q,
		&argument_smo_r, NULL, &argument_smo_t, NULL, NULL,
		&argument_smo_w, NULL };

	if (ch == '?')
		return (-2);
	if (tab_func[ch - JUMP_TABLE_SUB](self) == NULL)
		return (-1);
	return (0);
}
