/*
** EPITECH PROJECT, 2018
** sample_main_1.c
** File description:
** <..>
*/

int get_array_nb_elem(const int *ptr1, const int *ptr2);

int main(void)
{
    int tab[1000] = {0};
    int nb_elem = get_array_nb_elem(&tab[666], &tab[708]);

    printf("There are %d elements bandween elements 666 and 708\n", nb_elem);
    return (0);
}
