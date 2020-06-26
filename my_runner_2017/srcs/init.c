/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "my_runner.h"

static int create_texture(struct game *gm)
{
	gm->bg = (background_t **)malloc(sizeof(background_t *) *
			BACKGROUND_NO);
	if (gm->bg == NULL)
		return (-1);
	gm->bg[0] = create_background(0, 0, SKY);
	gm->bg[1] = create_background(0, 379, GRASS);
	gm->bg[2] = create_background(0, 0, MARIO);
	gm->bg[3] = create_background(1080, 0, SKY);
	gm->bg[4] = create_background(1080, 379, GRASS);
	gm->bg[5] = create_background(1080, 0, MARIO);
	gm->btn_start = create_button(350, 300);
	gm->btn_info = create_info_button(590, 300);
	gm->title = create_title(400, 200);
	gm->death_title = create_death_title(400, 200);
	return (0);
}

static void create_music_sound_font(struct game *gm)
{
	sfFont	*fnt = sfFont_createFromFile("./res/font.ttf");
	sfVector2f	pos;

	pos.x = 0;
	pos.y = 0;
	gm->music = sfMusic_createFromFile("./res/music.ogg");
	gm->sound = sfSound_create();
	gm->sound_buff = sfSoundBuffer_createFromFile("./res/paff.ogg");
	gm->score_text = sfText_create();
	sfText_setFont(gm->score_text, fnt);
	sfText_setPosition(gm->score_text, pos);
	sfText_setString(gm->score_text, "0");
	sfSound_setBuffer(gm->sound, gm->sound_buff);
}

static int infini_mode(struct game *gm)
{
	int	i = 0;

	if (gm->ground == NULL)
		return (-1);
	for (i = 0; i < TILE_NUMBER / 2; i++) {
		gm->ground[i] = create_tile(300 + 200 * (i + 1), -300,
				TOP_PIPE);
		gm->ground[(TILE_NUMBER / 2) +i] = create_tile(300 + 200 *
				(i + 1), 500, BOTTOM_PIPE);
	}
	return (0);
}

int create_elem(char *map, struct game *gm)
{
	gm->score = 0;
	gm->p1 = create_player(WIDTH >> 2, HEIGHT >> 2);
	if (gm->p1 == NULL)
		return (-1);
	gm->set->no_tile = (gm->set->infin_mode) ? TILE_NUMBER : counter(map);
	gm->set->no_mob = (gm->set->infin_mode) ? 0 : mob_counter(map);
	gm->ground = (tile_t **)malloc(sizeof(tile_t *) * gm->set->no_tile);
	if (gm->ground == NULL)
		return (-1);
	gm->mob = (player_t **)malloc(sizeof(player_t *) * gm->set->no_mob);
	if (gm->mob == NULL)
		return (-1);
	if (gm->set->infin_mode == 0 && create_map(gm, map) < 0)
		return (-1);
	if (gm->set->infin_mode == 1 && infini_mode(gm) < 0)
			return (-1);
	return (0);
}

struct game *init(char *map, struct settings *st)
{
	struct game	*gm = (struct game *)malloc(sizeof(struct game));
	sfVideoMode	video_mode;

	if (gm == NULL)
		return (NULL);
	gm->fps.microseconds = 50000;
	video_mode.width = WIDTH;
	video_mode.height = HEIGHT;
	video_mode.bitsPerPixel = 32;
	gm->set = st;
	gm->win = sfRenderWindow_create(video_mode, "my_runner",
			sfDefaultStyle, NULL);
	if (create_elem(map, gm) < 0)
		return (NULL);
	if (create_texture(gm) < 0)
		return (NULL);
	create_music_sound_font(gm);
	sfMusic_play(gm->music);
	return (gm);
}
