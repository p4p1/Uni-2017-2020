/*
** EPITECH PROJECT, 2017
** n4s.h
** File description:
** <..>
*/

#ifndef N4S_H_
#define N4S_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my.h"

typedef struct info {
	char	*code_str;
	char	*argument;
	char	*additional_info;
	int	valude_id;
	bool	status;
} info_t;

int is_valid_line(char *str);
void check_code(int err);
info_t *get_info(char *str);
int race(char *str);
void race_end(char *str);
void disp_info(info_t *info);
int lidar_info(char *str, double *array);
void change_dir(double *array, char *str, size_t size);

#endif
