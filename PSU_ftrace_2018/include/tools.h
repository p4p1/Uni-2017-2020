/*
** EPITECH PROJECT, 2019
** tools
** File description:
** header
*/

#ifndef TOOLS_H_
# define TOOLS_H_

# include <elf.h>

# define AT_SEC(ehdr, shdr) (void *)((char *) (ehdr) + (shdr)->sh_offset)

typedef struct symbol {
    char *name;
    long addr;
} symbol_t;

typedef struct data {
    char **arg;
    symbol_t *syms;
    Elf64_Ehdr *elf;
} data_t;

void exit_error(char const *err_name);
int check_elf_format(data_t *data);
int getData(data_t *data, char **argv);
Elf64_Shdr *section_by_name(Elf64_Ehdr *ehdr, char const *name);
void start_ftrace(data_t *data);

#endif
