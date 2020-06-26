/*
** EPITECH PROJECT, 2017
** exec.c
** File description:
** <..>
*/

#include "minishell2.h"

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

	my_memset(&filestat, 0, sizeof(struct stat));
	if (path == NULL)
		return (NULL);
	while ((pth = extract_path(path->token, cmd)) != NULL) {
		my_strcat(pth, cmd);
		if (pth != NULL && stat(pth, &filestat) < 0) {
			continue;
		} else {
			return (pth);
		}
	}
	return (cmd);
}

static void run_command(token_t *tree, struct queue *env, char *cmd)
{
	execve(cmd, &tree->val[0],
			create_env(env));
	my_printf("%s: Permission denied.\n", tree->val[0]);
	exit(84);
}

int ex_command(token_t *tree, struct queue **env)
{
	pid_t	pid;
	int	i = 0;
	char	*cmd = NULL;
	struct stat	fstat;

	my_memset(&fstat, 0, sizeof(struct stat));
	if (inier_command(tree->val, env)) {
		cmd = create_command(tree->val[0], *env);
		if (stat(cmd, &fstat) < 0) {
			my_printf("%s: Command not found.\n", tree->val[0]);
			return (1);
		}
		pid = fork();
		if (pid == 0) {
			run_command(tree, *env, cmd);
		} else {
			waitpid(pid, &i, 0);
			//check_sig(i);
		}
	}
	return (i);
}
