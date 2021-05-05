#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "core.h"

void t_print(token_t* arr, int num) {
  int i;
  printf("(");
  for (i = 0; i < num; i++)
    if (arr[i].operation != none)
      printf("[%i] ", arr[i].operation);
    else
      printf("{%lf} ", arr[i].number);
  printf(")");
}

int what_priority(operation_t operation) {
  switch (operation) {
  case plus: return 1;
  case minus_un: return 3;
  case minus_bi: return 1;
  case mult: return 2;
  case divis: return 2;
  case power: return 3;
  case brack_op: return 4;
  case brack_cl: return 0;
  case root: return 3;
  case sin_: return 3;
  case cos_: return 3;
  case tg_: return 3;
  case ctg_: return 3;
  case arcsin_: return 3;
  case arccos_: return 3;
  case arctg_: return 3;
  case ln: return 3;
  case floor_: return 3;
  case ceil_: return 3;
  default: return EOF;
  }
}

int what_association(operation_t operation) {
  switch (operation) {
  case plus: return 1;
  case minus_un: return -1;
  case minus_bi: return 1;
  case mult: return 1;
  case divis: return 1;
  case power: return -1;
  case brack_op: return 0;
  case brack_cl: return 0;
  case root: return -1;
  case sin_: return -1;
  case cos_: return -1;
  case tg_: return -1;
  case ctg_: return -1;
  case arcsin_: return -1;
  case arccos_: return -1;
  case arctg_: return -1;
  case ln: return -1;
  case floor_: return -1;
  case ceil_: return -1;
  default: return 0;
  }
}

int array_move(token_t* array, int pos) {
  switch (array[pos].operation) {
  case none: return 1;
  case plus: return 1;
  case minus_un: return 1;
  case minus_bi: return 1;
  case mult: return 1;
  case divis: return 1;
  case power: return 1;
  case brack_op: return 1;
  case brack_cl: return 1;
  case root: return 4;
  case sin_: return 3;
  case cos_: return 3;
  case tg_: return 2;
  case ctg_: return 3;
  case arcsin_: return 6;
  case arccos_: return 6;
  case arctg_: return 5;
  case ln: return 2;
  case floor_: return 5;
  case ceil_: return 4;
  default: return 1;
  }
}

int is_unary(operation_t operation) {
  switch (operation) {
  case plus: return 0;
  case minus_un: return 1;
  case minus_bi: return 0;
  case mult: return 0;
  case divis: return 0;
  case power: return 0;
  case brack_op: return 0;
  case brack_cl: return 0;
  case root: return 1;
  case sin_: return 1;
  case cos_: return 1;
  case tg_: return 1;
  case ctg_: return 1;
  case arcsin_: return 1;
  case arccos_: return 1;
  case arctg_: return 1;
  case ln: return 1;
  case floor_: return 1;
  case ceil_: return 1;
  default: return EOF;
  }
}

operation_t what_opertation(char* str, int pos, token_t* tokens, int curr) {
  switch (str[pos]) {
  case '+': return plus;
  case '-': if ((tokens[curr - 1].operation == none) || (tokens[curr - 1].operation == brack_cl)) return minus_bi;
            else return minus_un;
  case '*': return mult;
  case '/': return divis;
  case '^': return power;
  case '(': return brack_op;
  case ')': return brack_cl;
  case 's': if ((str[pos + 1] == 'q') && (str[pos + 2] == 'r') && (str[pos + 3] == 't'))
    return root;
    if ((str[pos + 1] == 'i') && (str[pos + 2] == 'n'))
      return sin_;
  case 'c': if ((str[pos + 1] == 'o') && (str[pos + 2] == 's'))
    return cos_;
    if ((str[pos + 1] == 't') && (str[pos + 2] == 'g'))
      return ctg_;
    if ((str[pos + 1] == 'e') && (str[pos + 2] == 'i') && (str[pos + 3] == 'l'))
      return ceil_;
  case 't': if (str[pos + 1] == 'g')
    return tg_;
  case 'a': if ((str[pos + 1] == 'r') && (str[pos + 2] == 'c') && (str[pos + 3] == 's') && (str[pos + 4] == 'i') && (str[pos + 5] == 'n'))
    return arcsin_;
    if ((str[pos + 1] == 'r') && (str[pos + 2] == 'c') && (str[pos + 3] == 'c') && (str[pos + 4] == 'o') && (str[pos + 5] == 's'))
      return arccos_;
    if ((str[pos + 1] == 'r') && (str[pos + 2] == 'c') && (str[pos + 3] == 't') && (str[pos + 4] == 'g'))
      return arctg_;
  case 'l': if (str[pos + 1] == 'n')
    return ln;
  case 'f': if ((str[pos + 1] == 'l') && (str[pos + 2] == 'o') && (str[pos + 3] == 'o') && (str[pos + 4] == 'r'))
    return floor_;
  default: return none;
  }
}

int is_sin_zero(double num) {
	int num_i = (int)(num /= (2 * PI));
	if (num == num_i)
		return 1;
	return 0;
}

void is_tg_error(double num, unsigned int* error) {
	int num_i;
	num = (num + (PI / 2)) / (PI);
	num_i = (int)num;
	if (num == num_i)
		* error = 18;
}

void is_ctg_error(double num, unsigned int* error) {
	int num_i;
	num /= PI;
	num_i = (int)num;
	if (num == num_i)
		* error = 19;
}

operation_t calculating_module(token_t * tokens, int pos, unsigned int* error) {
	int pow1 = (int)tokens[pos + 1].number;
  if ((tokens[pos + 1].operation != none) && (tokens[pos + 1].operation != brack_op) && (tokens[pos + 1].operation >= 0) && (tokens[pos].operation != brack_cl)) {
    * error = 6;           //ERROR: 6;
    return none;
  }
  if ((is_unary(tokens[pos].operation) == 0) && (tokens[pos - 1].operation != none)) {
    * error = 24;           //ERROR: 24;
    return none;
  }
	switch (tokens[pos].operation) {
	case plus: tokens[pos - 1].number += tokens[pos + 1].number;
    return plus;
	case minus_un: tokens[pos].number = -1 * tokens[pos + 1].number; tokens[pos].operation = none;
    return minus_un;
	case minus_bi: tokens[pos - 1].number -= tokens[pos + 1].number;
    return minus_bi;
	case mult: tokens[pos - 1].number *= tokens[pos + 1].number;
    return mult;
	case divis: tokens[pos - 1].number /= tokens[pos + 1].number;
    if (tokens[pos + 1].number == 0) * error = 7;
    return divis;           //ERROR: 7;
	case power: if ((tokens[pos + 1].number != pow1) && (tokens[pos - 1].number < 0)) * error = 12;
    tokens[pos - 1].number = pow(tokens[pos - 1].number, tokens[pos + 1].number);
    return power;            //ERROR: 12;
	case root: tokens[pos].number = sqrt(tokens[pos + 1].number);
    if (tokens[pos + 1].number < 0) * error = 10; tokens[pos].operation = none;
    return root;            //ERROR: 10;
	case sin_: tokens[pos].number = sin(tokens[pos + 1].number);
    if (is_sin_zero(tokens[pos + 1].number)) tokens[pos].number = 0; tokens[pos].operation = none;
    return sin_;
	case cos_: tokens[pos].number = cos(tokens[pos + 1].number); tokens[pos].operation = none;
    return cos_;
	case tg_: tokens[pos].number = tan(tokens[pos + 1].number); is_tg_error(tokens[pos + 1].number, error); tokens[pos].operation = none;
    return tg_;         //ERROR: 18;
	case ctg_: tokens[pos].number = cos(tokens[pos + 1].number) / sin(tokens[pos + 1].number); is_ctg_error(tokens[pos + 1].number, error); tokens[pos].operation = none;
    return ctg_;           //ERROR: 19;
	case arcsin_: tokens[pos].number = asin(tokens[pos + 1].number);
    if ((tokens[pos + 1].number < -1) || (tokens[pos + 1].number > 1)) * error = 14; tokens[pos].operation = none;
    return arcsin_;           //ERROR: 14;
	case arccos_: tokens[pos].number = acos(tokens[pos + 1].number);
    if ((tokens[pos + 1].number < -1) || (tokens[pos + 1].number > 1)) * error = 15; tokens[pos].operation = none;
    return arccos_;           //ERROR: 15;
	case arctg_: tokens[pos].number = atan(tokens[pos + 1].number); tokens[pos].operation = none;
    return arctg_;
	case ln: tokens[pos].number = log(tokens[pos + 1].number);
    if (tokens[pos + 1].number <= 0) * error = 11; tokens[pos].operation = none;
    return ln;            //ERROR: 11;
	case floor_: tokens[pos].number = floor(tokens[pos + 1].number); tokens[pos].operation = none;
    return floor_;
	case ceil_: tokens[pos].number = ceil(tokens[pos + 1].number); tokens[pos].operation = none;
    return ceil_;
	default: return none;
	}
}

int operation_bool(token_t* tokens, int pos) {
	int i = 1;
	if (tokens[pos].operation != none) {
		while (tokens[pos + i].operation == none)
			i++;
		if ((what_association(tokens[pos].operation)) == 1) {
			if (what_priority(tokens[pos + i].operation) <= what_priority(tokens[pos].operation))
				return 1;
			else
				return 0;
		}
		if ((what_association(tokens[pos].operation)) == -1) {
      if ((tokens[pos].operation != minus_un) && (is_unary(tokens[pos].operation) == 1) && (tokens[pos + 1].operation == none) && (tokens[pos + 2].operation == power))
        return 1;
      if (what_priority(tokens[pos + i].operation) < what_priority(tokens[pos].operation)) {
        return 1;
      }
			else
				return 0;
		}
	}
	return 0;
}
