/*
** EPITECH PROJECT, 2017
** nm.h
** File description:
** <..>
*/

#ifndef NM_H_
#define NM_H_

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

typedef struct list {
	struct list	*next;
	Elf64_Sym	*sym;
} list_t;

list_t *add_to_list(Elf64_Sym *token);
void sort_list(list_t *list);

#endif
