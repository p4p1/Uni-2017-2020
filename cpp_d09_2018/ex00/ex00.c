/*
** EPITECH PROJECT, 2018
** exo-1.c
** File description:
** <..>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t   *new = malloc(sizeof(cthulhu_t));

    if (new == NULL)
        return (NULL);
    printf("----\n");
    printf("Building Cthulhu\n");
    cthulhu_initializer(new);
    return (new);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

static void koala_initializaer(koala_t *this, char *_name, char is_A_legend)
{
    this->m_parent.m_name = strdup(_name);
    if (is_A_legend)
        this->m_parent.m_power = 42;
    else
        this->m_parent.m_power = 0;
    printf("Building %s\n", this->m_parent.m_name);
    this->m_is_a_legend = is_A_legend;
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    printf("----\n");
    if (new == NULL)
        return (NULL);
    printf("Building Cthulhu\n");
    koala_initializaer(new, name, is_a_legend);
    return (new);
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}
