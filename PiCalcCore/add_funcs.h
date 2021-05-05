#ifndef __ADD_FUNCS_H
#define __ADD_FUNCS_H
#include "core.h"

void t_print(token_t* arr, int num);

int what_priority(operation_t operation);

int what_association(operation_t operation);

int array_move(token_t* array, int pos);

int is_unary(operation_t operation);

operation_t what_opertation(char* str, int pos, token_t* tokens, int curr);

int is_sin_zero(double num);

void is_tg_error(double num, unsigned int* error);

void is_ctg_error(double num, unsigned int* error);

operation_t calculating_module(token_t* tokens, int pos, unsigned int* error);

int operation_bool(token_t* tokens, int pos);

#endif