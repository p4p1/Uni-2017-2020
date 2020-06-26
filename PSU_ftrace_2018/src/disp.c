/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** disp
*/

#include <stdio.h>
#include "syscalls.h"

void display_syscall(char **arg, long syscall,
                    struct user_regs_struct *regs, pid_t pid)
{
    long tab[6] = { (long)regs->rdi, (long)regs->rsi, (long)regs->rdx,
        (long)regs->r10, (long)regs->r8,  (long)regs->r9};

    (void) pid;
    (void) arg;
    if (syscall == -1)
        return;
    printf("Syscall %s(", g_syscalls[syscall].name);
    for (unsigned int i = 0 ; i < g_syscalls[syscall].nparams ; i++) {
        if (i == g_syscalls[syscall].nparams - 1)
            printf("0x%lx", tab[i]);
        else
            printf("0x%lx, ", tab[i]);
    }
    printf(") = 0x%lx\n", (long) regs->rax);
}
