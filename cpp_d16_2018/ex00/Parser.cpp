/*
** EPITECH PROJECT, 2018
** Parser.cpp
** File description:
** <..>
*/

#include "Parser.hpp"

Parser::Parser()
	: res(0)
{}

Parser::~Parser()
{}

static bool isoperator(char ch)
{
	std::string ope = "+-/*%";
	char	*operators = (char *)ope.c_str();
	int	i = 0;

	while (operators[i]) {
		if (operators[i] == ch)
			return true;
		i++;
	}
	return false;
}

static int compute_two(int a, int b, char ope)
{
	if (ope == '+')
		return b + a;
	if (ope == '-')
		return b - a;
	if (ope == '/')
		return b / a;
	if (ope == '%')
		return b % a;
	if (ope == '*')
		return b * a;
	return 0;
}

void Parser::feed(const std::string &str)
{
	char	*ptr = (char *)str.c_str();
	int		no1 = 0;
	int		no2 = 0;
	char		opera = 0;

	while (*ptr != '\0') {
		if (isdigit(*ptr)) {
			num.push(std::strtol(ptr, &ptr, 10));
		} else if (isoperator(*ptr)) {
			op.push(*ptr++);
		} else if (*ptr == ')') {
			no1 = num.top();
			num.pop();
			no2 = num.top();
			num.pop();
			opera = op.top();
			op.pop();
			num.push(compute_two(no1, no2, opera));
			ptr++;
		} else {
			ptr++;
		}
	}
	while (!op.empty()) {
		no1 = num.top();
		num.pop();
		no2 = num.top();
		num.pop();
		opera = op.top();
		op.pop();
		num.push(compute_two(no1, no2, opera));
	}
	res += num.top();
}

int Parser::result() const
{
	return res;
}

void Parser::reset()
{
	res = 0;
}
