/*
** EPITECH PROJECT, 2017
** count.c
** File description:
** <..>
*/

#include "minishell.h"

void my_pustr_err(char *str)
{
	write(2, str, my_strlen(str));
}

char *my_strcpy_alphanum(char *dest, char const *src)
{
	int	i = 0;

	if (dest == 0 || src == 0)
		return (0);
	while (*src != '\0') {
		if ((*src >= 'a' && *src <= 'z') ||
				(*src >= 'A' && *src <= 'Z') || (*src >= '0' &&
				*src <= '9') || *src == '_') {
			*(dest + i++) = *src++;
		} else {
			return (NULL);
		}
	}
	*(dest + i) = '\0';
	return (dest);
}

int arg_no(char *buffer)
{
	int	number = 1;
	int	pos = 0;

	for (int i = 0; buffer[i] == ' ' || buffer[i] == '\t'; i++)
		pos++;
	for (int i = pos; buffer[i]; i++)
		if (buffer[i] == ' ' && ((buffer[i + 1] != ' ' ||
					buffer[i + 1] == '\t') &&
					buffer[i + 1] != '\0'))
			number++;
	return (number + 1);
}

char *my_strdup_ln_space(char *buffer, int *pos)
{
	char	*tmp = (char *)malloc(sizeof(char) * my_strlen(buffer) + 1);
	int	j = 0;
	int	i = 0;

	if (tmp == NULL)
		return (NULL);
	for (i = *pos; buffer[i] == ' ' || buffer[i] == '\t'; i++)
		*pos += 1;
	*pos += (buffer[i] == ' ') ? 1 : 0;
	for (i = *pos; i < my_strlen(buffer) && (buffer[i] != ' ' &&
				buffer[i] != '\t'); i++) {
		tmp[j] = buffer[i];
		++j;
	}
	*pos = ++i;
	tmp[j] = '\0';
	return (tmp);
}

void exec_command(struct shell_info *self)
{
	struct stat	fstat;

	if (self != NULL && self->token != NULL && self->token[0] != NULL) {
		execve(create_command(self->token[0], self->envi),
			&self->token[0], create_env(self->envi));
		if (stat(create_command(self->token[0], self->envi), &fstat)
				< 0) {
			my_pustr_err(self->token[0]);
			my_pustr_err(": Command not found.\n");
		} else  {
			my_pustr_err(self->token[0]);
			my_pustr_err(": Pemission denied.\n");
		}
	}
	exit(-1);
}
