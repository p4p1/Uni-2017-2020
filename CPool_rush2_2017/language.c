/*
** EPITECH PROJECT, 2017
** language.c
** File description:
** language_check file
*/

#include "include/rush2.h"

int get_lang_percent(char *str, int lang_c)
{
	char	lang[5][26] = { {"taoinsrhldcumfpgwybvkxjqz\0"},
		{"saitnrulodcmpvqfbghjxy\0"},
		{"nisratdhulcgmobwfkzvupbj\0"},
		{"aosrnidlctumpbgyivqohfzj\0"}, {0} };
	int	i = 0;
	int	percent = 0;

	while (i < 26) {
		percent += calculate_percentage(str, lang[lang_c][i]);
		i++;
	}
	return (percent);
}

int percentage_is_better(char *str)
{
	int	lang_c = 0;
	int	percent = 0;
	int	t_lang = 0;

	for (lang_c = 0; lang_c < 3; lang_c++) {
		percent = get_lang_percent(str, lang_c);
		if (percent > get_lang_percent(str, t_lang))
			t_lang = lang_c;
	}
	return (t_lang);
}

void language_check(char *str)
{
	switch (percentage_is_better(str)) {
		case 0:
			my_putstr("=> English");
			break;
		case 1:
			my_putstr("=> French");
			break;
		case 2:
			my_putstr("=> German");
			break;
		case 3:
			my_putstr("=> Spanish");
			break;
	}
}
