/*
** EPITECH PROJECT, 2017
** exo-1.h
** File description:
** <..>
*/

#ifndef EX00_H_
#define EX00_H_

typedef struct s_cthulhu {
	int	m_power;
	char	*m_name;
} cthulhu_t;

typedef struct s_koala {
	cthulhu_t	m_parent;
	char		m_is_a_legend;
} koala_t;

cthulhu_t *new_cthulhu();
koala_t *new_koala(char *name, char is_a_legend);
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);
void eat(koala_t *this);

#endif
