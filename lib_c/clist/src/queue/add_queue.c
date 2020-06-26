/*
** EPITECH PROJECT, 2017
** add_queue.c
** File description:
** <..>
*/

#include "clist.h"

struct queue *add_queue(struct queue *root, void *value)
{
	struct queue	*new = (struct queue *)malloc(sizeof(struct queue));
	static struct queue	*tmp = NULL;

	if (new == NULL)
		return (NULL);
	new->token = value;
	new->next = NULL;
	if (root == NULL) {
		tmp = new;
		return (new);
	}
	tmp->next = new;
	tmp = new;
	return (root);
}
