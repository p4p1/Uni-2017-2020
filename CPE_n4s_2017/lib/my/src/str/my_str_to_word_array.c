/*
** EPITECH PROJECT, 2018
** str_to_word_array
** File description:
** slipt a whole string into words
*/

#include "my.h"
#include <stdio.h>

int count_words(char const *str)
{
	int words = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ':' || str[i] == '\n')
			words++;
	}
	return (words);
}

char **my_str_to_array(char const *str)
{
	int len = 0;
	int k = 0;
	int words = count_words(str);
	char **new_str = malloc(sizeof(char *) * (words + 1));

	for (int i = 0; i < words + 1; i++) {
		for (len = 0; str[k] != '\0' &&
		str[k] != ':' && str[k] != '\n'; k++, len++);
		new_str[i] = malloc(sizeof(char) * (len + 1));
		k++;
	}
	return (new_str);
}

char **my_str_to_word_array(char const *str)
{
	char **new_str = my_str_to_array(str);
	int j = 0;

	for (int i = 0, x = 0; i < my_strlen(str); i++, x++) {
		if (str[i] == ':' || str[i] == '\n') {
			i++;
			new_str[j][x] = '\0';
			j = j + 1;
			x = 0;
		}
		new_str[j][x] = str[i];
	}
	new_str[j] = NULL;
	return (new_str);
}
