/*
** EPITECH PROJECT, 2017
** cesar.c
** File description:
** <..>
*/

#include "cesar.h"

static char move_cap_char(char ch, cesar_t *self)
{
	int	flag = (self->number > 0) ? 0 : 1;

	for (int i = 0; flag == 0 && i < self->number; i++) {
		ch++;
		if (ch > 'Z')
			ch = 'A';
	}
	for (int i = 0; flag == 1 && i < (self->number * -1); i++) {
		ch--;
		if (ch < 'A')
			ch = 'Z';
	}
	return (ch);
}

static char move_smol_char(char ch, cesar_t *self)
{
	int	flag = (self->number > 0) ? 0 : 1;

	for (int i = 0; flag == 0 && i < self->number; i++) {
		ch++;
		if (ch > 'z')
			ch = 'a';
	}
	for (int i = 0; flag == 1 && i < (self->number * -1); i++) {
		ch--;
		if (ch < 'a')
			ch = 'z';
	}
	return (ch);
}

char cesar_move(char ch, cesar_t *self)
{
	if (ch >= 'A' && ch <= 'Z')
		return (move_cap_char(ch, self));
	if (ch >= 'a' && ch <= 'z')
		return (move_smol_char(ch, self));
	return (ch);
}
