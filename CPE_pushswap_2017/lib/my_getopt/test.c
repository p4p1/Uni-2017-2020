/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** <..>
*/

#include "my_getopt.h"

int main(int ac, char **av)
{
	char	ch = 0;

//	while ((ch = getopt(ac, av, "hl:")) != -1) {
//		switch (ch) {
//			case 'h':
//				printf("USAGE\n");
//				break;
//			case 'l':
//				printf("L FLAG: %s\n", optarg);
//				break;
//			case '?':
//				printf("WTF?: %c\n", optopt);
//				break;
//			default:
//				return (84);
//		}
//	}
//	printf("=============================\n");
	while ((ch = my_getopt(ac, av, "hl:")) != -1) {
		switch (ch) {
			case 'h':
				printf("USAGE\n");
				break;
			case 'l':
				printf("L FLAG: %s\n", my_optarg);
				break;
			case '?':
				printf("WTF?: %c\n", my_optopt);
				break;
			default:
				return (84);
		}
	}
	return (0);
}
