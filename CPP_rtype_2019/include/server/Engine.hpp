/*
** EPITECH PROJECT, 2017
** Engine.hpp
** File description:
** <..>
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <stdio.h>
#include "protocol.hpp"
#include <vector>

#define WIDTH_ENTITY 50
#define HEIGHT_ENTITY 50
#define BULLET_SPEED 100
#define MOVEMENT_SPEED 50

using namespace protocol;

class Engine {
    public:
        Engine();
        ~Engine();
        bool addElement(struct proto *elem);
        struct proto *getElement(unsigned int ident);
        bool colision(struct proto *el1, struct proto *el2);
        struct proto *isDead();
        void updateMovement(struct proto *el);
        void updateBullet();
    private:
        std::vector<struct proto *>   _players;
        std::vector<struct proto *>   _bullets;
};

#endif
