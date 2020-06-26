/*
** EPITECH PROJECT, 2017
** function_pointers.c
** File description:
** <..>
*/

#include "minishell.h"

static char **create_env(struct queue *qu)
{
	struct queue	*tmp_count = qu;
	int		no = 0;
	int		i = 0;
	char		**env;

	while (tmp_count != NULL) {
		tmp_count = tmp_count->next;
		++no;
	}
	env = malloc(sizeof(char *) * (no + 1));
	if (env == NULL)
		return (NULL);
	for (i = 0; qu; i++) {
		env[i] = qu->token;
		qu = qu->next;
	}
	env[i] = NULL;
	return (env);
}

static char *create_command(char *cmd, struct queue *env)
{
	struct queue	*path = get_path(env);
	struct stat	filestat;
	char		*pth = NULL;

	if (path == NULL)
		return (NULL);
	while ((pth = extract_path(path->token, cmd)) != NULL) {
		my_strcat(pth, cmd);
		if (stat(pth, &filestat) < 0)
			continue;
		else {
			return (pth);
		}
	}
	return (cmd);
}

char *get_cmd_fp(struct shell_info *self)
{
	char	*buffer = NULL;
	int	i = 0;
	int	j = 0;

	write(1, self->prompt, my_strlen(self->prompt));
	buffer = get_next_line(0);
	if (buffer == NULL) {
		write(1, "exit\n", 5);
	} else {
		self->token = (char **)malloc(sizeof(char *) * arg_no(buffer));
		self->token_type = (int *)malloc(sizeof(int) * arg_no(buffer));
		if (self->token == NULL)
			return (NULL);
		for (i = 0; i < (arg_no(buffer) - 1); i++) {
			self->token[i] = my_strdup_ln_space(buffer, &j);
			self->token_type[i] = (i == 0) ? COMMAND : ARGUMENT;
		}
		self->token[i] = NULL;
	}
	return (buffer);
}

int proc_cmd_fp(struct shell_info *self)
{
	pid_t	pid;
	int	i;

	if (inier_command(self)) {
		pid = fork();
		if (pid == 0) {
			execve(create_command(self->token[0], self->envi),
				&self->token[0], create_env(self->envi));
			my_printf("Command not found: %s\n", self->token[0]);
			exit(-1);
		} else {
			waitpid(pid, &i, 0);
			check_signal(i);
		}
	}
	for (i = 0; self->token[i]; i++)
		free(self->token[i]);
	free(self->token);
	free(self->token_type);
	return (0);
}
