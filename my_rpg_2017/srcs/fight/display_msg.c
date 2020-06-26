/*
** EPITECH PROJECT, 2018
** mrpg
** File description:
** display messagein fight
*/

#include "fight.h"

void display_run_message(sfRenderWindow *window)
{
	sfVector2f vec_sen = {50, 570};
	sfText *text = create_txt(vec_sen, "Vous prenez la fuite !", 30);

	display_txt_fight(window, text);
	sfRenderWindow_display(window);
}
