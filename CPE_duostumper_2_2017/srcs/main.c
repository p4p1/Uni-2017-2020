/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "connect4.h"

static int can_place(char **map, int pos)
{
	for (int i = 0; map[i]; i++) {
		if (map[i][pos] == '.')
			return (1);
	}
	return (0);
}

static int place_char(struct game *gm, char player, int pos)
{
	int	i = 0;

	while (i < gm->height && gm->map[i][pos] == '.')
		i++;
	gm->map[i - 1][pos] = player;
	return (is_winner(gm, pos, i - 1, player));
}

static int place(struct game *gm, int *no, int pl)
{
	int	ret = 0;

	if (pl < 0 || pl > gm->width || !can_place(gm->map, pl)) {
		my_printf("Row out of range.\n");
	} else {
		ret = place_char(gm, (*no % 2) ? gm->p1 : gm->p2, pl);
		if (ret == 0)
			*no += 1;
		display_map(gm);
	}
	return (ret);
}

static void game_loop(struct game *gm, char *str)
{
	int	no = 1;
	int	pl = 0;

	while (!is_over(gm)) {
		my_printf("Player %c, where do you want to play: ",
				(no % 2) ? gm->p1 : gm->p2);
		str = my_fgets(str, BUFSIZ, 0);
		if (str == NULL)
			break;
		pl = my_atoi(str) - 1;
		if(place(gm, &no, pl) == 1) {
			my_printf("Congrats, player %c won!\n",
					(no % 2) ? gm->p1 : gm->p2);
			break;
		}
	}
}

int main(int ac, char **av)
{
	struct game	*gm = init(ac, av);
	char	*str = malloc(sizeof(char) * BUFSIZ);

	if (gm == NULL || str == NULL)
		return (84);
	game_loop(gm, str);
	if (is_over(gm)) {
		my_printf("It’s a tie, nobody wins.\n");
	}
	destroyer(gm);
	return (0);
}
