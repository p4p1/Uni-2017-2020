/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** separate words in 2d array
*/

#include <stdlib.h>

void my_putchar(char c);

char is_end_of_line(char c)
{
	if (c != '\n')
		return (1);
	return (0);
}

int jump_to_end(char const *str, int i)
{
	while (is_end_of_line(*(str+i)))
		i++;
	return (i);
}

int word_no(char const *str)
{
	int	i = 0;
	int	len = 1;

	while (*(str+i) != '\0') {
		if ((is_end_of_line(*(str + i))) && (*(str + i) != '\0')) {
			len++;
			i = jump_to_end(str, i);
		} else {
			i++;
		}
	}
	return (len);
}

int save_word(char **ar, int *cw, char const *str, int pos)
{
	int	i = 0;
	int	w_len;

	w_len = ((jump_to_end(str, pos) - pos) + 1);
	*(ar + *cw) = (char *)malloc(w_len * sizeof(char));
	while (i < (w_len - 1) && *(str + (i + pos)) != '\0') {
		*(*(ar + *cw) + i) = *(str + (i + pos));
		++i;
	}
	*(*(ar+*cw)+i) = '\0';
	*cw += 1;
	return (pos+i);
}

char **my_str_to_word_array(char const *str)
{
	int	i = 0;
	int	cw = 0;
	char	**arr;

	if (str == 0)
		return (0);
	arr = (char **)malloc(word_no(str) * sizeof(char *));
	while (*(str + i) != '\0') {
		if (is_end_of_line(*(str + i))) {
			i = save_word(arr, &cw, str, i);
		} else {
			++i;
		}
		if (cw > (word_no(str) + 1))
			break;
	}
	*(arr+cw) = 0;
	return (arr);
}
