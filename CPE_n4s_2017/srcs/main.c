/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "n4s.h"
#include "gnl.h"

int main(void)
{
	char	*str = NULL;
	size_t size = 0;
	double array[32];

	write (1, "start_simulation\n", 17);
	getline(&str, &size, stdin);
	while (1) {
		write(1, "car_forward:0.5\n", 16);
		getline(&str, &size, stdin);
		race_end(str);
		write(1, "get_info_lidar\n", 15);
		getline(&str, &size, stdin);
		lidar_info(str, array);
		change_dir(array, str, size);
	}
	return (0);
}
