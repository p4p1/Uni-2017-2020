/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** header
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include <sys/user.h>
# include <sys/types.h>
# include "tools.h"

typedef struct s_syscalls {
    unsigned num;
    char *name;
    char man_found;
    unsigned nparams;
    int type_return;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
} syscalls_t;

void ftrace(data_t *data);
void display_syscall(char **arg, long syscall,
                    struct user_regs_struct *regs, pid_t pid);

#endif
