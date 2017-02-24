#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"

#define DO_SHOW 1
#define SOB_VOID 100
#define SOB_NIL 101
#define SOB_TRUE 104
#define SOB_FALSE 102
int main() {
	START_MACHINE;

	JUMP(CONTINUE);

#include "char.lib"
#include "io.lib"
#include "math.lib"
#include "string.lib"
#include "system.lib"
#include "scheme.lib"

NORMALIZE_FRACTION:
PUSH(FP);
MOV(FP, SP);
PUSH(R1);
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(R1, FPARG(0));
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), INDD(R1, 1));
MOV(INDD(R0, 2), INDD(R1, 2));
L_normalize_fraction_loop:
MOV(R1, INDD(R0, 1));
REM(R1, INDD(R0, 2));
CMP(R1, IMM(0));
JUMP_EQ(L_normalize_fraction_reduce);
MOV(INDD(R0, 1), INDD(R0, 2));
MOV(INDD(R0, 2), R1);
JUMP(L_normalize_fraction_loop);
L_normalize_fraction_reduce:
PUSH(INDD(R0, 2));
MOV(R1, FPARG(0));
MOV(INDD(R0, 1), INDD(R1, 1));
MOV(INDD(R0, 2), INDD(R1, 2));
POP(R1);
DIV(INDD(R0, 1), R1);
DIV(INDD(R0, 2), R1);
CMP(INDD(R0, 2), IMM(0));
JUMP_GT(L_normalize_fraction_make_int);
MUL(INDD(R0, 1), IMM(-1));
MUL(INDD(R0, 2), IMM(-1));
L_normalize_fraction_make_int:
CMP(INDD(R0, 2), IMM(1));
JUMP_NE(L_normalize_fraction_end);
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_INTEGER);
DROP(1);
L_normalize_fraction_end:
POP(R1);
POP(FP);
RETURN;

ADD_FRACTIONS:
PUSH(FP);
MOV(FP, SP);
PUSH(R1);
PUSH(R2);
PUSH(R3);
MOV(R0, FPARG(0));
MOV(R1, FPARG(1));
MOV(R2, INDD(R0, 1));
MUL(R2, INDD(R1, 2));
MOV(R3, INDD(R0, 2));
MUL(R3, INDD(R1, 1));
ADD(R2, R3);
MOV(R3, INDD(R0, 2));
MUL(R3, INDD(R1, 2));
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), R2);
MOV(INDD(R0, 2), R3);
POP(R3);
POP(R2);
POP(R1);
POP(FP);
RETURN;

LIST_LENGTH:
PUSH(FP);
MOV(FP, SP);
PUSH(R1);
MOV(R0, IMM(0));
MOV(R1, FPARG(0));
L_list_length_count_loop:
CMP(R1, IMM(SOB_NIL));
JUMP_EQ(L_list_length_exit);
INCR(R0);
MOV(R1, INDD(R1, 2));
JUMP(L_list_length_count_loop);
L_list_length_exit:
POP(R1);
POP(FP);
RETURN;

COMPARE_STRINGS:
PUSH(FP);
MOV(FP, SP);
PUSH(R1);
PUSH(R2);
MOV(R1, FPARG(0));
MOV(R2, FPARG(1));
CMP(INDD(R1, 0), IMM(T_STRING));
JUMP_NE(L_error_undefined);
CMP(INDD(R2, 0), IMM(T_STRING));
JUMP_NE(L_error_undefined);
CMP(R1, R2);
JUMP_EQ(L_compare_strings_return_true);
CMP(INDD(R1, 1), INDD(R2, 1));
JUMP_NE(L_compare_strings_return_false);
MOV(R0, INDD(R1, 1));
ADD(R1, IMM(2));
ADD(R2, IMM(2));
L_compare_strings_loop:
CMP(R0, IMM(0));
JUMP_EQ(L_compare_strings_return_true);
CMP(IND(R1), IND(R2));
JUMP_NE(L_compare_strings_return_false);
INCR(R1);
INCR(R2);
DECR(R0);
JUMP(L_compare_strings_loop);
L_compare_strings_return_false:
MOV(R0, IMM(SOB_FALSE));
JUMP(L_compare_strings_exit);
L_compare_strings_return_true:
MOV(R0, IMM(SOB_TRUE));
L_compare_strings_exit:
POP(R2);
POP(R1);
POP(FP);
RETURN;
CONTINUE:
/* constant_table */;
PUSH(IMM(206));
CALL(MALLOC);
DROP(1);
MOV(ADDR(100 + 0), IMM(T_VOID));
MOV(ADDR(101 + 0), IMM(T_NIL));
MOV(ADDR(102 + 0), IMM(T_BOOL));
MOV(ADDR(102 + 1), IMM(0));
MOV(ADDR(104 + 0), IMM(T_BOOL));
MOV(ADDR(104 + 1), IMM(1));
MOV(ADDR(106 + 0), IMM(T_INTEGER));
MOV(ADDR(106 + 1), IMM(-1));
MOV(ADDR(108 + 0), IMM(T_INTEGER));
MOV(ADDR(108 + 1), IMM(0));
MOV(ADDR(110 + 0), IMM(T_INTEGER));
MOV(ADDR(110 + 1), IMM(3));
MOV(ADDR(112 + 0), IMM(T_INTEGER));
MOV(ADDR(112 + 1), IMM(1));
/* constant_table_end */
PUSH(R1);
PUSH(90);
DROP(1);
POP(R1);
/* CISC_functions */
/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_car_closure_start_1));
JUMP(L_car_closure_exit_1);
L_car_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_car */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_PAIR));
JUMP_NE(L_error_undefined);
MOV(R0, INDD(R0, 1));
/* gen_car_end */
POP(FP);
RETURN;
L_car_closure_exit_1:
MOV(IND(123), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_cdr_closure_start_1));
JUMP(L_cdr_closure_exit_1);
L_cdr_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_cdr */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_PAIR));
JUMP_NE(L_error_undefined);
MOV(R0, INDD(R0, 2));
/* gen_cdr_end */
POP(FP);
RETURN;
L_cdr_closure_exit_1:
MOV(IND(122), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_null_closure_start_1));
JUMP(L_is_null_closure_exit_1);
L_is_null_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_null */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_NIL));
JUMP_NE(L_is_null_end);
MOV(R0, IMM(SOB_TRUE));
L_is_null_end:
POP(R1);
/* gen_is_null_end */
POP(FP);
RETURN;
L_is_null_closure_exit_1:
MOV(IND(121), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_pair_closure_start_1));
JUMP(L_is_pair_closure_exit_1);
L_is_pair_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_pair */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_PAIR));
JUMP_NE(L_is_pair_end);
MOV(R0, IMM(SOB_TRUE));
L_is_pair_end:
POP(R1);
/* gen_is_pair_end */
POP(FP);
RETURN;
L_is_pair_closure_exit_1:
MOV(IND(172), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_boolean_closure_start_1));
JUMP(L_is_boolean_closure_exit_1);
L_is_boolean_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_boolean */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_BOOL));
JUMP_NE(L_is_boolean_end);
MOV(R0, IMM(SOB_TRUE));
L_is_boolean_end:
POP(R1);
/* gen_is_boolean_end */
POP(FP);
RETURN;
L_is_boolean_closure_exit_1:
MOV(IND(173), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_char_closure_start_1));
JUMP(L_is_char_closure_exit_1);
L_is_char_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_char */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_CHAR));
JUMP_NE(L_is_char_end);
MOV(R0, IMM(SOB_TRUE));
L_is_char_end:
POP(R1);
/* gen_is_char_end */
POP(FP);
RETURN;
L_is_char_closure_exit_1:
MOV(IND(174), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_zero_closure_start_1));
JUMP(L_is_zero_closure_exit_1);
L_is_zero_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_zero */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(INDD(R0, 0), IMM(T_INTEGER));
JUMP_EQ(L_is_zero_compare_to_zero);
CMP(INDD(R0, 0), IMM(T_FRACTION));
JUMP_EQ(L_is_zero_compare_to_zero);
JUMP(L_error_undefined);
L_is_zero_compare_to_zero:
CMP(INDD(R0, 1), IMM(0));
JUMP_NE(L_is_zero_return_false);
L_is_zero_return_true:
MOV(R0, IMM(SOB_TRUE));
JUMP(L_is_zero_end);
L_is_zero_return_false:
MOV(R0, IMM(SOB_FALSE));
L_is_zero_end:
/* gen_is_zero_end */
POP(FP);
RETURN;
L_is_zero_closure_exit_1:
MOV(IND(175), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_integer_closure_start_1));
JUMP(L_is_integer_closure_exit_1);
L_is_integer_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_integer */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_INTEGER));
JUMP_NE(L_is_integer_end);
MOV(R0, IMM(SOB_TRUE));
L_is_integer_end:
POP(R1);
/* gen_is_integer_end */
POP(FP);
RETURN;
L_is_integer_closure_exit_1:
MOV(IND(176), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_number_closure_start_1));
JUMP(L_is_number_closure_exit_1);
L_is_number_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_number */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_TRUE));
MOV(R1, FPARG(2));
CMP(IND(R1), IMM(T_INTEGER));
JUMP_EQ(L_is_number_end);
CMP(IND(R1), IMM(T_FRACTION));
JUMP_EQ(L_is_number_end);
MOV(R0, IMM(SOB_FALSE));
L_is_number_end:
POP(R1)
/* gen_is_number_end */
POP(FP);
RETURN;
L_is_number_closure_exit_1:
MOV(IND(177), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_rational_closure_start_1));
JUMP(L_is_rational_closure_exit_1);
L_is_rational_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_rational */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_TRUE));
MOV(R1, FPARG(2));
CMP(IND(R1), IMM(T_INTEGER));
JUMP_EQ(L_is_rational_end);
CMP(IND(R1), IMM(T_FRACTION));
JUMP_EQ(L_is_rational_end);
MOV(R0, IMM(SOB_FALSE));
L_is_rational_end:
POP(R1);
/* gen_is_rational_end */
POP(FP);
RETURN;
L_is_rational_closure_exit_1:
MOV(IND(178), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_vector_closure_start_1));
JUMP(L_is_vector_closure_exit_1);
L_is_vector_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_vector */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_VECTOR));
JUMP_NE(L_is_vector_end);
MOV(R0, IMM(SOB_TRUE));
L_is_vector_end:
POP(R1);
/* gen_is_vector_end */
POP(FP);
RETURN;
L_is_vector_closure_exit_1:
MOV(IND(179), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_symbol_closure_start_1));
JUMP(L_is_symbol_closure_exit_1);
L_is_symbol_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_symbol */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_SYMBOL));
JUMP_NE(L_is_symbol_end);
MOV(R0, IMM(SOB_TRUE));
L_is_symbol_end:
POP(R1);
/* gen_is_symbol_end */
POP(FP);
RETURN;
L_is_symbol_closure_exit_1:
MOV(IND(180), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_string_closure_start_1));
JUMP(L_is_string_closure_exit_1);
L_is_string_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_string */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_STRING));
JUMP_NE(L_is_string_end);
MOV(R0, IMM(SOB_TRUE));
L_is_string_end:
POP(R1);
/* gen_is_string_end */
POP(FP);
RETURN;
L_is_string_closure_exit_1:
MOV(IND(181), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_procedure_closure_start_1));
JUMP(L_is_procedure_closure_exit_1);
L_is_procedure_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_procedure */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 0), IMM(T_CLOSURE));
JUMP_NE(L_is_procedure_end);
MOV(R0, IMM(SOB_TRUE));
L_is_procedure_end:
POP(R1);
/* gen_is_procedure_end */
POP(FP);
RETURN;
L_is_procedure_closure_exit_1:
MOV(IND(182), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_equal_closure_start_1));
JUMP(L_is_equal_closure_exit_1);
L_is_equal_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_equal */
CMP(FPARG(1), IMM(2));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
MOV(R0, IMM(SOB_FALSE));
MOV(R1, FPARG(2));
MOV(R2, FPARG(3));
CMP(R1, R2);
JUMP_EQ(L_is_equal_return_true);
CMP(INDD(R1,0),IMM(T_SYMBOL));
JUMP_NE(L_is_equal_integers);
CMP(INDD(R2,0),IMM(T_SYMBOL));
JUMP_NE(L_is_equal_end);
CMP(INDD(R1,1),INDD(R2,1)); 
JUMP_EQ(L_is_equal_return_true);
L_is_equal_integers:
CMP(INDD(R1,0),IMM(T_INTEGER));
JUMP_NE(L_is_equal_fractions);
CMP(INDD(R2,0),IMM(T_INTEGER));
JUMP_NE(L_is_equal_second_fraction);
CMP(INDD(R1,1),INDD(R2,1));
JUMP_EQ(L_is_equal_return_true);
L_is_equal_second_fraction:
CMP(INDD(R2,0),IMM(T_FRACTION));
JUMP_NE(L_is_equal_end);
CMP(INDD(R2,2),IMM(1));
JUMP_NE(L_is_equal_end);
CMP(INDD(R1,1),INDD(R2,1));
JUMP_EQ(L_is_equal_return_true);
L_is_equal_fractions:
CMP(INDD(R1,0),IMM(T_FRACTION));
JUMP_NE(L_is_equal_booleans);
CMP(INDD(R2,0),IMM(T_FRACTION));
JUMP_NE(L_is_equal_second_integer);
CMP(INDD(R1,1),INDD(R2,1));
JUMP_NE(L_is_equal_end);
CMP(INDD(R1,2),INDD(R2,2));
JUMP_EQ(L_is_equal_return_true);
L_is_equal_second_integer:
CMP(INDD(R2,0),IMM(T_INTEGER));
JUMP_NE(L_is_equal_end);
CMP(INDD(R1,2),IMM(1));
JUMP_NE(L_is_equal_end);
CMP(INDD(R2,1),INDD(R1,1));
JUMP_EQ(L_is_equal_return_true);
L_is_equal_booleans:
CMP(INDD(R1,0),IMM(T_BOOL));
JUMP_NE(L_is_equal_chars);
CMP(INDD(R2,0),IMM(T_BOOL));
JUMP_NE(L_is_equal_end);
CMP(INDD(R2,1),INDD(R1,1));
JUMP_EQ(L_is_equal_return_true);
L_is_equal_chars:
CMP(INDD(R1,0),IMM(T_CHAR));
JUMP_NE(L_is_equal_end);
CMP(INDD(R2,0),IMM(T_CHAR));
JUMP_NE(L_is_equal_end);
CMP(INDD(R2,1),INDD(R1,1));
JUMP_NE(L_is_equal_end);
L_is_equal_return_true:
MOV(R0, IMM(SOB_TRUE));
L_is_equal_end:
POP(R2);
POP(R1);
/* gen_is_equal_end */
POP(FP);
RETURN;
L_is_equal_closure_exit_1:
MOV(IND(183), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_equal_num_closure_start_1));
JUMP(L_is_equal_num_closure_exit_1);
L_is_equal_num_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_equal_num */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
PUSH(R3);
MOV(R0, IMM(SOB_TRUE));
MOV(R1, FPARG(1));
L_is_equal_num_compare_loop:
CMP(R1, IMM(0));
JUMP_EQ(L_is_equal_num_end);
MOV(R2, FPARG(1+R1));
CMP(IND(R2), IMM(T_INTEGER));
JUMP_NE(L_is_equal_num_not_int);
MOV(R3, FPARG(2));
CMP(INDD(R3, 1), INDD(R2, 1));
JUMP_NE(L_is_equal_num_return_false);
JUMP(L_is_equal_num_continue);
L_is_equal_num_not_int:
CMP(IND(R2), IMM(T_FRACTION));
JUMP_NE(L_is_equal_num_not_fraction);
MOV(R3, FPARG(2));
CMP(INDD(R3, 1), INDD(R2, 1));
JUMP_NE(L_is_equal_num_return_false);
CMP(INDD(R3, 2), INDD(R2, 2));
JUMP_NE(L_is_equal_num_return_false);
L_is_equal_num_continue:
DECR(R1);
JUMP(L_is_equal_num_compare_loop);
L_is_equal_num_not_fraction:
JUMP(L_error_undefined);
L_is_equal_num_return_false:
MOV(R0, IMM(SOB_FALSE));
L_is_equal_num_end:
POP(R3);
POP(R2);
POP(R1);
/* gen_is_equal_num_end */
POP(FP);
RETURN;
L_is_equal_num_closure_exit_1:
MOV(IND(184), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_set_car_closure_start_1));
JUMP(L_set_car_closure_exit_1);
L_set_car_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_set_car */
CMP(FPARG(1), IMM(2));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_PAIR));
JUMP_NE(L_error_undefined);
MOV(INDD(R0, 1), FPARG(3));
MOV(R0, IMM(SOB_VOID));
/* gen_set_car_end */
POP(FP);
RETURN;
L_set_car_closure_exit_1:
MOV(IND(185), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_set_cdr_closure_start_1));
JUMP(L_set_cdr_closure_exit_1);
L_set_cdr_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_set_cdr */
CMP(FPARG(1), IMM(2));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_PAIR));
JUMP_NE(L_error_undefined);
MOV(INDD(R0, 2), FPARG(3));
MOV(R0, IMM(SOB_VOID));
/* gen_set_cdr_end */
POP(FP);
RETURN;
L_set_cdr_closure_exit_1:
MOV(IND(166), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_string_length_closure_start_1));
JUMP(L_string_length_closure_exit_1);
L_string_length_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_string_length */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_STRING));
JUMP_NE(L_error_undefined);
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_INTEGER);
DROP(1);
/* gen_string_length_end */
POP(FP);
RETURN;
L_string_length_closure_exit_1:
MOV(IND(187), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_vector_length_closure_start_1));
JUMP(L_vector_length_closure_exit_1);
L_vector_length_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_vector_length */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_VECTOR));
JUMP_NE(L_error_undefined);
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_INTEGER);
DROP(1);
/* gen_vector_length_end */
POP(FP);
RETURN;
L_vector_length_closure_exit_1:
MOV(IND(188), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_string_ref_closure_start_1));
JUMP(L_string_ref_closure_exit_1);
L_string_ref_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_string_ref */
CMP(FPARG(1), IMM(2));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R1, FPARG(2));
CMP(IND(R1), IMM(T_STRING));
JUMP_NE(L_error_undefined);
MOV(R0, FPARG(3));
CMP(IND(R0), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
CMP(INDD(R0, 1), INDD(R1, 1));
JUMP_GE(L_error_out_of_bounds);
MOV(R0, INDD(R0, 1));
PUSH(INDD(R1, 2+R0));
CALL(MAKE_SOB_CHAR);
DROP(1);
POP(R1);
/* gen_string_ref_end */
POP(FP);
RETURN;
L_string_ref_closure_exit_1:
MOV(IND(189), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_vector_ref_closure_start_1));
JUMP(L_vector_ref_closure_exit_1);
L_vector_ref_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_vector_ref */
CMP(FPARG(1), IMM(2));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R1, FPARG(2));
CMP(IND(R1), IMM(T_VECTOR));
JUMP_NE(L_error_undefined);
MOV(R0, FPARG(3));
CMP(IND(R0), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
CMP(INDD(R0, 1), INDD(R1, 1));
JUMP_GE(L_error_out_of_bounds);
MOV(R0, INDD(R0, 1));
MOV(R0, INDD(R1, 2+R0));
POP(R1);
/* gen_vector_ref_end */
POP(FP);
RETURN;
L_vector_ref_closure_exit_1:
MOV(IND(190), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_make_string_closure_start_1));
JUMP(L_make_string_closure_exit_1);
L_make_string_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_make_string */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
CMP(FPARG(1), IMM(2));
JUMP_EQ(L_make_string_has_char);
MOV(R1, IMM(0));
JUMP(L_make_stringchar_is_set);
L_make_string_has_char:
MOV(R1, FPARG(3));
CMP(IND(R1), IMM(T_CHAR));
JUMP_NE(L_error_undefined);
MOV(R1, INDD(R1, 1));
L_make_stringchar_is_set:
MOV(R2, INDD(R0, 1));
L_make_string_loop:
CMP(R2, IMM(0));
JUMP_EQ(L_make_string_loop_end);
PUSH(R1);
DECR(R2);
JUMP(L_make_string_loop);
L_make_string_loop_end:
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_STRING);
DROP(1+INDD(R0, 1));
POP(R2);
POP(R1);
/* gen_make_string_end */
POP(FP);
RETURN;
L_make_string_closure_exit_1:
MOV(IND(191), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_make_vector_closure_start_1));
JUMP(L_make_vector_closure_exit_1);
L_make_vector_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_make_vector */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
MOV(R1, FPARG(2));
CMP(IND(R1), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
CMP(FPARG(1), IMM(2));
JUMP_EQ(L_make_vector_has_init);
PUSH(IMM(0));
CALL(MAKE_SOB_INTEGER);
DROP(1);
JUMP(L_make_vectorinit_is_set);
L_make_vector_has_init:
MOV(R0, FPARG(3));
L_make_vectorinit_is_set:
MOV(R2, INDD(R1, 1));
L_make_vector_loop:
CMP(R2, IMM(0));
JUMP_EQ(L_make_vector_loop_end);
PUSH(R0);
DECR(R2);
JUMP(L_make_vector_loop);
L_make_vector_loop_end:
PUSH(INDD(R1, 1));
CALL(MAKE_SOB_VECTOR);
DROP(1+INDD(R1, 1));
POP(R2);
POP(R1);
/* gen_make_vector_end */
POP(FP);
RETURN;
L_make_vector_closure_exit_1:
MOV(IND(192), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_vector_closure_start_1));
JUMP(L_vector_closure_exit_1);
L_vector_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_vector */
CMP(FPARG(1), IMM(0));
JUMP_LT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R1, FPARG(1));
MOV(R0, IMM(0));
L_vector_push_loop:
CMP(R0, R1);
JUMP_EQ(L_vector_make_vector);
PUSH(FPARG(2+R0));
INCR(R0);
JUMP(L_vector_push_loop);
L_vector_make_vector:
 PUSH(FPARG(1));
CALL(MAKE_SOB_VECTOR);
DROP(1+FPARG(1));
POP(R1);
/* gen_vector_end */
POP(FP);
RETURN;
L_vector_closure_exit_1:
MOV(IND(193), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_string_set_closure_start_1));
JUMP(L_string_set_closure_exit_1);
L_string_set_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_string_set */
CMP(FPARG(1), IMM(3));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(3));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_STRING));
JUMP_NE(L_error_undefined);
MOV(R1, FPARG(3));
CMP(IND(R1), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
MOV(R1, INDD(R1, 1));
CMP(R1, INDD(R0, 1));
JUMP_GE(L_error_out_of_bounds);
MOV(R2, FPARG(4));
CMP(IND(R2), IMM(T_CHAR));
JUMP_NE(L_error_undefined);
MOV(INDD(R0, 2+R1), INDD(R2, 1));
MOV(R0, IMM(SOB_VOID));
POP(R2);
POP(R1);
/* gen_string_set_end */
POP(FP);
RETURN;
L_string_set_closure_exit_1:
MOV(IND(194), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_vector_set_closure_start_1));
JUMP(L_vector_set_closure_exit_1);
L_vector_set_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_vector_set */
CMP(FPARG(1), IMM(3));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(3));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_VECTOR));
JUMP_NE(L_error_undefined);
MOV(R1, FPARG(3));
CMP(IND(R1), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
MOV(R1, INDD(R1, 1));
CMP(R1, INDD(R0, 1));
JUMP_GE(L_error_out_of_bounds);
MOV(R2, FPARG(4));
MOV(INDD(R0, 2+R1), R2);
MOV(R0, IMM(SOB_VOID));
POP(R2);
POP(R1);
/* gen_vector_set_end */
POP(FP);
RETURN;
L_vector_set_closure_exit_1:
MOV(IND(195), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_numerator_closure_start_1));
JUMP(L_numerator_closure_exit_1);
L_numerator_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_numerator */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_INTEGER));
JUMP_EQ(L_numerator_make);
CMP(IND(R0), IMM(T_FRACTION));
JUMP_EQ(L_numerator_make);
JUMP(L_error_undefined);
L_numerator_make:
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_INTEGER);
DROP(1);
/* gen_numerator_end */
POP(FP);
RETURN;
L_numerator_closure_exit_1:
MOV(IND(196), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_denominator_closure_start_1));
JUMP(L_denominator_closure_exit_1);
L_denominator_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_denominator */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_INTEGER));
JUMP_EQ(L_denominator_make_from_int);
CMP(IND(R0), IMM(T_FRACTION));
JUMP_EQ(L_denominator_make_from_fraction);
JUMP(L_error_undefined);
L_denominator_make_from_int:
PUSH(IMM(1));
JUMP(L_denominator_make);
L_denominator_make_from_fraction:
PUSH(INDD(R0, 2));
L_denominator_make:
CALL(MAKE_SOB_INTEGER);
DROP(1);
/* gen_denominator_end */
POP(FP);
RETURN;
L_denominator_closure_exit_1:
MOV(IND(197), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_char_to_integer_closure_start_1));
JUMP(L_char_to_integer_closure_exit_1);
L_char_to_integer_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_char_to_integer */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_CHAR));
JUMP_NE(L_error_undefined);
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_INTEGER);
DROP(1);
/* gen_char_to_integer_end */
POP(FP);
RETURN;
L_char_to_integer_closure_exit_1:
MOV(IND(198), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_integer_to_char_closure_start_1));
JUMP(L_integer_to_char_closure_exit_1);
L_integer_to_char_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_integer_to_char */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_INTEGER));
JUMP_NE(L_error_undefined);
PUSH(INDD(R0, 1));
CALL(MAKE_SOB_CHAR);
DROP(1);
/* gen_integer_to_char_end */
POP(FP);
RETURN;
L_integer_to_char_closure_exit_1:
MOV(IND(199), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_plus_closure_start_1));
JUMP(L_plus_closure_exit_1);
L_plus_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_plus */
CMP(FPARG(1), IMM(0));
JUMP_LT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), IMM(0));
MOV(INDD(R0, 2), IMM(1));
MOV(R1, FPARG(1));
L_plus_calc_loop:
CMP(R1, IMM(0));
JUMP_EQ(L_plus_end);
MOV(R2, FPARG(1+R1));
CMP(IND(R2), IMM(T_INTEGER));
JUMP_NE(L_plus_add_fractions);
PUSH(R0);
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), INDD(R2, 1));
MOV(INDD(R0, 2), IMM(1));
MOV(R2, R0);
POP(R0);
L_plus_add_fractions:
CMP(IND(R2), IMM(T_FRACTION));
JUMP_NE(L_error_undefined);
PUSH(R0);
PUSH(R2);
CALL(ADD_FRACTIONS);
DROP(2);
DECR(R1);
JUMP(L_plus_calc_loop);
L_plus_end:
PUSH(R0);
CALL(NORMALIZE_FRACTION);
DROP(1);
POP(R2);
POP(R1);
/* gen_plus_end */
POP(FP);
RETURN;
L_plus_closure_exit_1:
MOV(IND(140), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_multiply_closure_start_1));
JUMP(L_multiply_closure_exit_1);
L_multiply_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_multiply */
CMP(FPARG(1), IMM(0));
JUMP_LT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), IMM(1));
MOV(INDD(R0, 2), IMM(1));
MOV(R1, FPARG(1));
L_multiply_calc_loop:
CMP(R1, IMM(0));
JUMP_EQ(L_multiply_end);
MOV(R2, FPARG(1+R1));
DECR(R1);
MUL(INDD(R0, 1), INDD(R2, 1));
CMP(IND(R2), IMM(T_INTEGER));
JUMP_EQ(L_multiply_calc_loop);
CMP(IND(R2), IMM(T_FRACTION));
JUMP_NE(L_error_undefined);
MUL(INDD(R0, 2), INDD(R2, 2));
JUMP(L_multiply_calc_loop);
L_multiply_end:
PUSH(R0);
CALL(NORMALIZE_FRACTION);
DROP(1);
POP(R2);
POP(R1);
/* gen_multiply_end */
POP(FP);
RETURN;
L_multiply_closure_exit_1:
MOV(IND(115), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_divide_closure_start_1));
JUMP(L_divide_closure_exit_1);
L_divide_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_divide */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
PUSH(R3);
MOV(R1, FPARG(2));
MOV(R0, R1);
CMP(IND(R0), IMM(T_FRACTION));
JUMP_EQ(L_divide_flip_first_arg);
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), INDD(R1, 1));
MOV(INDD(R0, 2), IMM(1));
L_divide_flip_first_arg:
CMP(FPARG(1), IMM(1));
JUMP_NE(L_divide_calc_div);
PUSH(INDD(R0, 1));
MOV(INDD(R0, 1), INDD(R0, 2));
POP(INDD(R0, 2));
MOV(R1,R0);
JUMP(L_divide_end);
L_divide_calc_div:
MOV(R2, IMM(2));
MOV(R1, R0);
L_divide_div_loop:
CMP(R2, FPARG(1));
JUMP_GT(L_divide_end);
MOV(R3, FPARG(1+R2));
CMP(IND(R3), IMM(T_FRACTION));
JUMP_EQ(L_divide_flip_arg);
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_FRACTION));
MOV(INDD(R0, 1), INDD(R3, 1));
MOV(INDD(R0, 2), IMM(1));
MOV(R3, R0);
L_divide_flip_arg:
PUSH(INDD(R3, 1));
MOV(INDD(R3, 1), INDD(R3, 2));
POP(INDD(R3, 2));
MUL(INDD(R1, 1), INDD(R3, 1));
MUL(INDD(R1, 2), INDD(R3, 2));
INCR(R2);
JUMP(L_divide_div_loop);
L_divide_end:
PUSH(R1);
CALL(NORMALIZE_FRACTION);
DROP(1);
POP(R3);
POP(R2);
POP(R1);
/* gen_divide_end */
POP(FP);
RETURN;
L_divide_closure_exit_1:
MOV(IND(202), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_apply_closure_start_1));
JUMP(L_apply_closure_exit_1);
L_apply_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_apply */
CMP(FPARG(1), IMM(2));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(2));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
PUSH(R3);
MOV(R1, FPARG(3));
PUSH(R1);
CALL(LIST_LENGTH);
DROP(1);
MOV(R2, SP);
ADD(R2, R0);
DECR(R2);
L_apply_unravel_args_loop:
CMP(R1, IMM(SOB_NIL));
JUMP_EQ(L_apply_build_stack_args);
MOV(STACK(R2), INDD(R1, 1));
MOV(R1, INDD(R1, 2));
DECR(R2);
JUMP(L_apply_unravel_args_loop);
L_apply_build_stack_args:
MOV(R1, FPARG(2));
MOV(R2, SP);
ADD(SP, R0);
PUSH(R0);
PUSH(INDD(R1, 1));
PUSH(FPARG(-1));
PUSH(FPARG(-2));
PUSH(FPARG(-3));
PUSH(FPARG(-4));
PUSH(FPARG(-5));
PUSH(INDD(R1, 2));
MOV(R3, FP);
SUB(R3, IMM(6));
L_apply_shift_stack:
CMP(R2, SP);
JUMP_GE(L_apply_set_stack_regs);
MOV(STACK(R3), STACK(R2));
INCR(R3);
INCR(R2);
JUMP(L_apply_shift_stack);
L_apply_set_stack_regs:
MOV(SP, R3);
POP(R0);
POP(R3);
POP(R2);
POP(R1);
POP(FP);
JUMPA(R0);
/* gen_apply_end */
POP(FP);
RETURN;
L_apply_closure_exit_1:
MOV(IND(118), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_is_positive_closure_start_1));
JUMP(L_is_positive_closure_exit_1);
L_is_positive_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_is_positive */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
MOV(R0, IMM(SOB_TRUE));
MOV(R1, FPARG(2));
CMP(INDD(R1, 1), IMM(0));
JUMP_GT(L_is_positive_end);
MOV(R0, IMM(SOB_FALSE));
L_is_positive_end:
POP(R1);
/* gen_is_positive_end */
POP(FP);
RETURN;
L_is_positive_closure_exit_1:
MOV(IND(127), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_string_to_symbol_closure_start_1));
JUMP(L_string_to_symbol_closure_exit_1);
L_string_to_symbol_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_string_to_symbol */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, FPARG(2));
CMP(IND(R1), IMM(T_STRING));
JUMP_NE(L_error_undefined);
MOV(R2, IMM(90));
MOV(R3, R2);
MOV(R2, IND(R2));
L_string_to_symbol_loop:
CMP(R2, IMM(0));
JUMP_EQ(L_string_to_symbol_string_not_found);
PUSH(R1);
PUSH(INDD(R2, 0));
CALL(COMPARE_STRINGS);
DROP(2);
MOV(R3, R2);
INCR(R3);
MOV(R4, IND(R2));
CMP(R0, IMM(SOB_TRUE));
JUMP_EQ(L_string_to_symbol_string_found);
MOV(R2, INDD(R2, 1));
JUMP(L_string_to_symbol_loop);
L_string_to_symbol_string_not_found:
PUSH(2);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), R1);
MOV(INDD(R0, 1), IMM(0));
MOV(IND(R3), R0);
MOV(R4, R1);
L_string_to_symbol_string_found:
PUSH(R4);
CALL(MAKE_SOB_SYMBOL);
DROP(1);
L_string_to_symbol_exit:
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* gen_string_to_symbol_end */
POP(FP);
RETURN;
L_string_to_symbol_closure_exit_1:
MOV(IND(205), R0)
/* closure_gen_end */

/* closure_gen */
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0, 0), IMM(T_CLOSURE));
MOV(INDD(R0, 1), IMM(222222));
MOV(INDD(R0, 2), LABEL(L_symbol_to_string_closure_start_1));
JUMP(L_symbol_to_string_closure_exit_1);
L_symbol_to_string_closure_start_1:
PUSH(FP);
MOV(FP, SP);
/* gen_symbol_to_string */
CMP(FPARG(1), IMM(1));
JUMP_LT(L_error_wrong_number_of_arguments);
CMP(FPARG(1), IMM(1));
JUMP_GT(L_error_wrong_number_of_arguments);
MOV(R0, FPARG(2));
CMP(IND(R0), IMM(T_SYMBOL));
JUMP_NE(L_error_undefined);
MOV(R0, INDD(R0, 1));
/* gen_symbol_to_string_end */
POP(FP);
RETURN;
L_symbol_to_string_closure_exit_1:
MOV(IND(206), R0)
/* closure_gen_end */
/* CISC_functions_end */
/* compiled_code */
/* gen_define_list */
/* gen_lambda_opt */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_113:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_113);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_113);

L_copy_params_113:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_113:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_113);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_113);

L_write_closure_113:
MOV(INDD(R1, 2), IMM(&&L_closure_code_113));
JUMP(L_closure_exit_113);

L_closure_code_113:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_stack_fix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, IMM(SOB_NIL));
MOV(R2, FPARG(1));
L_opt_list_loop_start_31:
CMP(R2,0);
JUMP_LE(L_opt_list_loop_exit_31);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_31);
L_opt_list_loop_exit_31:

MOV(R2, FPARG(1));
SUB(R2, 0);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_31);
MOV(R3, IMM(0+1));

L_opt_stack_fix1_start_31:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_31);
L_opt_stack_fix1_exit_31:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_31:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_31);

MOV(FPARG(R3-1), R1);
MOV(FP, FP-R2+1);
DROP(2);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
MOV(SP, FP);
MOV(FPARG(1) ,0+1);
/* lambda_stack_fix-end */
/* lambda_suffix */
/* gen_seq */
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_113:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_opt_end */

PUSH(R0);
MOV(R0, IMM(165));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_50);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_50:
/* print_result_end */

/* gen_define_cons */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_114:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_114);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_114);

L_copy_params_114:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_114:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_114);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_114);

L_write_closure_114:
MOV(INDD(R1, 2), IMM(&&L_closure_code_114));
JUMP(L_closure_exit_114);

L_closure_code_114:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(165));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(1));
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_115:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_115);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_115);

L_copy_params_115:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_115:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_115);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_115);

L_write_closure_115:
MOV(INDD(R1, 2), IMM(&&L_closure_code_115));
JUMP(L_closure_exit_115);

L_closure_code_115:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic */
PUSH(R1);
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 1));
/* gen_var_bound_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(166));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_115:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(1));
L_overwrite_previous_frame_81:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_81);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_81);
L_run_body_81:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_114:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */

PUSH(R0);
MOV(R0, IMM(120));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_51);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_51:
/* print_result_end */

/* gen_define_append */
/* gen_lambda_opt */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_116:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_116);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_116);

L_copy_params_116:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_116:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_116);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_116);

L_write_closure_116:
MOV(INDD(R1, 2), IMM(&&L_closure_code_116));
JUMP(L_closure_exit_116);

L_closure_code_116:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_stack_fix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, IMM(SOB_NIL));
MOV(R2, FPARG(1));
L_opt_list_loop_start_32:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_32);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_32);
L_opt_list_loop_exit_32:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_32);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_32:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_32);
L_opt_stack_fix1_exit_32:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_32:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_32);

MOV(FPARG(R3-1), R1);
MOV(FP, FP-R2+1);
DROP(2);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
MOV(SP, FP);
MOV(FPARG(1) ,1+1);
/* lambda_stack_fix-end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic_tp */
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_117:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_117);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_117);

L_copy_params_117:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_117:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_117);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_117);

L_write_closure_117:
MOV(INDD(R1, 2), IMM(&&L_closure_code_117));
JUMP(L_closure_exit_117);

L_closure_code_117:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_set_param */
/* gen_box */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R0), FPARG(2));
/* gen_box */

MOV(FPARG(2), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
/* gen_set_param */
/* gen_box */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R0), FPARG(3));
/* gen_box */

MOV(FPARG(3), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
/* gen_box_set */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_118:
CMP(R3, IMM(2));
JUMP_GE(L_copy_params_118);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_118);

L_copy_params_118:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_118:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_118);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_118);

L_write_closure_118:
MOV(INDD(R1, 2), IMM(&&L_closure_code_118));
JUMP(L_closure_exit_118);

L_closure_code_118:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_56);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
JUMP(L_if_end_56);
L_if_else_56:
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(2);
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(120));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_83:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_83);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_83);
L_run_body_83:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_56:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_118:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
POP(IND(R0));
MOV(R0, SOB_VOID);
/* gen_box_set_end */
/* gen_box_set */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_119:
CMP(R3, IMM(2));
JUMP_GE(L_copy_params_119);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_119);

L_copy_params_119:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_119:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_119);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_119);

L_write_closure_119:
MOV(INDD(R1, 2), IMM(&&L_closure_code_119));
JUMP(L_closure_exit_119);

L_closure_code_119:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_57);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
JUMP(L_if_end_57);
L_if_else_57:
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 1));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_84:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_84);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_84);
L_run_body_84:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_57:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_119:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
POP(IND(R0));
MOV(R0, SOB_VOID);
/* gen_box_set_end */
/* gen_applic_tp */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 1));
/* gen_var_bound_end */
PUSH(R0);
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_box_get */
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_85:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_85);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_85);
L_run_body_85:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_117:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_82:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_82);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_82);
L_run_body_82:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_116:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_opt_end */

PUSH(R0);
MOV(R0, IMM(164));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_52);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_52:
/* print_result_end */

/* gen_define_not */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_120:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_120);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_120);

L_copy_params_120:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_120:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_120);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_120);

L_write_closure_120:
MOV(INDD(R1, 2), IMM(&&L_closure_code_120));
JUMP(L_closure_exit_120);

L_closure_code_120:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_58);
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
JUMP(L_if_end_58);
L_if_else_58:
/* gen_const */
MOV(R0, IMM(104));
/* gen_const_end */
L_if_end_58:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_120:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */

PUSH(R0);
MOV(R0, IMM(156));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_53);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_53:
/* print_result_end */

/* gen_define_map */
/* gen_applic */
PUSH(R1);
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
PUSH(R0);
PUSH(2);
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_121:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_121);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_121);

L_copy_params_121:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_121:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_121);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_121);

L_write_closure_121:
MOV(INDD(R1, 2), IMM(&&L_closure_code_121));
JUMP(L_closure_exit_121);

L_closure_code_121:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_set_param */
/* gen_box */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R0), FPARG(2));
/* gen_box */

MOV(FPARG(2), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
/* gen_set_param */
/* gen_box */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R0), FPARG(3));
/* gen_box */

MOV(FPARG(3), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
/* gen_box_set */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_122:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_122);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_122);

L_copy_params_122:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_122:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_122);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_122);

L_write_closure_122:
MOV(INDD(R1, 2), IMM(&&L_closure_code_122));
JUMP(L_closure_exit_122);

L_closure_code_122:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_59);
/* gen_const */
MOV(R0, IMM(101));
/* gen_const_end */
JUMP(L_if_end_59);
L_if_else_59:
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(120));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_86:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_86);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_86);
L_run_body_86:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_59:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_122:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
POP(IND(R0));
MOV(R0, SOB_VOID);
/* gen_box_set_end */
/* gen_box_set */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_123:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_123);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_123);

L_copy_params_123:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_123:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_123);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_123);

L_write_closure_123:
MOV(INDD(R1, 2), IMM(&&L_closure_code_123));
JUMP(L_closure_exit_123);

L_closure_code_123:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_60);
/* gen_const */
MOV(R0, IMM(101));
/* gen_const_end */
JUMP(L_if_end_60);
L_if_else_60:
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
PUSH(R0);
PUSH(2);
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 1));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
PUSH(R0);
PUSH(2);
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(118));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(120));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_87:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_87);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_87);
L_run_body_87:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_60:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_123:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
POP(IND(R0));
MOV(R0, SOB_VOID);
/* gen_box_set_end */
/* gen_lambda_opt */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_124:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_124);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_124);

L_copy_params_124:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_124:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_124);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_124);

L_write_closure_124:
MOV(INDD(R1, 2), IMM(&&L_closure_code_124));
JUMP(L_closure_exit_124);

L_closure_code_124:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_stack_fix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, IMM(SOB_NIL));
MOV(R2, FPARG(1));
L_opt_list_loop_start_33:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_33);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_33);
L_opt_list_loop_exit_33:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_33);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_33:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_33);
L_opt_stack_fix1_exit_33:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_33:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_33);

MOV(FPARG(R3-1), R1);
MOV(FP, FP-R2+1);
DROP(2);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
MOV(SP, FP);
MOV(FPARG(1) ,1+1);
/* lambda_stack_fix-end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic_tp */
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 1));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_88:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_88);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_88);
L_run_body_88:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_124:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_opt_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_121:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */

PUSH(R0);
MOV(R0, IMM(116));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_54);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_54:
/* print_result_end */

/* gen_define_- */
/* gen_lambda_opt */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_125:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_125);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_125);

L_copy_params_125:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_125:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_125);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_125);

L_write_closure_125:
MOV(INDD(R1, 2), IMM(&&L_closure_code_125));
JUMP(L_closure_exit_125);

L_closure_code_125:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_stack_fix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, IMM(SOB_NIL));
MOV(R2, FPARG(1));
L_opt_list_loop_start_34:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_34);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_34);
L_opt_list_loop_exit_34:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_34);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_34:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_34);
L_opt_stack_fix1_exit_34:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_34:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_34);

MOV(FPARG(R3-1), R1);
MOV(FP, FP-R2+1);
DROP(2);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
MOV(SP, FP);
MOV(FPARG(1) ,1+1);
/* lambda_stack_fix-end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_61);
/* gen_applic_tp */
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(106));
/* gen_const_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(115));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_91:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_91);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_91);
L_run_body_91:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
JUMP(L_if_end_61);
L_if_else_61:
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_126:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_126);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_126);

L_copy_params_126:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_126:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_126);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_126);

L_write_closure_126:
MOV(INDD(R1, 2), IMM(&&L_closure_code_126));
JUMP(L_closure_exit_126);

L_closure_code_126:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic_tp */
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(106));
/* gen_const_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(115));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_89:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_89);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_89);
L_run_body_89:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_126:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(116));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(120));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_free */
MOV(R0, IMM(140));
MOV(R0, IND(R0));
/* gen_var_free_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(118));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_90:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_90);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_90);
L_run_body_90:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_61:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_125:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_opt_end */

PUSH(R0);
MOV(R0, IMM(126));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_55);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_55:
/* print_result_end */

/* gen_define_remainder */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_127:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_127);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_127);

L_copy_params_127:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_127:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_127);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_127);

L_write_closure_127:
MOV(INDD(R1, 2), IMM(&&L_closure_code_127));
JUMP(L_closure_exit_127);

L_closure_code_127:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(108));
/* gen_const_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(119));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_62);
/* gen_set_param */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(126));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */

MOV(FPARG(3), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
JUMP(L_if_end_62);
L_if_else_62:
/* gen_const */
MOV(R0, IMM(100));
/* gen_const_end */
L_if_end_62:
/* gen_if_end */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(117));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_63);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
JUMP(L_if_end_63);
L_if_else_63:
/* gen_applic_tp */
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(126));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(132));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_92:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_92);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_92);
L_run_body_92:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_63:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_127:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */

PUSH(R0);
MOV(R0, IMM(132));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_56);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_56:
/* print_result_end */

/* gen_define_< */
/* gen_applic */
PUSH(R1);
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
PUSH(R0);
PUSH(1);
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_128:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_128);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_128);

L_copy_params_128:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_128:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_128);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_128);

L_write_closure_128:
MOV(INDD(R1, 2), IMM(&&L_closure_code_128));
JUMP(L_closure_exit_128);

L_closure_code_128:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_set_param */
/* gen_box */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R0), FPARG(2));
/* gen_box */

MOV(FPARG(2), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
/* gen_box_set */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_129:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_129);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_129);

L_copy_params_129:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_129:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_129);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_129);

L_write_closure_129:
MOV(INDD(R1, 2), IMM(&&L_closure_code_129));
JUMP(L_closure_exit_129);

L_closure_code_129:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_64);
/* gen_const */
MOV(R0, IMM(104));
/* gen_const_end */
JUMP(L_if_end_64);
L_if_else_64:
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_applic */
PUSH(R1);
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(123));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(126));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(127));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_65);
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(122));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(1));
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(1));
L_overwrite_previous_frame_93:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_93);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_93);
L_run_body_93:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
JUMP(L_if_end_65);
L_if_else_65:
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
L_if_end_65:
/* gen_if_end */
L_if_end_64:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_129:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
POP(IND(R0));
MOV(R0, SOB_VOID);
/* gen_box_set_end */
/* gen_lambda_opt */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_130:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_130);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_130);

L_copy_params_130:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_130:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_130);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_130);

L_write_closure_130:
MOV(INDD(R1, 2), IMM(&&L_closure_code_130));
JUMP(L_closure_exit_130);

L_closure_code_130:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_stack_fix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, IMM(SOB_NIL));
MOV(R2, FPARG(1));
L_opt_list_loop_start_35:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_35);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_35);
L_opt_list_loop_exit_35:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_35);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_35:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_35);
L_opt_stack_fix1_exit_35:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_35:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_35);

MOV(FPARG(R3-1), R1);
MOV(FP, FP-R2+1);
DROP(2);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
MOV(SP, FP);
MOV(FPARG(1) ,1+1);
/* lambda_stack_fix-end */
/* lambda_suffix */
/* gen_seq */
/* gen_if */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(121));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_66);
/* gen_const */
MOV(R0, IMM(104));
/* gen_const_end */
JUMP(L_if_end_66);
L_if_else_66:
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(120));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
PUSH(IMM(1));
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(1));
L_overwrite_previous_frame_94:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_94);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_94);
L_run_body_94:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_66:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_130:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_opt_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_128:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */

PUSH(R0);
MOV(R0, IMM(117));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_57);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_57:
/* print_result_end */

/* gen_define_> */
/* gen_lambda_opt */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_131:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_131);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_131);

L_copy_params_131:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_131:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_131);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_131);

L_write_closure_131:
MOV(INDD(R1, 2), IMM(&&L_closure_code_131));
JUMP(L_closure_exit_131);

L_closure_code_131:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_stack_fix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
MOV(R1, IMM(SOB_NIL));
MOV(R2, FPARG(1));
L_opt_list_loop_start_36:
CMP(R2,0);
JUMP_LE(L_opt_list_loop_exit_36);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_36);
L_opt_list_loop_exit_36:

MOV(R2, FPARG(1));
SUB(R2, 0);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_36);
MOV(R3, IMM(0+1));

L_opt_stack_fix1_start_36:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_36);
L_opt_stack_fix1_exit_36:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_36:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_36);

MOV(FPARG(R3-1), R1);
MOV(FP, FP-R2+1);
DROP(2);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
MOV(SP, FP);
MOV(FPARG(1) ,0+1);
/* lambda_stack_fix-end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic_tp */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_132:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_132);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_132);

L_copy_params_132:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_132:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_132);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_132);

L_write_closure_132:
MOV(INDD(R1, 2), IMM(&&L_closure_code_132));
JUMP(L_closure_exit_132);

L_closure_code_132:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_applic_tp */
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(106));
/* gen_const_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(115));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_95:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_95);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_95);
L_run_body_95:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_132:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(116));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
PUSH(R0);
/* gen_var_free */
MOV(R0, IMM(117));
MOV(R0, IND(R0));
/* gen_var_free_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(118));
MOV(R0, IND(R0));
/* gen_var_free_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
PUSH(FPARG(-1));
PUSH(R1);
PUSH(R2);
MOV(R1, FP);
MOV(SP, FP);
SUB(SP, IMM(4));
SUB(SP, FPARG(1));
MOV(FP, FPARG(-2));
MOV(R2, IMM(5));
ADD(R2, IMM(2));
L_overwrite_previous_frame_96:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_96);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_96);
L_run_body_96:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_131:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_opt_end */

PUSH(R0);
MOV(R0, IMM(119));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_58);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_58:
/* print_result_end */

/* gen_applic */
PUSH(R1);
PUSH(0);
/* gen_applic */
PUSH(R1);
/* gen_const */
MOV(R0, IMM(112));
/* gen_const_end */
PUSH(R0);
PUSH(1);
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_133:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_133);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_133);

L_copy_params_133:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_133:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_133);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_133);

L_write_closure_133:
MOV(INDD(R1, 2), IMM(&&L_closure_code_133));
JUMP(L_closure_exit_133);

L_closure_code_133:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_set_param */
/* gen_box */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R0), FPARG(2));
/* gen_box */

MOV(FPARG(2), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
/* gen_applic */
PUSH(R1);
PUSH(0);
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_134:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_134);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_134);

L_copy_params_134:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_134:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_134);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_134);

L_write_closure_134:
MOV(INDD(R1, 2), IMM(&&L_closure_code_134));
JUMP(L_closure_exit_134);

L_closure_code_134:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_box_set */
/* gen_const */
MOV(R0, IMM(110));
/* gen_const_end */
PUSH(R0);
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
POP(IND(R0));
MOV(R0, SOB_VOID);
/* gen_box_set_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_134:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
/* gen_lambda_simple */
/* gen_lambda */
/* lambda_prefix */
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(R4);
PUSH(R5);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(R1, R0);
MOV(IND(R1), IMM(T_CLOSURE));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(INDD(R1, 1), R0);

MOV(R2, FPARG(0));
MOV(R3, IMM(0));
MOV(R4, IMM(1));
MOV(R5, INDD(R1, 1));

L_copy_env_loop_135:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_135);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_135);

L_copy_params_135:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_135:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_135);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_135);

L_write_closure_135:
MOV(INDD(R1, 2), IMM(&&L_closure_code_135));
JUMP(L_closure_exit_135);

L_closure_code_135:
PUSH(FP);
MOV(FP, SP);

/* lambda_prefix_end */
/* lambda_suffix */
/* gen_seq */
/* gen_box_get */
/* gen_var_bound */
MOV(R0, FPARG(0));
MOV(R0, INDD(R0, 0));
MOV(R0, INDD(R0, 0));
/* gen_var_bound_end */
MOV(R0, IND(R0));
/* gen_box_get_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_135:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_133:
MOV(R0, R1);
POP(R5);
POP(R4);
POP(R3);
POP(R2);
POP(R1);
/* lambda_suffix_end */
/* gen_lambda_end */
/* gen_lambda_simple_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
CMP(IND(R0), IMM(T_CLOSURE));
JUMP_NE(L_error_not_a_closure);
PUSH(INDD(R0, 1));
CALLA(INDD(R0, 2));
DROP(1);
POP(R1);
DROP(R1);
POP(R1);
/* gen_applic_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_59);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_59:
/* print_result_end */
/* compiled_code_end */

JUMP(L_end_error_handler);
L_error_out_of_bounds:
printf("Error: Index out of bounds.\n");
JUMP(L_end_error_handler);
L_error_not_a_closure:
printf("Error: Not a closure.\n");
JUMP(L_end_error_handler);
L_error_wrong_number_of_arguments:
printf("Error: Wrong number of arguments.\n");
JUMP(L_end_error_handler);
L_error_undefined:
printf("Error: Undefined.\n");
L_end_error_handler:
STOP_MACHINE;

return 0;
}
