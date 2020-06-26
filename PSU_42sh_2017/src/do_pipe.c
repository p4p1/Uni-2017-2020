/*
** EPITECH PROJECT, 2018
** do_pipe.c
** File description:
** Handle the pipe
*/

#include "my.h"

static void execut_fork_pipe(args *command)
{
	search_bin(command);
	if (access(command->filename, F_OK) == 0) {
		execve(command->filename, command->arg, command->env);
		perror(command->filename);
	} else {
		my_putstr(command->filename);
		my_putstr(": Command not found.\n");
	}
	return;
}

void do_pid_one(int *pipe_fd, args *command_one)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	if (check_built(command_one) != 0)
		execut_fork_pipe(command_one);
	exit(0);
}

void do_pid_two(int *pipe_fd, args *command_two)
{
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	if (check_built(command_two) != 0)
		execut_fork_pipe(command_two);
	exit(0);
}

void do_pipe_final(args *command_one, args *command_two)
{
	pid_t pid_one = 18;
	pid_t pid_two = 18;
	int pipe_fd[2];

	pipe(pipe_fd);
	pid_one = fork();
	if (pid_one == 0) {
		do_pid_one(pipe_fd, command_one);
	}
	pid_two = fork();
	if (pid_two == 0) {
		do_pid_two(pipe_fd, command_two);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(&pid_one);
	wait(&pid_two);
}

void do_pipe(char *str_one, char **envp)
{
	args command_one;
	args command_two;
	char *str_two = NULL;

	str_one = make_good(str_one);
	str_two = get_pipe(str_one);
	if (str_two == NULL)
		return;
	str_one = get_pipe(str_one);
	if (str_one == NULL)
		return;
	str_one = make_good(str_one);
	str_two = make_good(str_two);
	create_struct(&command_one, str_two, envp, 1);
	create_struct(&command_two, str_one, envp, 1);
	command_one.env = envp;
	command_two.env = envp;
	do_pipe_final(&command_one, &command_two);
}
