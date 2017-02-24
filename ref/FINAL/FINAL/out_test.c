#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"

#define DO_SHOW 1
#include "debug_macros.h"

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
PUSH(IMM(207));
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
MOV(ADDR(112 + 1), IMM(5));
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
MOV(IND(124), R0)
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
MOV(IND(123), R0)
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
MOV(IND(122), R0)
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
MOV(IND(173), R0)
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
MOV(IND(174), R0)
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
MOV(IND(175), R0)
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
MOV(IND(176), R0)
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
MOV(IND(177), R0)
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
MOV(IND(178), R0)
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
MOV(IND(179), R0)
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
MOV(IND(180), R0)
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
MOV(IND(181), R0)
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
MOV(IND(182), R0)
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
MOV(IND(183), R0)
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
MOV(IND(184), R0)
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
MOV(IND(185), R0)
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
MOV(IND(186), R0)
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
MOV(IND(167), R0)
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
MOV(IND(188), R0)
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
MOV(IND(189), R0)
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
MOV(IND(190), R0)
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
MOV(IND(191), R0)
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
MOV(IND(192), R0)
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
MOV(IND(193), R0)
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
MOV(IND(194), R0)
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
MOV(IND(195), R0)
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
MOV(IND(196), R0)
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
MOV(IND(197), R0)
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
MOV(IND(198), R0)
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
MOV(IND(199), R0)
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
MOV(IND(200), R0)
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
MOV(IND(115), R0)
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
MOV(IND(116), R0)
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
MOV(IND(203), R0)
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
MOV(IND(119), R0)
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
MOV(IND(128), R0)
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
MOV(IND(206), R0)
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
MOV(IND(207), R0)
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

L_copy_env_loop_1:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_1);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_1);

L_copy_params_1:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_1:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_1);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_1);

L_write_closure_1:
MOV(INDD(R1, 2), IMM(&&L_closure_code_1));
JUMP(L_closure_exit_1);

L_closure_code_1:
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
L_opt_list_loop_start_1:
CMP(R2,0);
JUMP_LE(L_opt_list_loop_exit_1);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_1);
L_opt_list_loop_exit_1:

MOV(R2, FPARG(1));
SUB(R2, 0);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_1);
MOV(R3, IMM(0+1));

L_opt_stack_fix1_start_1:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_1);
L_opt_stack_fix1_exit_1:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_1:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_1);

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

L_closure_exit_1:
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
MOV(R0, IMM(166));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_1);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_1:
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

L_copy_env_loop_2:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_2);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_2);

L_copy_params_2:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_2:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_2);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_2);

L_write_closure_2:
MOV(INDD(R1, 2), IMM(&&L_closure_code_2));
JUMP(L_closure_exit_2);

L_closure_code_2:
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

L_copy_env_loop_3:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_3);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_3);

L_copy_params_3:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_3:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_3);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_3);

L_write_closure_3:
MOV(INDD(R1, 2), IMM(&&L_closure_code_3));
JUMP(L_closure_exit_3);

L_closure_code_3:
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
MOV(R0, IMM(167));
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

L_closure_exit_3:
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
L_overwrite_previous_frame_1:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_1);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_1);
L_run_body_1:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_2:
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
MOV(R0, IMM(121));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_2);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_2:
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

L_copy_env_loop_4:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_4);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_4);

L_copy_params_4:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_4:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_4);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_4);

L_write_closure_4:
MOV(INDD(R1, 2), IMM(&&L_closure_code_4));
JUMP(L_closure_exit_4);

L_closure_code_4:
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
L_opt_list_loop_start_2:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_2);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_2);
L_opt_list_loop_exit_2:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_2);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_2:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_2);
L_opt_stack_fix1_exit_2:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_2:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_2);

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

L_copy_env_loop_5:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_5);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_5);

L_copy_params_5:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_5:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_5);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_5);

L_write_closure_5:
MOV(INDD(R1, 2), IMM(&&L_closure_code_5));
JUMP(L_closure_exit_5);

L_closure_code_5:
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

L_copy_env_loop_6:
CMP(R3, IMM(2));
JUMP_GE(L_copy_params_6);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_6);

L_copy_params_6:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_6:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_6);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_6);

L_write_closure_6:
MOV(INDD(R1, 2), IMM(&&L_closure_code_6));
JUMP(L_closure_exit_6);

L_closure_code_6:
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
JUMP(L_if_end_1);
L_if_else_1:
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
MOV(R0, IMM(124));
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
MOV(R0, IMM(121));
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
L_overwrite_previous_frame_3:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_3);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_3);
L_run_body_3:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_1:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_6:
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

L_copy_env_loop_7:
CMP(R3, IMM(2));
JUMP_GE(L_copy_params_7);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_7);

L_copy_params_7:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_7:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_7);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_7);

L_write_closure_7:
MOV(INDD(R1, 2), IMM(&&L_closure_code_7));
JUMP(L_closure_exit_7);

L_closure_code_7:
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_2);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
JUMP(L_if_end_2);
L_if_else_2:
/* gen_applic_tp */
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
MOV(R0, IMM(124));
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
L_overwrite_previous_frame_4:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_4);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_4);
L_run_body_4:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_2:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_7:
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
L_overwrite_previous_frame_5:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_5);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_5);
L_run_body_5:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_5:
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
L_overwrite_previous_frame_2:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_2);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_2);
L_run_body_2:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_4:
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
JUMP_EQ(L_print_result_3);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_3:
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

L_copy_env_loop_8:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_8);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_8);

L_copy_params_8:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_8:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_8);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_8);

L_write_closure_8:
MOV(INDD(R1, 2), IMM(&&L_closure_code_8));
JUMP(L_closure_exit_8);

L_closure_code_8:
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
JUMP_EQ(L_if_else_3);
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
JUMP(L_if_end_3);
L_if_else_3:
/* gen_const */
MOV(R0, IMM(104));
/* gen_const_end */
L_if_end_3:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_8:
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
MOV(R0, IMM(157));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_4);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_4:
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

L_copy_env_loop_9:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_9);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_9);

L_copy_params_9:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_9:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_9);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_9);

L_write_closure_9:
MOV(INDD(R1, 2), IMM(&&L_closure_code_9));
JUMP(L_closure_exit_9);

L_closure_code_9:
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

L_copy_env_loop_10:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_10);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_10);

L_copy_params_10:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_10:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_10);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_10);

L_write_closure_10:
MOV(INDD(R1, 2), IMM(&&L_closure_code_10));
JUMP(L_closure_exit_10);

L_closure_code_10:
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_4);
/* gen_const */
MOV(R0, IMM(101));
/* gen_const_end */
JUMP(L_if_end_4);
L_if_else_4:
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
MOV(R0, IMM(124));
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
MOV(R0, IMM(121));
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
L_overwrite_previous_frame_6:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_6);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_6);
L_run_body_6:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_4:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_10:
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

L_copy_env_loop_11:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_11);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_11);

L_copy_params_11:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_11:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_11);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_11);

L_write_closure_11:
MOV(INDD(R1, 2), IMM(&&L_closure_code_11));
JUMP(L_closure_exit_11);

L_closure_code_11:
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
MOV(R0, IMM(124));
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_5);
/* gen_const */
MOV(R0, IMM(101));
/* gen_const_end */
JUMP(L_if_end_5);
L_if_else_5:
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
MOV(R0, IMM(124));
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
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(121));
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
L_overwrite_previous_frame_7:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_7);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_7);
L_run_body_7:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_5:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_11:
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

L_copy_env_loop_12:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_12);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_12);

L_copy_params_12:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_12:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_12);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_12);

L_write_closure_12:
MOV(INDD(R1, 2), IMM(&&L_closure_code_12));
JUMP(L_closure_exit_12);

L_closure_code_12:
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
L_opt_list_loop_start_3:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_3);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_3);
L_opt_list_loop_exit_3:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_3);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_3:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_3);
L_opt_stack_fix1_exit_3:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_3:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_3);

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
L_overwrite_previous_frame_8:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_8);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_8);
L_run_body_8:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_12:
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

L_closure_exit_9:
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
JUMP_EQ(L_print_result_5);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_5:
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

L_copy_env_loop_13:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_13);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_13);

L_copy_params_13:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_13:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_13);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_13);

L_write_closure_13:
MOV(INDD(R1, 2), IMM(&&L_closure_code_13));
JUMP(L_closure_exit_13);

L_closure_code_13:
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
L_opt_list_loop_start_4:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_4);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_4);
L_opt_list_loop_exit_4:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_4);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_4:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_4);
L_opt_stack_fix1_exit_4:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_4:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_4);

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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_6);
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
MOV(R0, IMM(116));
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
L_overwrite_previous_frame_11:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_11);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_11);
L_run_body_11:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
JUMP(L_if_end_6);
L_if_else_6:
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

L_copy_env_loop_14:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_14);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_14);

L_copy_params_14:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_14:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_14);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_14);

L_write_closure_14:
MOV(INDD(R1, 2), IMM(&&L_closure_code_14));
JUMP(L_closure_exit_14);

L_closure_code_14:
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
MOV(R0, IMM(116));
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
L_overwrite_previous_frame_9:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_9);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_9);
L_run_body_9:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_14:
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
PUSH(R0);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
PUSH(R0);
PUSH(2);
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
PUSH(R0);
/* gen_var_free */
MOV(R0, IMM(115));
MOV(R0, IND(R0));
/* gen_var_free_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(119));
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
L_overwrite_previous_frame_10:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_10);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_10);
L_run_body_10:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_6:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_13:
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
MOV(R0, IMM(127));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_6);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_6:
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

L_copy_env_loop_15:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_15);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_15);

L_copy_params_15:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_15:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_15);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_15);

L_write_closure_15:
MOV(INDD(R1, 2), IMM(&&L_closure_code_15));
JUMP(L_closure_exit_15);

L_closure_code_15:
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_7);
/* gen_set_param */
/* gen_applic */
PUSH(R1);
/* gen_var_param */
MOV(R0, FPARG(2+1));
/* gen_var_param_end */
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

MOV(FPARG(3), R0);
MOV(R0, IMM(SOB_VOID));
/* gen_set_param_end */
JUMP(L_if_end_7);
L_if_else_7:
/* gen_const */
MOV(R0, IMM(100));
/* gen_const_end */
L_if_end_7:
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_8);
/* gen_var_param */
MOV(R0, FPARG(2+0));
/* gen_var_param_end */
JUMP(L_if_end_8);
L_if_else_8:
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
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(133));
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
L_overwrite_previous_frame_12:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_12);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_12);
L_run_body_12:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_8:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_15:
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
MOV(R0, IMM(133));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_7);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_7:
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

L_copy_env_loop_16:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_16);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_16);

L_copy_params_16:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_16:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_16);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_16);

L_write_closure_16:
MOV(INDD(R1, 2), IMM(&&L_closure_code_16));
JUMP(L_closure_exit_16);

L_closure_code_16:
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

L_copy_env_loop_17:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_17);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_17);

L_copy_params_17:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_17:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_17);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_17);

L_write_closure_17:
MOV(INDD(R1, 2), IMM(&&L_closure_code_17));
JUMP(L_closure_exit_17);

L_closure_code_17:
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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_9);
/* gen_const */
MOV(R0, IMM(104));
/* gen_const_end */
JUMP(L_if_end_9);
L_if_else_9:
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
MOV(R0, IMM(124));
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
MOV(R0, IMM(124));
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
PUSH(R0);
PUSH(1);
/* gen_var_free */
MOV(R0, IMM(128));
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
JUMP_EQ(L_if_else_10);
/* gen_applic_tp */
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
L_overwrite_previous_frame_13:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_13);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_13);
L_run_body_13:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
JUMP(L_if_end_10);
L_if_else_10:
/* gen_const */
MOV(R0, IMM(102));
/* gen_const_end */
L_if_end_10:
/* gen_if_end */
L_if_end_9:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_17:
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

L_copy_env_loop_18:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_18);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_18);

L_copy_params_18:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_18:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_18);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_18);

L_write_closure_18:
MOV(INDD(R1, 2), IMM(&&L_closure_code_18));
JUMP(L_closure_exit_18);

L_closure_code_18:
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
L_opt_list_loop_start_5:
CMP(R2,1);
JUMP_LE(L_opt_list_loop_exit_5);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_5);
L_opt_list_loop_exit_5:

MOV(R2, FPARG(1));
SUB(R2, 1);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_5);
MOV(R3, IMM(1+1));

L_opt_stack_fix1_start_5:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_5);
L_opt_stack_fix1_exit_5:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_5:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_5);

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
CMP(R0, IMM(102));
JUMP_EQ(L_if_else_11);
/* gen_const */
MOV(R0, IMM(104));
/* gen_const_end */
JUMP(L_if_end_11);
L_if_else_11:
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
L_overwrite_previous_frame_14:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_14);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_14);
L_run_body_14:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
L_if_end_11:
/* gen_if_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_18:
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

L_closure_exit_16:
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
MOV(R0, IMM(118));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_8);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_8:
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

L_copy_env_loop_19:
CMP(R3, IMM(0));
JUMP_GE(L_copy_params_19);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_19);

L_copy_params_19:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_19:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_19);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_19);

L_write_closure_19:
MOV(INDD(R1, 2), IMM(&&L_closure_code_19));
JUMP(L_closure_exit_19);

L_closure_code_19:
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
L_opt_list_loop_start_6:
CMP(R2,0);
JUMP_LE(L_opt_list_loop_exit_6);
PUSH(R1);
PUSH(FPARG(1+R2));
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R1, R0);
DECR(R2);
JUMP(L_opt_list_loop_start_6);
L_opt_list_loop_exit_6:

MOV(R2, FPARG(1));
SUB(R2, 0);
MOV(R4, FPARG(1));
CMP(R2, IMM(0));
JUMP_EQ(L_opt_stack_fix1_exit_6);
MOV(R3, IMM(0+1));

L_opt_stack_fix1_start_6:
MOV(FPARG(R3+R2), FPARG(R3));
DECR(R3);
CMP(R3, IMM(-3 - 4));
JUMP_GT(L_opt_stack_fix1_start_6);
L_opt_stack_fix1_exit_6:

MOV(R3, R2-2 - 4);
L_opt_stack_fix2_6:
MOV(FPARG(R3-1), FPARG(R3));
INCR(R3);
CMP(R3, R4+2);
JUMP_LT(L_opt_stack_fix2_6);

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

L_copy_env_loop_20:
CMP(R3, IMM(1));
JUMP_GE(L_copy_params_20);
MOV(INDD(R5, R4), INDD(R2, R3));
INCR(R3);
INCR(R4);
JUMP(L_copy_env_loop_20);

L_copy_params_20:
PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(IND(R5), R0);
MOV(R5, R0);

MOV(R2, IMM(2));
MOV(R3, IMM(0));

L_copy_params_loop_20:
CMP(R3, FPARG(1));
JUMP_GE(L_write_closure_20);
MOV(INDD(R5, R3), FPARG(R2));
INCR(R2);
INCR(R3);
JUMP(L_copy_params_loop_20);

L_write_closure_20:
MOV(INDD(R1, 2), IMM(&&L_closure_code_20));
JUMP(L_closure_exit_20);

L_closure_code_20:
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
MOV(R0, IMM(116));
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
L_overwrite_previous_frame_15:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_15);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_15);
L_run_body_15:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_20:
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
PUSH(R0);
/* gen_var_free */
MOV(R0, IMM(118));
MOV(R0, IND(R0));
/* gen_var_free_end */
PUSH(R0);
PUSH(IMM(2));
/* gen_var_free */
MOV(R0, IMM(119));
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
L_overwrite_previous_frame_16:
CMP(R2, IMM(0));
JUMP_EQ(L_run_body_16);
PUSH(STACK(R1));
INCR(R1);
DECR(R2);
JUMP(L_overwrite_previous_frame_16);
L_run_body_16:
POP(R2);
POP(R1);
JUMPA(INDD(R0, 2));
/* gen_applic_tp_end */
/* gen_seq_end */

POP(FP);
RETURN;

L_closure_exit_19:
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
MOV(R0, IMM(120));
POP(IND(R0));
MOV(R0, IMM(SOB_VOID));
/* gen_define_end */
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_9);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_9:
/* print_result_end */

/* gen_applic */
PUSH(R1);
/* gen_const */
MOV(R0, IMM(112));
/* gen_const_end */
PUSH(R0);
/* gen_const */
MOV(R0, IMM(110));
/* gen_const_end */
PUSH(R0);
PUSH(2);
/* gen_var_free */
MOV(R0, IMM(115));
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
/* print_result */
CMP(R0, IMM(SOB_VOID));
JUMP_EQ(L_print_result_10);
PUSH(R0);
CALL(WRITE_SOB);
DROP(1);
CALL(NEWLINE);
L_print_result_10:
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
