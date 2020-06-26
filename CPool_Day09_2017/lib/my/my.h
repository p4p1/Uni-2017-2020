/*
** EPITECH PROJECT, 2017
** libmy.h
** File description:
** header for lib my
*/

#ifndef LIB_MY_H_
#define LIB_MY_H_

int my_print_combn(int n);
int my_print_comb(int n);
int my_print_comb2(int n);
int pnb_number_len(int nb);
int pnb_get_digit(int nb, int loc);
int find_power(int nb, char const *base);
int tab_swap(int *a, int *b);
void reset_chars(char *str);
void set_upcase(char *str, int *i);
int get_str_len(char const *str);
int get_str_len_2(char const *str);
int find_occurence(char *p_begining_occurence, char const *to_find);
int get_len_str(char const *str);
int get_digit(int nb, int loc);
int init_max_and_num(int *start_num, int *max_no, int n);
int number_len(int nb);
char is_alphanumeric(char c);
int jump_to_end(char const *str, int i);
int save_word(char **ar, int *cw, char const *str, int pos);
int word_no(char const *str);
void is_smaller(int *tab, int2 ii);
int pnb_invert_sign(int nb); 2
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_factorial_rec(int nb);
int my_compute_power_it(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const * src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_evil_str(char *str);
int check_digit(int *val, char const *str, int i, int *ndig);
int my_print_alpha(void);
int c_check_no(int no);
int c_disp_coma(int no);
int c_disp_no(int no);
int c2_check_no(int no);
int c2_disp_coma(int no);
int c2_disp_no(int no);
int cn_check_no(int no);
int cn_check_over(int no);
int cn_disp_coma(int no);
int cn_disp_over(int no);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
struct info_param *my_params_to_array(int ac, char **av);

#endif
