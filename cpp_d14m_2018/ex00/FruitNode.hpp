/*
** EPITECH PROJECT, 2017
** FruitNode.hpp
** File description:
** <..>
*/

#ifndef FRUIT_NODE_HPP_
#define FRUIT_NODE_HPP_

typedef struct fruit_node {
	Fruit			*token;
	struct fruit_node	*next;
} FruitNode;

#endif
