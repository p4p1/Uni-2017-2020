/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** the header of get_next_line function
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
#	define READ_SIZE (1024)
#endif

char *get_next_line(int);

#endif
