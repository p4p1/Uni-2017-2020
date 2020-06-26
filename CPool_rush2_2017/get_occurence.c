/*
** EPITECH PROJECT, 2017
** get_occurence.c
** File description:
** get_occurence file git
*/

#include "include/rush2.h"

char set_to_lower_case(char *str, char letter)
{
	int	i = 0;

	if (letter >= 'A' && letter <= 'Z')
		letter += 32;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i += 1;
	}
	return (letter);
}

int calculate_percentage(char *str, char letter)
{
	int	i = 0;
	int	nombre_de_lettre = 0;

	letter = set_to_lower_case(str, letter);
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z')
			nombre_de_lettre++;
		i += 1;
	}
	if (nombre_de_lettre <= 0)
		return (0);
	return (get_occurence(str, letter)*10000 / nombre_de_lettre * 10);
}

int get_occurence(char *str, char letter)
{
	int	i = 0;
	int	len = 0;

	letter = set_to_lower_case(str, letter);
	while (str[i] != '\0') {
		if (str[i] == letter)
			len++;
		i += 1;
	}
	return (len);
}
