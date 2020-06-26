/*
** EPITECH PROJECT, 2017
** get_color
** File description:
** move the colors on an int using or's and bit shift
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16) | (green << 8) | blue;
}

