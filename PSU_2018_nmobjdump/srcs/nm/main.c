/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** <..>
*/

#include "nm.h"

static void disp_elf(Elf64_Ehdr *elf)
{
    Elf64_Shdr  *str = (Elf64_Shdr *)((char *)elf + elf->e_shoff);
    Elf64_Shdr section_string = str[elf->e_shstrndx];
    char        *string = (char *)((void *)elf + section_string.sh_offset);
    for (int i = 0; i < elf->e_shnum; i++) {
        printf("%s\n", &string[str[i].sh_name]);
    }
}

static void nm(const char *file_name)
{
    int fd;
    void *buf;
    struct stat s;
    Elf64_Ehdr *elf = NULL;

    fd = open(file_name, O_RDONLY);
    if (fd != -1) {
        fstat(fd, &s);
        buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (buf != (void *)-1) {
            printf("mmap(%s): %08lx\n", file_name, (unsigned long) buf);
            elf = buf;
            printf("Section Header Table: addr = %08lx, nb = %dn",
                    elf->e_shoff, elf->e_shnum);
        } else {
            perror ("mmap");
        }
        close(fd);
    }
    disp_elf(elf);

}

int main (int ac, char **av)
{
    if (ac == 1) {
        nm("./a.out");
        return (0);
    }
    if (ac == 2) {
        nm(av[1]);
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        printf("%s:\n", av[i]);
        nm(av[i]);
        if (i != ac - 1)
            printf("\n");
    }
    return (0);
}
