/*
** EPITECH PROJECT, 2017
** gen_line.c
** File description:
** generate lines of each ex
*/

#include "rush3.h"

char *rush1_line(int size, int height, int line)
{
	char	*s_line = (char *)malloc(sizeof(char) * (size + 1));
	int	i = 0;

	if (line == (height - 1) || line == 0)
		s_line[0] = 'o';
	else
		s_line[0] = '|';
	while (++i < (size - 1)) {
		if (line == (height - 1) || line == 0)
			s_line[i] = '-';
		else
			s_line[i] = ' ';
	}
	if ((line == (height - 1) || line == 0))
		s_line[i] = 'o';
	else
		s_line[i] = '|';
	rush1(s_line, size, height, line);
	return (s_line);
}

char *rush2_line(int size, int height, int line)
{
	char	*s_line = (char *)malloc(sizeof(char) * size);
	int	i = 0;

	if (line == (height - 1) || line == 0)
		s_line[0] = (line == 0) ? '/' : '\\';
	else
		s_line[0] = '*';
	while (++i < (size - 1)) {
		if (line == (height - 1) || line == 0)
			s_line[i] = '*';
		else
			s_line[i] = ' ';
	}
	if (line == (height - 1) || line == 0)
		s_line[i] = (line == 0) ? '\\' : '/';
	else
		s_line[i] = '*';
	rush2(s_line, size, height);
	return (s_line);
}

char *rush3_line(int size, int height, int line)
{
	char	*s_line = (char *)malloc(sizeof(char) * size);
	int	i = 0;

	if (line == (height - 1) || line == 0)
		s_line[0] = (line == 0) ? 'A' : 'C';
	else
		s_line[0] = 'B';
	while (++i < (size - 1)) {
		if (line == (height - 1) || line == 0)
			s_line[i] = 'B';
		else
			s_line[i] = ' ';
	}
	if (line == (height - 1) || line == 0)
		s_line[i] = (line == 0) ? 'A' : 'C';
	else
		s_line[i] = 'B';
	rushB(s_line, size, height);
	return (s_line);
}

char *rush4_line(int size, int height, int line)
{
	char	*s_line = (char *)malloc(sizeof(char) * size);
	int	i = 0;

	if (line == (height - 1) || line == 0)
		s_line[i] = 'A';
	else
		s_line[0] = 'B';
	while (++i < (size - 1)) {
		if (line == (height - 1) || line == 0)
			s_line[i] = 'B';
		else
			s_line[i] = ' ';
	}
	if (line == (height - 1) || line == 0)
		s_line[i] = 'C';
	else
		s_line[i] = 'B';
	rushB(s_line, size, height);
	return (s_line);
}

char *rush5_line(int size, int height, int line)
{
	char	*s_line = (char *)malloc(sizeof(char) * size);
	int	i = 0;

	if (line == (height - 1) || line == 0)
		s_line[i] = (line == 0) ? 'A' : 'C';
	else
		s_line[0] = 'B';
	while (++i < (size - 1)) {
		if (line == (height - 1) || line == 0)
			s_line[i] = 'B';
		else
			s_line[i] = ' ';
	}
	if (line == (height - 1) || line == 0)
		s_line[i] = (line == 0) ? 'C' : 'A';
	else
		s_line[i] = 'B';
	rushB(s_line, size, height);
	return (s_line);
}
