#ifndef __CORE_H
#define __CORE_H

#define PI 3.1415926535897932384626433832795
//#define exponent 2.71828182845904523536028747135266249775724709369995

typedef enum operations {
	none,
	plus,
	minus_un,
	minus_bi,
	mult,
	divis,
	power,
	brack_op,
	brack_cl,
	root,
	sin_,
	cos_,
	tg_,
	ctg_,
	arcsin_,
	arccos_,
	arctg_,
	ln,
	floor_,
	ceil_
}operation_t;

typedef struct signs {
	operation_t operation;
	double number;
}token_t;

double symbol_processing(char* str, int start, int end, unsigned int* error);

#endif
