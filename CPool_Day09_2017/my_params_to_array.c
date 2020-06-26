/*
** EPITECH PROJECT, 2017
** my_params_to_array
** File description:
** my_params to struct
*/

#include <stdlib.h>
#include "include/my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
	struct info_param	*p_ip = malloc(sizeof(struct info_param) * ac);
	int	i = 0;
	char	*str_cpy = 0;

	while (i < ac) {
		p_ip[i].length = my_strlen(*(av+i));
		p_ip[i].str = *(av+i);
		str_cpy = malloc(sizeof(char) * my_strlen(*(av+i)));
		my_strcpy(str_cpy, *(av+i));
		p_ip[i].copy =  str_cpy;
		p_ip[i].word_array = my_str_to_word_array(str_cpy);
		++i;
	}
	p_ip[i].str = 0;
	return (p_ip);
}

