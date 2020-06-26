/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** <..>
*/

#ifndef BSQ_H_
#define BSQ_H_

#include "my.h"
#include "my_fgets.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct s_bsq_class	bsq_class;

struct s_pos {
	int	x;
	int	y;
};

struct s_size {
	int	width;
	int	height;
};

struct s_bsq_class {
	struct s_pos	pos;
	struct s_pos	bigest_pos;
	struct s_size	size;
	char		**map;
	int		**sol;
	int		fd;
	char		*(*get_line)(bsq_class *);
	void		(*scan_line)(bsq_class *);
};

bsq_class *set_to_zero(bsq_class *);
bsq_class *init_bsq(int);
char *end_first_line(char *, int);
int valid_line(char *, int);
int algo(bsq_class *);
void set_solution(bsq_class *);

#endif
