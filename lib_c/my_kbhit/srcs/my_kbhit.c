/*
** EPITECH PROJECT, 2017
** my_kbhit.c
** File description:
** the main init and destroy function
*/

#include "my_kbhit.h"

kbhit_t *init_kbhit(void)
{
	kbhit_t	*self = (kbhit_t *)malloc(sizeof(kbhit_t));

	if (self == NULL)
		return (NULL);
	self->fd = open("/dev/input/event3", O_RDONLY);
	if (self->fd < 0)
		return (NULL);
	self->root = (struct key *)malloc(sizeof(struct key) * 26);
	if (self->root == NULL)
		return (NULL);
	return (self);
}

void destroy_kbhit(kbhit_t *kbhit)
{
	free(kbhit);
}
