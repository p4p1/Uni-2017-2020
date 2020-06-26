/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** mai program
*/

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include "syscalls.h"
#include "tools.h"

static Elf64_Addr get_local_fun(long ret, struct user_regs_struct *regs)
{
    return regs->rip + ((ret >> 8) & 0xFFFFFFFF) + 5;
}

static char *get_symbol(symbol_t *syms, int32_t offset)
{
    for (int i = 0 ; syms[i].name != NULL ; i++) {
        if (syms[i].addr == offset)
            return syms[i].name;
    }
    return NULL;
}

static void check_fun(long ret, struct user_regs_struct *regs, symbol_t *syms, char const *prog_name)
{
    unsigned char primary = 0xFF & ret;
    Elf64_Addr offset;
    char *name;

    if (primary == 0xE8) {
        offset = get_local_fun(ret, regs);
        name = get_symbol(syms, offset);
        if (name == NULL)
            printf("Entering function func_0x%lx@%s at 0x%llx\n", offset, prog_name, regs->rip);
        else
            printf("Entering function %s at 0x%llx\n", name, regs->rip);
    } else if (primary == 0xFF) {
        //TODO EXTERNAL CALL
//            offset = get_external_fun(ret, &regs);
//            printf("Entering function %s at 0x%llx\n", get_symbol(syms, offset), offset);
        printf("External call\n");
    }
}

static int looping(char **arg, pid_t pid, symbol_t *syms)
{
    struct user_regs_struct regs;
    siginfo_t info;
    int status;
    long syscall;
    long ret;

    while (waitpid(pid, &status, 0) && !WIFEXITED(status)) {
        if (ptrace(PTRACE_GETSIGINFO, pid, 0, &info) >= 0 &&
            info.si_signo != SIGTRAP && info.si_signo != SIGSTOP)
            printf("Received signal %s\n", sys_siglist[info.si_signo]);
        ptrace(PTRACE_GETREGS, pid, 0, &regs);
        ptrace(PTRACE_PEEKUSER, pid, NULL, NULL);
        syscall = (long) regs.orig_rax;
        ret = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, NULL);
        if (ret == -1 && errno != 0)
            exit_error("ptrace");
        if (syscall < 315)
            display_syscall(arg, syscall, &regs, pid);
        check_fun(ret, &regs, syms, arg[0]);
        ptrace(PTRACE_SINGLESTEP, pid, 0, 0);
    }
    printf("+++ exited with %d +++\n", WEXITSTATUS(status));
    return (0);
}

void ftrace(data_t *data)
{
    pid_t pid = fork();

    switch (pid) {
    case -1:
        exit(84);
    case 0:
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execvp(data->arg[0], data->arg);
        exit(0);
    default:
        looping(data->arg, pid, data->syms);
    }
}
