/*
** EPITECH PROJECT, 2017
** add_queue.c
** File description:
** add a token to the queue
*/

#include "clist.h"
#include <stdio.h>

void add_queue(struct queue **root, char *value)
{
	struct queue	*data = (struct queue *)malloc(sizeof(struct queue));
	struct queue	*tmp_s = (*root);
	char		*temp_value = my_strdp(value);

	if ((*root) == NULL) {
		(*root) = data;
		(*root)->token = temp_value;
		(*root)->next = NULL;
	} else {
		while (tmp_s->next != NULL)
			tmp_s = tmp_s->next;
		data->token = temp_value;
		data->next = NULL;
		tmp_s->next = data;
	}
}
