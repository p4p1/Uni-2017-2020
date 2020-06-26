/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** <..>
*/

#include "clist.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	struct queue	*root = NULL;
	char	*str = strdup("PUTEZER");

	root = add_queue(root, (void *)str);
	printf("%p\n", root);
	root = add_queue(root, (void *)str);
	printf("%p\n", root->next);
	pop_queue(&root);
	printf("%p\n", root);
	free(str);
}
