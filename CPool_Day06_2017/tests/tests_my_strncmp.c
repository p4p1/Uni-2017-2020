/*
** EPITECH PROJECT, 2017
** tests_my_strncmp.c
** File description:
** test file for my_strncmp
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, test_my_strncmp_V1)
{
	cr_assert_eq(my_strncmp("helloWorld", "helloWorld", 10), 0);
	cr_assert_eq(my_strncmp("starfoul", "starfouz", 8), -14);
	cr_assert_eq(my_strncmp("help", "hello", 3), 0);
	cr_assert_eq(my_strncmp("I love writing", "I loev writing", 100), 17);
	cr_assert_eq(my_strncmp("you can see me", "you can't see me", 8), -7);
	cr_assert_eq(my_strncmp("poiuytrewq", "qwertyuiop", 18), -1);
	cr_assert_eq(my_strncmp("z", "a", 1), 25);
	cr_assert_eq(my_strncmp("honja", "honja", 100), 0);
}
