/*
** EPITECH PROJECT, 2017
** tests_get_occurence.c
** File description:
** testing the get occurence
*/

#include <criterion/criterion.h>
#include "../include/rush2.h"

Test(get_occurence, testing_get_occurence)
{
	cr_assert_eq(get_occurence("HelloWorld", 'o'), 2);
}
