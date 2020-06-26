/*
** EPITECH PROJECT, 2017
** test_utils.c
** File description:
** test utils
*/

#include "bistro.h"
#include <criterion/criterion.h>

Test(from_base, return_its_ok)
{
	cr_expect_eq(from_base('0', "P0NEY"), 1);
	cr_expect_eq(from_base('1', "098765412"), 7);
	cr_expect_eq(from_base('2', "SALUT2"), 5);
	cr_expect_eq(from_base('3', "OKAY39876"), 4);
	cr_expect_eq(from_base('/', "%67/4"), 3);
	cr_expect_eq(from_base('5', "40987583"), 5);
	cr_expect_eq(from_base('6', "GROSPONEY6L"), 9);
	cr_expect_eq(from_base('7', "NISKA7NINHO"), 5);
	cr_expect_eq(from_base('8', "TRES90TRES568LONG9"), 12);
	cr_expect_eq(from_base('9', "98765"), 0);
	cr_expect_eq(from_base('A', "-98+A"), 4);
	cr_expect_eq(from_base('B', "019283B7465"), 6);
	cr_expect_eq(from_base('C', "CHAR67"), 0);
	cr_expect_eq(from_base('D', "QUEDESLETTRES"), 3);
	cr_expect_eq(from_base('E', "1B2E3U4H5"), 3);
	cr_expect_eq(from_base('F', "0124721948OMNDRLSFOP"), 17);
}

Test(to_base, return_its_good)
{
	cr_expect_eq(to_base(0, "SALUT"), 'S');
	cr_expect_eq(to_base(8, "01234567890"), '8');
	cr_expect_eq(to_base(26, "TRESTRESLONGVRAIMENTTRSLONG"), 'G');
	cr_expect_eq(to_base(8, "076219789"), '9');
	cr_expect_eq(to_base(3, "54LU1"), 'U');
	cr_expect_eq(to_base(7, "0123959204291"), '2');
	cr_expect_eq(to_base(1, "OKAY"), 'K');
	cr_expect_eq(to_base(10, "01234CINSIXSEP"), 'X');
	cr_expect_eq(to_base(15, "09OI87HV65GFS72JJD8"), 'J');
	cr_expect_eq(to_base(0, "$P3CÏAL"), '$');
	cr_expect_eq(to_base(2, "|R3$$PEC"), '3');
	cr_expect_eq(to_base(5, "012345"), '5');
	cr_expect_eq(to_base(1, "P0ZZZEYRO"), '0');
	cr_expect_eq(to_base(6, "AAAAAAAA"), 'A');
	cr_expect_eq(to_base(13, "TREIZE13TREIZE13"), 'E');
	cr_expect_eq(to_base(9, "B3UR3TTEDELUXE"), 'E');
}

Test(check_neg, return_its_youpi)
{
	cr_expect_eq(check_neg("546728", '-'), 1);
	cr_expect_eq(check_neg("-137381", '-'), -1);
	cr_expect_eq(check_neg("1", '-'), 1);
	cr_expect_eq(check_neg("-1", '-'), -1);
}
