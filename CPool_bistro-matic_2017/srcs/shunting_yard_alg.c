/*
** EPITECH PROJECT, 2017
** shuting_yard_alg.c
** File descirption:
** the shuting yard algorithm to convert from normal notation to rpn
*/

#include "bistro.h"

char *stos(char *str, char **endptr, char **b_nop, int neg)
{
	int	len = (*str == b_nop[1][3])? 1 : 0;
	char	*value = 0;
	int	i = 0;
	int	j = 0;

	while ((str[len] != '\0') && in_base(str[len], *b_nop)) {
		++len;
	}
	value = (char *)malloc(sizeof(char) * (len + 2));
	if (neg % 2) {
		len++;
		value[i++] = b_nop[1][3];
	}
	while (i < len) {
		value[i] = str[j];
		++i;
		++j;
	}
	value[i] = '\0';
	*endptr = str + j;
	return (value);
}

int process_operator(char *op, struct stack **s, struct queue **q, char *ops)
{
	char	*t_str = malloc(sizeof(char) * 2);

	if (t_str == 0) {
		my_putstr(ERROR_MSG);
		exit(EXIT_MALLOC);
	}
	if (*op == ops[3] && check_op((op - 1), ops) && *(ops) == *(op + 1))
		return (0);
	if ((*s)) {
		while (check_op((*s)->token, ops) >= check_op(op, ops)) {
			pop_stack_to_queue(s, q);
			if (*s == NULL)
				break;
		}
	}
	t_str[0] = *op;
	t_str[1] = '\0';
	add_stack(s, t_str);
	free(t_str);
	return (0);
}

void process_right_p(struct stack **s, struct queue **q, int *n, char *op)
{
	char	*tmp = 0;

	if (*n)
		*n -= 1;
	if ((*s)) {
		while (*(*s)->token != *op) {
			pop_stack_to_queue(s, q);
			if ((*s) == 0)
				break;
		}
	}
	tmp = pop_stack(s);
	free(tmp);
}

void add_op_to_stack(struct stack **s, char *op, int *n, char *ops)
{
	char	*tmp = malloc(sizeof(char) * 2);

	if (tmp == 0) {
		my_putstr(ERROR_MSG);
		exit(EXIT_MALLOC);
	}
	if (*(op - 1) == ops[3])
		*n += 1;
	if (*(op - 1) == ops[3] && !(*n % 2)) {
		pop_stack(s);
		tmp[0] = ops[2];
		tmp[1] = '\0';
		add_stack(s, tmp);
	}
	tmp[0] = *op;
	tmp[1] = '\0';
	add_stack(s, tmp);
	free(tmp);
}

struct queue *shuting_yard(char *str, char **b_op)
{
	struct stack	*s_head = 0;
	struct queue	*q_head = 0;
	int	i = 0;
	int	neg = 0;

	while (*str != '\0') {
		if (neg_no(str, i++, *b_op, b_op[1]) || in_base(*str, *b_op)) {
			add_queue(&q_head, stos(str, &str, b_op, neg));
		} else if (check_op(str, (*(b_op + 1) + 2)) && i != 1) {
			process_operator(str++, &s_head, &q_head, b_op[1]);
		} else if (*str == *(b_op[1])) {
			add_op_to_stack(&s_head, (str)++, &neg, b_op[1]);
		} else if (*str == b_op[1][1]) {
			process_right_p(&s_head, &q_head, &neg ,b_op[1]);
			str++;
		} else {
			str++;
		}
	}
	dump_stack_to_queue(&s_head, &q_head);
	return (q_head);
}
