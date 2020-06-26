/*
** EPITECH PROJECT, 2017
** cesar.h
** File description:
** <..>
*/

#ifndef CESAR_H_
#define CESAR_H_

#include "my.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SUCCESS (0)
#define FAILED (84)
#define FILE_NAME ("crypt")

typedef struct cesar_info {
	char	*str;
	int	fp;
	int	number;
}	cesar_t;

char cesar_move(char ch, cesar_t *self);
void write_char(int fp, char ch);

#endif
