/*
** EPITECH PROJECT, 2017
** getlen.c
** File description:
** Get the length of the double array
*/
#include "rush3.h"

int get_len(char **str)
{
	int count = 1;
	int line_size = 0;
	int initial_size = my_strlen(str[0]);

	while(str[count] != 0) {
		line_size = my_strlen(str[count]);
		if(line_size != initial_size){
			return(-1);
		}
		count = count + 1;
	}
	return(count);
}

