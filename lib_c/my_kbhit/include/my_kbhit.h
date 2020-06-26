/*
** EPITECH PROJECT, 2017
** my_kbhit.h
** File description:
** The keyboard hit function
*/

#ifndef MY_KBHIT_H_
#define MY_KBHIT_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct kbhit_struct kbhit_t;

struct key
{
	char		ch;
	int		code;
};

struct kbhit_struct
{
	struct key	(*kbhit)(void);
	struct key	*root;
	int		fd;
}

kbhit_t *init_kbhit(void);
void destroy_kbhit(kbhit_t *);

#endif
