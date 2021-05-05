#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "main.h"
#include "core.h"
#include "errors_list.h"
#include "add_funcs.h"
#define ERROR if(*error!=0) return -1
#define exponent 2.71828182845904523536028747135266249775724709369995

int array_processing(token_t * tokens, int* count, int pos, unsigned int* error) {
	int i, l, mov = pos, rew = 2;
	operation_t operation;
	operation = calculating_module(tokens, pos, error);
	ERROR;
	if (operation == none)
		rew = 0;
	if (is_unary(operation)) {
		rew = 1;
		mov++;
	}
	for (l = 0; l < rew; l++) {
		for (i = mov; i < *count; i++)
			tokens[i] = tokens[i + 1];
		(*count)--;
	}
	//t_print(tokens, *count);
	return 0;
}

double brackets_processing(token_t * tokens, int* count, int begin, int end, unsigned int* error) {
	int i = begin + 1;
	double result = 0;
	while (i < end) {
		if (operation_bool(tokens, i)) {
			i = array_processing(tokens, count, i, error);
			i = begin + 1;
		}
		else
			i++;
		ERROR;
		if ((tokens[begin].operation == brack_op) && (tokens[begin + 1].operation == none) && (tokens[begin + 2].operation == brack_cl))
			return tokens[begin + 1].number;
		//t_print(tokens, *count);
	}
	result += tokens[begin + 1].number;
	return result;
}

double logical_module(token_t * tokens, int count, unsigned int* error) {
	int i, l, j, op = 0;
	double result = 0, br_res;
	for (i = 0; i < count; i++) {
		if (tokens[i].operation == brack_op)
			op = i;
		if (tokens[i].operation == brack_cl) {
			br_res = brackets_processing(tokens, &count, op, i, error);
			ERROR;
			tokens[op].number = br_res;
			tokens[op].operation = none;
			for (l = 0; l < 2; l++) {
				for (j = op + 1; j < count; j++)
					tokens[j] = tokens[j + 1];
				count--;
			}
			//t_print(tokens, count);
			i = -1;
		}
	}
	i = 0;
  //t_print(tokens, count);
	while ((count > 1) && (i >= 0)) {
		if (operation_bool(tokens, i))
			i = array_processing(tokens, &count, i, error);
		else
			i++;
		ERROR;
		//t_print(tokens, count);
	}
	result += tokens[0].number;
	return result;
}

double symbol_processing(char* str, int start, int end, unsigned int* error) {
	int i, l, j, count, point;
	double result = 0;
	token_t* tokens, * tokens_c;
	tokens = (token_t*)malloc(sizeof(token_t));
	if (tokens == NULL) {
		*error = 1;           //ERROR: 1;
		return result;
	}
	count = 0;
    for(int i = start; i < end; i++)
        printf("%c", str[i]);
    printf("]\n");
	while (start < end) {
		i = start;
		if (isspace(str[i]))
			i++;
		else {
			tokens[count].operation = what_opertation(str, start, tokens, count);
			tokens[count].number = 0;
			if ((isdigit(str[i]) == 0) && (tokens[count].operation == none)) {
				*error = wrong_symbol(str, i);
				if (*error == 13)            //ERROR: 13;
					i = end;
			}
			i += array_move(tokens, count);
      if ((tokens[count].operation == none) && ((isdigit(str[start]) != 0) || ((str[start] == '.') && (isdigit(str[start + 1]) != 0)))) {
        tokens[count].number = atof(str);
        if ((str[start] == '.') && (isdigit(str[start + 1]) != 0))
          i--;
        point = 0;
        while ((str[i] >= 0) && ((isdigit(str[i]) != 0) || (str[i] == '.'))) {
          if (str[i] == '.')
            point++;
          i++;
        }
        if ((point != 0) && (point != 1))
          * error = 22;         //ERROR: 22;
        if ((str[i] == 'e') || (str[i] == 'E')) {
          if ((str[i + 1] == '-') || (str[i + 1] == '+'))
            i++;
          i++;
          if (isdigit(str[i]) == 0)
            * error = 16;            //ERROR: 16;
          while (isdigit(str[i]) != 0)
            i++;
        }
      }
			if (str[start] == 'e')
				tokens[count].number = exponent;
      if (str[start] == 'E')
        * error = 21;         //ERROR: 21;
			if ((str[start] == 'p') && (str[start + 1] == 'i')) {
				tokens[count].number = PI;
				i = start + 2;
			}
			count++;
			tokens_c = (token_t*)realloc(tokens, (count + 1) * sizeof(token_t));
			if (tokens_c == NULL) {
				*error = 2;           //ERROR: 2;
				return result;
			}
			tokens = tokens_c;
		}
		for (l = start; l < i; l++) {
			for (j = start; j < end; j++)
				str[j] = str[j + 1];
			end--;
		}
		if (*error != 0) {
      for (l = start; l < end; l++)
        str[l] = '\n';
			free(tokens);
			return -1;
		}
	}
	//t_print(tokens, count);
	*error = errors_finder(tokens, count);
	if (*error == 0)
		result = logical_module(tokens, count, error);
	free(tokens);
    error_list_en(error);
	return result;
}
