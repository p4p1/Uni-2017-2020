/*
** EPITECH PROJECT, 2017
** sort.c
** File description:
** <..>
*/

#include "tetris.h"

static void swap(struct queue *en1, struct queue *en2)
{
	void	*tmp = NULL;

	tmp = en1->token;
	en1->token = en2->token;
	en2->token = tmp;
}

static void sort(struct queue *qu, int j, int size)
{
	struct shapes	*el1 = NULL;
	struct shapes	*el2 = NULL;

	for (int i = 0; i < size - j - 1; i++) {
		el1 = qu->token;
		el2 = qu->next->token;
		if (el1->name[0] > el2->name[0])
			swap(qu, qu->next);
		qu = qu->next;
	}
}

void bubble_sort(struct queue *qu)
{
	struct shapes	*el = NULL;
	int		size = 0;

	if (qu == NULL)
		return;
	el = qu->token;
	size = el->no;
	for (int i = 0; i < size; i++) {
		sort(qu, i, size);
	}
}
