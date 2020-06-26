/*
** EPITECH PROJECT, 2017
** alloc.c
** File description:
** <..>
*/

#include "my_rpg.h"

map_t *alloc_tile(header_t head)
{
	unsigned int	i = 0;
	map_t	*tile = malloc(sizeof(map_t) *
			(head.width + 1));

	if (tile == NULL)
		return (NULL);
	for (i = 0; i < head.width; i++) {
		my_memset(&(tile[i]), 0, sizeof(map_t));
	}
	return (tile);
}

map_t **alloc_map(header_t head)
{
	map_t	**tile = malloc(sizeof(map_t *) *
			(head.height + 8));
	unsigned int	i = 0;

	if (tile == NULL)
		return (NULL);
	for (i = 0; i < head.height; i++) {
		tile[i] = alloc_tile(head);
		if (tile[i] == NULL)
			return (NULL);
	}
	tile[i] = NULL;
	return (tile);
}
