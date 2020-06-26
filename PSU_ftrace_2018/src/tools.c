/*
** EPITECH PROJECT, 2019
** tools
** File description:
** source
*/

#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void exit_error(char const *err_name)
{
    perror(err_name);
    exit(84);
}

int check_elf_format(data_t *data)
{
    if (data->elf->e_ident[EI_MAG0] != ELFMAG0 ||
        data->elf->e_ident[EI_MAG1] != ELFMAG1 ||
        data->elf->e_ident[EI_MAG2] != ELFMAG2 ||
        data->elf->e_ident[EI_MAG3] != ELFMAG3 ||
        data->elf->e_ident[EI_CLASS] == ELFCLASSNONE ||
        data->elf->e_ident[EI_DATA] == ELFDATANONE ||
        data->elf->e_ident[EI_VERSION] == EV_NONE) {
        fprintf(stderr, "File format not recognized\n");
        return 1;
    }
    return 0;
}

int getData(data_t *data, char **argv)
{
    struct stat s;
    int fd = open(argv[0], O_RDONLY);

    if (fd == -1)
        exit_error("open");
    if (fstat(fd, &s) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }
    data->arg = argv;
    data->elf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data->elf == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

Elf64_Shdr *section_by_name(Elf64_Ehdr *ehdr, char const *name)
{
    Elf64_Shdr *shdr = (Elf64_Shdr *) (((char *) ehdr) + ehdr->e_shoff);
    char *strtab = ((char *) ehdr) + shdr[ehdr->e_shstrndx].sh_offset;

    for (int i = 0 ; i < ehdr->e_shnum ; i++)
        if (strcmp(name, strtab + shdr[i].sh_name) == 0)
            return &(shdr[i]);
    return NULL;
}
