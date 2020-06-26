/*
** EPITECH PROJECT, 2017
** tests_arguments.c
** File description:
** test file for arguments
*/

#include <criterion/criterion.h>
#include <stdio.h>

int get_no(char *str);

Test(get_argument, retrieve_arguments)
{
	cr_assert_eq(get_no("helloWorld"), 0);
	cr_assert_eq(get_no("hello24"), 0);
	cr_assert_eq(get_no("hello25"), 0);
	cr_assert_eq(get_no("45jdsfsd"), 45);
}
