/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** elf loading
*/

#include <stdlib.h>
#include <sys/mman.h>
#include "ftrace.h"

static symbol_t *syms_name_join(Elf64_Sym *symtab,
                                char *strtab,
                                Elf64_Shdr *symtab_shdr)
{
    int syms_number = symtab_shdr->sh_size / symtab_shdr->sh_entsize;
    symbol_t *syms = malloc(sizeof(symbol_t) * (syms_number + 1));
    int n = 0;

    if (syms == NULL)
        return NULL;
    for (int i = 0; i < syms_number; i++) {
        if (symtab[i].st_name != 0 && (short) symtab[i].st_shndx >= 0) {
            syms[n].name = &(strtab[symtab[i].st_name]);
            syms[n].addr = symtab[i].st_value;
            n++;
        }
    }
    syms[n].name = NULL;
    syms[n].addr = 0;
    return syms;
}

static void get_elf_symbols(data_t *data)
{
    Elf64_Shdr *symtab_shdr = section_by_name(data->elf, ".symtab");
    Elf64_Sym *symtab = AT_SEC(data->elf, symtab_shdr);
    char *strtab = AT_SEC(data->elf, section_by_name(data->elf, ".strtab"));

    data->syms = symtab && strtab ?
        syms_name_join(symtab, strtab, symtab_shdr) : NULL;
}

void start_ftrace(data_t *data)
{
    get_elf_symbols(data);
    ftrace(data);
    free(data->syms);
    munmap(data->elf, 0);
}
