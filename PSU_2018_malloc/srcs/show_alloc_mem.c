/*
** EPITECH PROJECT, 2018
** show_alloc_mem.c
** File description:
** <..>
*/
#include "my_malloc.h"

void my_putchar(char ch)
{
    write(0, &ch, 1);
}

static int my_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        ++len;
    return (len);
}

void my_putstr(char *str)
{
    while (*str)
        my_putchar(*str++);
}

void my_putnbr_base_local(unsigned long nbr, char const *base)
{
    unsigned long	nb_len = my_strlen(base);
    unsigned long	pos = 0;

    pos = nbr % nb_len;
    if (nbr > 0) {
        my_putnbr_base_local(nbr / nb_len, base);
        my_putchar(base[pos]);
    }
}

void show_alloc_mem(void)
{
    alloc_t *alloc_ptr = alloc_list_start;
    unsigned long ptr = 0;
    void *break_addr = sbrk(0);

    my_putstr("break: ");
    my_putnbr_base_local((unsigned long)break_addr,
    "0123456789abcdef");
    my_putchar('\n');
    while (alloc_ptr) {
        ptr = (unsigned long)alloc_ptr->current;
        my_putnbr_base_local(ptr, "0123456789abcdef");
        my_putstr(" - ");
        ptr = (unsigned long)alloc_ptr->current + (unsigned
        long)alloc_ptr->size;
        my_putnbr_base_local(ptr, "0123456789abcdef");
        my_putstr(" : ");
        my_putnbr_base_local(alloc_ptr->size, "0123456789");
        my_putstr(" bytes");
        my_putstr(" : ");
        my_putstr((alloc_ptr->is_free) ? "1" : "0");
        my_putstr(" is_free\n");
        alloc_ptr = alloc_ptr->next;
    }
}
