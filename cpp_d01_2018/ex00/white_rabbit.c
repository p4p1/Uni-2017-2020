/*
** EPITECH PROJECT, 2018
** white_rabbit.c
** File description:
** <..>
*/

#include <stdio.h>
#include <stdlib.h>

int follow_the_white_rabbit(void)
{
    int die = 0;
    int die_total = 0;

    while (1) {
        die = random() % 37;
        if (die == 4 || die == 5 || die == 6 || die == 17 || die == 28 ||
                (die >= 18 && die <= 21))
            printf("left\n");
        else if (die == 13 || die >= 34 || die == 23)
            printf("right\n");
        else if (die == 15 || die == 10)
            printf("forward\n");
        else if ((die > 24 && (die * 3) == 78) || (die % 8) == 0)
            printf("backward\n");
        else if (die == 1 || die == 37 || die_total == 421 || die_total == 397)
            break;
        die_total += die;
    }
    die_total += die;
    printf("RABBIT!!!\n");
    return (die_total);
}
