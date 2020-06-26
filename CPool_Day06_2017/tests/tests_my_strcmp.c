/*
** EPITECH PROJECT, 2017
** tests_my_strcmp.c
** File description:
** test file for my_strcmp
*/

#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, test_my_strcmp_V1)
{
	cr_assert_eq(my_strcmp("helloWorld", "helloWorld"), 0);
	cr_assert_eq(my_strcmp("z", "a"), 25);
	cr_assert_eq(my_strcmp("starfoul", "starfouz"), -14);
	cr_assert_eq(my_strcmp("help", "hello"), 4);
	cr_assert_eq(my_strcmp("I love writing", "I loev writing"), 17);
	cr_assert_eq(my_strcmp("you can see me..", "you can't see me.."), -7);
	cr_assert_eq(my_strcmp("poiuytrewq", "qwertyuiop"), -1);
	cr_assert_eq(my_strcmp("honja", "honja"), 0);
}
