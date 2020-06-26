/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** <..>
*/

#include <string.h>
#include <stdlib.h>

#include "string.h"

void ptr_assign_s(string_t *this, const string_t *str);
void ptr_assign_c(string_t *this, const char *s);

void ptr_append_s(string_t *this, const string_t *ap);
void ptr_append_c(string_t *this, const char *ap);

char ptr_at(const string_t *this, size_t pos);

void ptr_clear(string_t *this);

int ptr_size(const string_t *this);

int ptr_compare_s(const string_t *this, const string_t *str);
int ptr_compare_c(const string_t *this, const char *str);

size_t ptr_copy(const string_t *this, char *s, size_t n, size_t pos);

const char *ptr_c_str(const string_t *this);

int ptr_empty(const string_t *this);

int ptr_find_s(const string_t *this, const string_t *str, size_t pos);
int ptr_find_c(const string_t *this, const char *str, size_t pos);

void ptr_insert_c(string_t *this, size_t pos, const char *str);
void ptr_insert_s(string_t *this, size_t pos, const string_t *str);

int ptr_to_int(const string_t *this);

string_t **ptr_split_s(const string_t *this, char separator);
char **ptr_split_c(const string_t *this, char separator);

void ptr_aff(const string_t *this);

void ptr_join_c(string_t *this, char delim, const char * const * tab);
void ptr_join_s(string_t *this, char delim, const string_t * const * tab);

string_t *ptr_substr(const string_t *this, int offset, int length);

void string_init(string_t *this, const char *s)
{
    if (this != NULL) {
        this->assign_s = &ptr_assign_s;
        this->assign_c = &ptr_assign_c;
        this->append_s = &ptr_append_s;
        this->append_c = &ptr_append_c;
        this->at = &ptr_at;
        this->clear = &ptr_clear;
        this->size = &ptr_size;
        this->compare_s = &ptr_compare_s;
        this->compare_c = &ptr_compare_c;
        this->copy = &ptr_copy;
        this->c_str = &ptr_c_str;
        this->empty = &ptr_empty;
        this->find_s = &ptr_find_s;
        this->find_c = &ptr_find_c;
        this->insert_c = &ptr_insert_c;
        this->insert_s = &ptr_insert_s;
        this->to_int = &ptr_to_int;
        this->split_s = &ptr_split_s;
        this->split_c = &ptr_split_c;
        this->aff = &ptr_aff;
        this->join_c = &ptr_join_c;
        this->join_s = &ptr_join_s;
        this->substr = &ptr_substr;
        this->str = strdup(s);
    }
}

void string_destroy(string_t *this)
{
    if (this != NULL) {
        free(this->str);
        this->str = NULL;
    }
}
