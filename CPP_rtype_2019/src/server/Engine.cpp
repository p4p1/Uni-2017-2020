/*
** EPITECH PROJECT, 2018
** Engine.cpp
** File description:
** <..>
*/

#include "Engine.hpp"

Engine::Engine()
{}

Engine::~Engine()
{}

bool Engine::addElement(struct proto *elem)
{
    if (elem->object == PLAYER) {
        _players.push_back(elem);
        return (true);
    }
    if (elem->object == BULLET) {
        _bullets.push_back(elem);
        return (true);
    }
    return (false);
}

struct proto *Engine::getElement(unsigned int ident)
{
    for (unsigned int i = 0; i < _players.size(); i++) {
        if (_players[i]->identifier == ident)
            return (_players[i]);
    }
    for (unsigned int i = 0; i < _bullets.size(); i++) {
        if (_bullets[i]->identifier == ident)
            return (_bullets[i]);
    }
    return (nullptr);
}

bool Engine::colision(struct proto *el1, struct proto *el2)
{
    if (el1->x < el2->x + WIDTH_ENTITY && el1->x + el1->x + WIDTH_ENTITY >
            el2->x && el1->y < el2->y + HEIGHT_ENTITY && el1->y + HEIGHT_ENTITY
            > el2->y)
        return (true);
    return (false);
}

void Engine::updateBullet()
{
    for (unsigned int i = 0; i < _bullets.size(); i++) {
        if (_bullets[i]->mov == UP)
            _bullets[i]->y -= BULLET_SPEED;
        if (_bullets[i]->mov == DOWN)
            _bullets[i]->y += BULLET_SPEED;
        if (_bullets[i]->mov == RIGHT)
            _bullets[i]->x += BULLET_SPEED;
        if (_bullets[i]->mov == LEFT)
            _bullets[i]->x -= BULLET_SPEED;
    }
}

struct proto *Engine::isDead()
{
    for (unsigned int i = 0; i < _bullets.size(); i++) {
        for (unsigned int j = 0; j < _players.size(); j++) {
            if (colision(_bullets[i], _players[j]))
                return (_players[j]);
        }
    }
    return (nullptr);
}

void Engine::updateMovement(struct proto *el)
{
    for (unsigned int i = 0; i < _players.size(); i++) {
        if (el->identifier == _players[i]->identifier) {
            if (_players[i]->mov == UP)
                _players[i]->y -= MOVEMENT_SPEED;
            if (_players[i]->mov == DOWN)
                _players[i]->y += MOVEMENT_SPEED;
            if (_players[i]->mov == RIGHT)
                _players[i]->x += MOVEMENT_SPEED;
            if (_players[i]->mov == LEFT)
                _players[i]->x -= MOVEMENT_SPEED;
            if (_players[i]->mov == DEAD) {
                _players[i]->x = 0;
                _players[i]->y = 0;
            }
            break;
        }
    }
}
