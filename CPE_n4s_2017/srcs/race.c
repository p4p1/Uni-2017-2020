/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** all about the race
*/

#include "n4s.h"
#include "gnl.h"

void change_dir(double *array, char *str, size_t size)
{
	if (array[0] >= (array[31] + 400.0)) {
		write(1, "wheels_dir:0.2\n", 15);
		getline(&str, &size, stdin);
	}
	else if ((array[0] + 400.0) <= array[31]) {
		write(1, "wheels_dir:-0.2\n", 16);
		getline(&str, &size, stdin);
	}
	if (array[0] >= (array[31] - 7.0)) {
		write(1, "wheels_dir:0.0\n", 15);
		getline(&str, &size, stdin);
	}
	/*else if ((array[0] - 5.0) <= array[31]) {
		write(1, "wheels_dir:0.0\n", 15);
		getline(&str, &size, stdin);
	}*/
}

int lidar_info(char *str, double *array)
{
	char **buffer = my_str_to_word_array(str);
	int nbr = 0;

	for (nbr = 0; buffer[nbr] != NULL; nbr++);
	if (nbr == 36 || nbr == 37) {
		for (int i = 3, index = 0; i < 35; i++, index++)
			array[index] = atof(buffer[i]);
	}
	return(0);
}

void race_end(char *str)
{
	if (strstr(str, "Track Clear") != NULL) {
		write(1, "car_forward:0.0\n", 16);
		write(1, "stop_simulation\n", 16);
	}
}
