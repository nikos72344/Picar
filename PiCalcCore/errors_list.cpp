#include <stdio.h>
#include <ctype.h>
#include "core.h"
#include "add_funcs.h"
//#include "main.h"
#define IS_ERROR if(error!=0) return error

void error_list_en(unsigned int* error) {
  switch (*error) {
  case 1: fprintf(stdout, "not enough memory"); break;
  case 2: fprintf(stdout, "not enough memory"); break;
  case 3: fprintf(stdout, "not enough brackets"); break;
  case 4: fprintf(stdout, "missing number"); break;
  case 5: fprintf(stdout, "missing number"); break;
  case 6: fprintf(stdout, "missing number"); break;
  case 7: fprintf(stdout, "division by zero"); break;
  case 8: fprintf(stdout, "wrong input data"); break;
  case 9: fprintf(stdout, "empty brackets"); break;
  case 10: fprintf(stdout, "root expression is less than zero"); break;
  case 11: fprintf(stdout, "logarithmic expression is less than or equal to zero"); break;
  case 12: fprintf(stdout, "wrong power expression"); break;
  case 13: fprintf(stdout, "wrong input data"); break;
  case 14: fprintf(stdout, "wrong arcsin input data"); break;
  case 15: fprintf(stdout, "wrong arccos input data"); break;
  case 16: fprintf(stdout, "incorrect scientific form of the number"); break;
  case 17: fprintf(stdout, "wrong input data"); break;
  case 18: fprintf(stdout, "tangent does not exist in this angle"); break;
  case 19: fprintf(stdout, "cotangent does not exist in this angle"); break;
  case 20: fprintf(stdout, "unexpected end"); break;
  case 21: fprintf(stdout, "use 'e' as exponent"); break;
  case 22: fprintf(stdout, "several points in number"); break;
  case 23: fprintf(stdout, "missing number"); break;
  case 24: fprintf(stdout, "missing number"); break;
  case 25: fprintf(stdout, "wrong language, use English only"); break;
  case 26: fprintf(stdout, "wrong language, use English only"); break;
  case 27: fprintf(stdout, "wrong language, use English only"); break;
  case 28: fprintf(stdout, "not enough memory"); break;
  case 29: fprintf(stdout, "not enough memory"); break;
  case 30: fprintf(stdout, "not enough memory"); break;
  case 31: fprintf(stdout, "too many input parametrs"); break;
  case 32: fprintf(stdout, "file can not be open"); break;
  case 33: fprintf(stdout, "not enough memory"); break;
  case 34: fprintf(stdout, "not enough memory"); break;
  case 35: fprintf(stdout, "not enough memory"); break;
  case 36: fprintf(stdout, "not enough memory"); break;
  case 37: fprintf(stdout, "not enough memory"); break;
  case 38: fprintf(stdout, "not enough memory"); break;
  case 39: fprintf(stdout, "not enough memory"); break;
  case 40: fprintf(stdout, "not enough memory"); break;
  case 41: fprintf(stdout, "not enough memory"); break;
  case 42: fprintf(stdout, "not enough memory"); break;
  case 43: fprintf(stdout, "not enough memory"); break;
  case 44: fprintf(stdout, "not enough memory"); break;
  default: break;
  }
}

void error_list_ru(unsigned int* error) {
  switch (*error) {
  case 1: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 2: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 3: fprintf(stdout, "пропущена скобка"); break;
  case 4: fprintf(stdout, "пропущено число"); break;
  case 5: fprintf(stdout, "пропущено число"); break;
  case 6: fprintf(stdout, "пропущено число"); break;
  case 7: fprintf(stdout, "деление на нуль"); break;
  case 8: fprintf(stdout, "пропущено математическое действие"); break;
  case 9: fprintf(stdout, "пустые скобки"); break;
  case 10: fprintf(stdout, "подкоренное выражение отрицательно"); break;
  case 11: fprintf(stdout, "логарифмическое выражение неположительно"); break;
  case 12: fprintf(stdout, "отрицательный показатель"); break;
  case 13: fprintf(stdout, "неверно введенные данные"); break;
  case 14: fprintf(stdout, "неверна€ область определени€ arcsin"); break;
  case 15: fprintf(stdout, "неверна€ область определни€ arccos"); break;
  case 16: fprintf(stdout, "неверна€ форма научной записи числа"); break;
  case 17: fprintf(stdout, "пропущено математическое действие"); break;
  case 18: fprintf(stdout, "неверна€ область определени€ tg"); break;
  case 19: fprintf(stdout, "неверна€ область определени€ ctg"); break;
  case 20: fprintf(stdout, "неожиданный конец выражени€"); break;
  case 21: fprintf(stdout, "используйте 'e' дл€ записи экспоненты"); break;
  case 22: fprintf(stdout, "несколько точек в числе"); break;
  case 23: fprintf(stdout, "пропущено число"); break;
  case 24: fprintf(stdout, "пропущено число"); break;
  case 25: fprintf(stdout, "дл€ записи математического выражени€ используйте только английский €зык"); break;
  case 26: fprintf(stdout, "дл€ записи математического выражени€ используйте только английский €зык"); break;
  case 27: fprintf(stdout, "дл€ записи математического выражени€ используйте только английский €зык"); break;
  case 28: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 29: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 30: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 31: fprintf(stdout, "слишком много входных параметров"); break;
  case 32: fprintf(stdout, "файл не может быть открыт"); break;
  case 33: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 34: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 35: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 36: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 37: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 38: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 39: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 40: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 41: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 42: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 43: fprintf(stdout, "не удалось выделить пам€ть"); break;
  case 44: fprintf(stdout, "не удалось выделить пам€ть"); break;
  default: break;
  }
}

void error_list_by(unsigned int* error) {
  switch (*error) {
  case 1: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 2: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 3: fprintf(stdout, "прапушчана дужка"); break;
  case 4: fprintf(stdout, "прапушчаны л≥к"); break;
  case 5: fprintf(stdout, "прапушчаны л≥к"); break;
  case 6: fprintf(stdout, "прапушчаны л≥к"); break;
  case 7: fprintf(stdout, "дз€ленне на нуль"); break;
  case 8: fprintf(stdout, "прапушчана матэматычнае дзе€нне"); break;
  case 9: fprintf(stdout, "пусты€ дужк≥"); break;
  case 10: fprintf(stdout, "падкаранЄвы выраз адмоҐны"); break;
  case 11: fprintf(stdout, "лагарыфм≥чны выраз недадатны"); break;
  case 12: fprintf(stdout, "адмоҐны паказн≥к"); break;
  case 13: fprintf(stdout, "н€слушна Ґведзены€ дадзены€"); break;
  case 14: fprintf(stdout, "н€слушна€ вобласць вызначэнн€ arcsin"); break;
  case 15: fprintf(stdout, "н€слушна€ вобласць вызначэнн€ arccos"); break;
  case 16: fprintf(stdout, "н€слушна€ форма навуковага зап≥су л≥ку"); break;
  case 17: fprintf(stdout, "прапушчана матэматычнае дзе€нне"); break;
  case 18: fprintf(stdout, "н€слушна€ вобласць вызначэнн€ tg"); break;
  case 19: fprintf(stdout, "н€слушна€ вобласць вызначэнн€ ctg"); break;
  case 20: fprintf(stdout, "нечаканы канец выразу"); break;
  case 21: fprintf(stdout, "ужывайце 'e' дл€ зап≥су экспаненты"); break;
  case 22: fprintf(stdout, "некальк≥ кропак у л≥ку"); break;
  case 23: fprintf(stdout, "прапушчаны л≥к"); break;
  case 24: fprintf(stdout, "прапушчаны л≥к"); break;
  case 25: fprintf(stdout, "дл€ зап≥су матэматычнага выразу ужывайце тольк≥ ангельскую мову"); break;
  case 26: fprintf(stdout, "дл€ зап≥су матэматычнага выразу ужывайце тольк≥ ангельскую мову"); break;
  case 27: fprintf(stdout, "дл€ зап≥су матэматычнага выразу ужывайце тольк≥ ангельскую мову"); break;
  case 28: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 29: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 30: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 31: fprintf(stdout, "зашмат уваходных параметраҐ"); break;
  case 32: fprintf(stdout, "файл не можа быць адкрыты"); break;
  case 33: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 34: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 35: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 36: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 37: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 38: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 39: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 40: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 41: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 42: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 43: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  case 44: fprintf(stdout, "не атрымалас€ вылучыць пам€ць"); break;
  default: break;
  }
}

unsigned int wrong_symbol(char* str, int pos) {
  if(str[pos] < 0)
    return 25;            //ERROR: 25;
	switch (str[pos]) {
	case 'e': if (isalpha(str[pos + 1]) == 0) { return 0; } return 13;
	case 'E': if (isalpha(str[pos + 1]) == 0) { return 0; } return 13;
	case 'p': if (str[pos + 1] == 'i') { return 0; } return 13;
	case 's': if ((str[pos + 1] == 'q') && (str[pos + 2] == 'r') && (str[pos + 3] == 't')) { return 0; }
			  if ((str[pos + 1] == 'i') && (str[pos + 2] == 'n')) { return 0; } return 13;
	case 'c': if ((str[pos + 1] == 'o') && (str[pos + 2] == 's')) { return 0; }
			  if ((str[pos + 1] == 't') && (str[pos + 2] == 'g')) { return 0; }
			  if ((str[pos + 1] == 'e') && (str[pos + 2] == 'i') && (str[pos + 3] == 'l')) { return 0; } return 13;
	case 't': if (str[pos + 1] == 'g') { return 0; } return 13;
	case 'a': if ((str[pos + 1] == 'r') && (str[pos + 2] == 'c') && (str[pos + 3] == 's') && (str[pos + 4] == 'i') && (str[pos + 5] == 'n')) { return 0; }
			  if ((str[pos + 1] == 'r') && (str[pos + 2] == 'c') && (str[pos + 3] == 'c') && (str[pos + 4] == 'o') && (str[pos + 5] == 's')) { return 0; }
			  if ((str[pos + 1] == 'r') && (str[pos + 2] == 'c') && (str[pos + 3] == 't') && (str[pos + 4] == 'g')) { return 0; } return 13;
	case 'l': if (str[pos + 1] == 'n') { return 0; } return 13;
	case 'f': if ((str[pos + 1] == 'l') && (str[pos + 2] == 'o') && (str[pos + 3] == 'o') && (str[pos + 4] == 'r')) { return 0; } return 13;
  case '.': if ((isdigit(str[pos + 1]) != 0) || (str[pos + 1] == '.')) { return 0; } return 13;
	case ' ': return 0;
	default: return 13;           //ERROR: 13;
	}
}

unsigned int brackets_count(token_t * array, int size) {
	int i, op = 0, cl = 0;
	for (i = 0; i < size; i++) {
		if (array[i].operation == brack_op)
			op++;
		if (array[i].operation == brack_cl)
			cl++;
	}
	if (op == cl)
		return 0;
	else
		return 3;
}

unsigned int same_operation(token_t * array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (array[i].operation == array[i + 1].operation) {
			if ((array[i].operation == plus) || (array[i].operation == mult) || (array[i].operation == divis) || (array[i].operation == power))
				return 4;
		}
	}
	return 0;
}

unsigned int wrong_start(token_t * array) {
	if ((array[0].operation == plus) || (array[0].operation == mult) || (array[0].operation == divis) || (array[0].operation == power))
		return 5;
	return 0;
}

unsigned int wrong_brackets(token_t * array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if ((array[i].operation == brack_cl) && (array[i + 1].operation == brack_op))
			return 8;
	}
	return 0;
}

unsigned int empty_brackets(token_t * array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if ((array[i].operation == brack_op) && (array[i + 1].operation == brack_cl))
			return 9;
	}
	return 0;
}

unsigned int no_operation(token_t * array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if ((array[i].operation == none) && (array[i + 1].operation == none))
			return 17;
	}
	return 0;
}

unsigned int unexpeted_end(token_t * array, int size) {
	if ((array[size - 1].operation != none) && (array[size - 1].operation != brack_cl))
		return 20;
	return 0;
}

unsigned int minus_bi_and_operations(token_t* array, int size) {
  int i;
  for (i = 0; i < size; i++)
    if (((array[i].operation == minus_un) || (array[i].operation == minus_bi)) && (array[i + 1].operation != none) && (array[i + 1].operation != brack_op) && (is_unary(array[i + 1].operation) != 1))
      return 23;
  return 0;
}

unsigned int errors_finder(token_t * array, int size) {
	unsigned int error = 0;
	error = brackets_count(array, size);            //ERROR: 3;
	IS_ERROR;
	error = same_operation(array, size);            //ERROR: 4;
	IS_ERROR;
	error = wrong_start(array);           //ERROR: 5;
	IS_ERROR;
	error = wrong_brackets(array, size);            //ERROR: 8;
	IS_ERROR;
	error = empty_brackets(array, size);            //ERROR: 9;
	IS_ERROR;
	error = no_operation(array, size);            //ERROR: 17;
	IS_ERROR;
	error = unexpeted_end(array, size);           //ERROR: 20;
	IS_ERROR;
  error=minus_bi_and_operations(array, size);           //ERROR: 23;
  IS_ERROR;
	return error;
}
