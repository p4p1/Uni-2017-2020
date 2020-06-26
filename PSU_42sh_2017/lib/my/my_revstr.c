/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse copy
*/

int	my_strlen18(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*my_revstr(char *str)
{
	int compteur_start = 0;
	int compteur_end;
	char remp;

	compteur_end = (my_strlen18(str) - 1);
	while (compteur_start <= compteur_end) {
		remp = str[compteur_start];
		str[compteur_start] = str[compteur_end];
		str[compteur_end] = remp;
		compteur_start ++;
		compteur_end --;
	}
	return (str);

}
