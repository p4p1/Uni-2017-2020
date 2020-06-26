/*
** EPITECH PROJECT, 2017
** my_malloc.h
** File description:
** <..>
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>
#include <string.h>
#include <stddef.h>

#define PAGE_SIZE (getpagesize())

typedef struct alloc_s
{
	size_t		size;
	size_t		free_size;
	unsigned int	is_free;
	void		*current;
	struct alloc_s	*next;
	struct alloc_s	*prev;
} alloc_t;

void add_before_current(alloc_t *ptr);
void add_after_current(alloc_t *ptr);

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

void show_alloc_mem(void);

void my_putstr(char *);
void my_putnbr_base_local(unsigned long nbr, char const *base);
void my_putchar(char);
void disp_node(alloc_t *ptr);

alloc_t *alloc_list;
alloc_t *alloc_list_start;

#endif
