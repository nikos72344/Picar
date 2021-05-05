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
  case 1: fprintf(stdout, "�� ������� �������� ������"); break;
  case 2: fprintf(stdout, "�� ������� �������� ������"); break;
  case 3: fprintf(stdout, "��������� ������"); break;
  case 4: fprintf(stdout, "��������� �����"); break;
  case 5: fprintf(stdout, "��������� �����"); break;
  case 6: fprintf(stdout, "��������� �����"); break;
  case 7: fprintf(stdout, "������� �� ����"); break;
  case 8: fprintf(stdout, "��������� �������������� ��������"); break;
  case 9: fprintf(stdout, "������ ������"); break;
  case 10: fprintf(stdout, "����������� ��������� ������������"); break;
  case 11: fprintf(stdout, "��������������� ��������� ��������������"); break;
  case 12: fprintf(stdout, "������������� ����������"); break;
  case 13: fprintf(stdout, "������� ��������� ������"); break;
  case 14: fprintf(stdout, "�������� ������� ����������� arcsin"); break;
  case 15: fprintf(stdout, "�������� ������� ���������� arccos"); break;
  case 16: fprintf(stdout, "�������� ����� ������� ������ �����"); break;
  case 17: fprintf(stdout, "��������� �������������� ��������"); break;
  case 18: fprintf(stdout, "�������� ������� ����������� tg"); break;
  case 19: fprintf(stdout, "�������� ������� ����������� ctg"); break;
  case 20: fprintf(stdout, "����������� ����� ���������"); break;
  case 21: fprintf(stdout, "����������� 'e' ��� ������ ����������"); break;
  case 22: fprintf(stdout, "��������� ����� � �����"); break;
  case 23: fprintf(stdout, "��������� �����"); break;
  case 24: fprintf(stdout, "��������� �����"); break;
  case 25: fprintf(stdout, "��� ������ ��������������� ��������� ����������� ������ ���������� ����"); break;
  case 26: fprintf(stdout, "��� ������ ��������������� ��������� ����������� ������ ���������� ����"); break;
  case 27: fprintf(stdout, "��� ������ ��������������� ��������� ����������� ������ ���������� ����"); break;
  case 28: fprintf(stdout, "�� ������� �������� ������"); break;
  case 29: fprintf(stdout, "�� ������� �������� ������"); break;
  case 30: fprintf(stdout, "�� ������� �������� ������"); break;
  case 31: fprintf(stdout, "������� ����� ������� ����������"); break;
  case 32: fprintf(stdout, "���� �� ����� ���� ������"); break;
  case 33: fprintf(stdout, "�� ������� �������� ������"); break;
  case 34: fprintf(stdout, "�� ������� �������� ������"); break;
  case 35: fprintf(stdout, "�� ������� �������� ������"); break;
  case 36: fprintf(stdout, "�� ������� �������� ������"); break;
  case 37: fprintf(stdout, "�� ������� �������� ������"); break;
  case 38: fprintf(stdout, "�� ������� �������� ������"); break;
  case 39: fprintf(stdout, "�� ������� �������� ������"); break;
  case 40: fprintf(stdout, "�� ������� �������� ������"); break;
  case 41: fprintf(stdout, "�� ������� �������� ������"); break;
  case 42: fprintf(stdout, "�� ������� �������� ������"); break;
  case 43: fprintf(stdout, "�� ������� �������� ������"); break;
  case 44: fprintf(stdout, "�� ������� �������� ������"); break;
  default: break;
  }
}

void error_list_by(unsigned int* error) {
  switch (*error) {
  case 1: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 2: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 3: fprintf(stdout, "���������� �����"); break;
  case 4: fprintf(stdout, "���������� ��"); break;
  case 5: fprintf(stdout, "���������� ��"); break;
  case 6: fprintf(stdout, "���������� ��"); break;
  case 7: fprintf(stdout, "�������� �� ����"); break;
  case 8: fprintf(stdout, "���������� ������������ �������"); break;
  case 9: fprintf(stdout, "������ ����"); break;
  case 10: fprintf(stdout, "���������� ����� ������"); break;
  case 11: fprintf(stdout, "����������� ����� ���������"); break;
  case 12: fprintf(stdout, "������ �������"); break;
  case 13: fprintf(stdout, "�������� ��������� ��������"); break;
  case 14: fprintf(stdout, "��������� �������� ���������� arcsin"); break;
  case 15: fprintf(stdout, "��������� �������� ���������� arccos"); break;
  case 16: fprintf(stdout, "��������� ����� ���������� ����� ���"); break;
  case 17: fprintf(stdout, "���������� ������������ �������"); break;
  case 18: fprintf(stdout, "��������� �������� ���������� tg"); break;
  case 19: fprintf(stdout, "��������� �������� ���������� ctg"); break;
  case 20: fprintf(stdout, "�������� ����� ������"); break;
  case 21: fprintf(stdout, "�������� 'e' ��� ����� ����������"); break;
  case 22: fprintf(stdout, "������� ������ � ���"); break;
  case 23: fprintf(stdout, "���������� ��"); break;
  case 24: fprintf(stdout, "���������� ��"); break;
  case 25: fprintf(stdout, "��� ����� ������������� ������ �������� ����� ���������� ����"); break;
  case 26: fprintf(stdout, "��� ����� ������������� ������ �������� ����� ���������� ����"); break;
  case 27: fprintf(stdout, "��� ����� ������������� ������ �������� ����� ���������� ����"); break;
  case 28: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 29: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 30: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 31: fprintf(stdout, "������ ��������� ���������"); break;
  case 32: fprintf(stdout, "���� �� ���� ���� �������"); break;
  case 33: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 34: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 35: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 36: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 37: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 38: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 39: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 40: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 41: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 42: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 43: fprintf(stdout, "�� ���������� �������� ������"); break;
  case 44: fprintf(stdout, "�� ���������� �������� ������"); break;
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
