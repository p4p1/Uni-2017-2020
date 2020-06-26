/*
** EPITECH PROJECT, 2017
** ex_6.h
** File description:
** <..>
*/

#ifndef EX_6_H_
#define EX_6_H_

struct fo {
    struct fu {
        int foo;
    } fu;
    struct fa {
        short fa foo;
        struct fp {
            struct fu   foo;
            struct fu   bar;
        }fp;
        struct fp   bar;
    } fa;
    struct fa   foo;
    short       bar;
};

typedef struct fo foo_t;

#endif
