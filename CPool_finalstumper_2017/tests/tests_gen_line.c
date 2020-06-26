/*
** EPITECH PROJECT, 2017
** tests_gen_line.c
** File description:
** test file for line generator
*/

#include <criterion/criterion.h>
#include "rush3.h"

Test(rush1_line, testing_rush1_lines_first_line)
{
	cr_assert_str_eq("o---o", rush1_line(5, 5, 0));
}

Test(rush1_line, testing_rush1_lines_single_value)
{
	cr_assert_str_eq("o", rush1_line(1, 5, 0));
}

Test(rush1_line, testing_rush1_lines_second_line)
{
	cr_assert_str_eq("|   |", rush1_line(5, 5, 2));
}

Test(rush1_line, testing_rush1_lines_last_line)
{
	cr_assert_str_eq("o---o", rush1_line(5, 5, 4));
}

Test(rush2_line, testing_rush2_lines_first_line)
{
	cr_assert_str_eq("/***\\", rush2_line(5, 5, 0));
}

Test(rush2_line, testing_rush2_lines_second_line)
{
	cr_assert_str_eq("*   *", rush2_line(5, 5, 2));
}

Test(rush2_line, testing_rush2_lines_last_line)
{
	cr_assert_str_eq("\\***/", rush2_line(5, 5, 4));
}

Test(rush3_line, testing_rush3_lines_first_line)
{
	cr_assert_str_eq("ABBBA", rush3_line(5, 5, 0));
}

Test(rush3_line, testing_rush3_lines_second_line)
{
	cr_assert_str_eq("B   B", rush3_line(5, 5, 2));
}

Test(rush3_line, testing_rush3_lines_last_line)
{
	cr_assert_str_eq("CBBBC", rush3_line(5, 5, 4));
}

Test(rush4_line, testing_rush4_lines_first_line)
{
	cr_assert_str_eq("ABBBC", rush4_line(5, 5, 0));
}

Test(rush4_line, testing_rush4_lines_second_line)
{
	cr_assert_str_eq("B   B", rush4_line(5, 5, 2));
}

Test(rush4_line, testing_rush4_lines_last_line)
{
	cr_assert_str_eq("ABBBC", rush4_line(5, 5, 4));
}

Test(rush5_line, testing_rush5_lines_first_line)
{
	cr_assert_str_eq("ABBBC", rush5_line(5, 5, 0));
}

Test(rush5_line, testing_rush5_lines_second_line)
{
	cr_assert_str_eq("B   B", rush5_line(5, 5, 2));
}

Test(rush5_line, testing_rush5_lines_last_line)
{
	cr_assert_str_eq("CBBBA", rush5_line(5, 5, 4));
}


Test(rush5_line, testing_rush5_lines_single_line)
{
	cr_assert_str_eq("BBBBB", rush5_line(5, 1, 0));
}
