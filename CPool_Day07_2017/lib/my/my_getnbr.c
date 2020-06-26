/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr ex.
*/

void my_putchar(char c);

int check_digit(int *val, char const *str, int i, int *ndig)
{
	*val = *val*10 + (*(str+i) - '0');
	if (++*ndig > 10) {
		*val = 0;
		return (1);
	}
	return (0);
}

int set_val(int neg, int val)
{
	if(!(neg % 2))
		return (val * -1);
	else
		return (val);
}

int my_getnbr(char const *str)
{
	int	val = 0;
	int	i = -1;
	int	neg = 1;
	int	ndig = 0;
	int	flag = 0;

	while (*(str+(++i)) != '\0') {
		if (*(str+i) >= '0' && *(str+i) <= '9') {
			if (*(str+i) != '0' || ndig > 0)
				flag = check_digit(&val, str, i, &ndig);
			if (flag)
				break;
		} else if (val) {
			break;
		}
		if (*(str+i) == '-')
			neg++;
	}
	return (set_val(neg, val));
}
