/*
** EPITECH PROJECT, 2018
** sample_main.c
** File description:
** <..>
*/

#include <stdio.h>
#include "castmania.h"

static void test_print(void)
{
    int i = 5;
    float   f = 42.5;

    printf("Print i : ");
    exec_instruction(PRINT_INT, &i);
    printf("Print f : ");
    exec_instruction(PRINT_FLOAT, &f);
}

static void test_add_op(integer_op_t *int_op, instruction_t *inst)
{
    addition_t add;

    add.add_type = ABSOLUTE;
    add.add_op = *int_op;
    inst->operation = &add;
    printf("10 + 3 = ");
    exec_instruction(ADD_OPERATION, inst);
    printf("Ideed 10 + 3 =  %d\n\n", add.add_op.res);
}

static void test_div_op(integer_op_t *int_op, instruction_t *inst)
{
    division_t div;

    div.div_type = INTEGER;
    div.div_op = int_op;
    inst->operation = &div;
    printf("10 / 3 = ");
    exec_instruction(DIV_OPERATION, inst);
    printf("Indeed 10 / 3 = %d\n\n", int_op->res);
}

static void test_operations(void)
{
    integer_op_t    int_op;
    instruction_t   inst;

    int_op.a = 10;
    int_op.b = 3;
    inst.output_type = VERBOSE;
    test_add_op(&int_op, &inst);
    test_div_op(&int_op, &inst);
}

int main(void)
{
    test_print();
    printf("\n");
    test_operations();
    return (0);
}
