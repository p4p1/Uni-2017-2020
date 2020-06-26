/*
** EPITECH PROJECT, 2018
** castmania.c
** File description:
** <..>
*/

#include "castmania.h"
#include <stdio.h>

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t   *value = (instruction_t *)data;
    addition_t      *add = NULL;
    division_t      *div = NULL;
    integer_op_t    *it_dv = NULL;
    decimale_op_t   *dv_dv = NULL;

    if (instruction_type == ADD_OPERATION) {
        add = (addition_t *) value->operation;
        exec_add((addition_t *) value->operation);
        if (value->output_type == VERBOSE)
            printf("%d\n", add->add_op.res);
    }
    if (instruction_type == DIV_OPERATION) {
        div = (division_t *) value->operation;
        exec_div((division_t *) value->operation);
        if (value->output_type == VERBOSE) {
            dv_dv = (div->div_type == DECIMALE) ? div->div_op : NULL;
            it_dv = (div->div_type == INTEGER) ? div->div_op : NULL;
            (dv_dv != NULL) ? printf("%f\n", dv_dv->res ) : printf("%d\n", it_dv->res);
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    int *val = NULL;
    float * vaf = NULL;

    if (instruction_type == PRINT_INT) {
        val = data;
        printf("%d\n", *val);
    } else if (instruction_type == PRINT_FLOAT) {
        vaf = data;
        printf("%f\n", *vaf);
    } else {
        exec_operation(instruction_type, data);
    }
}
