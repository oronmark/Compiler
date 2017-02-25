
    #include <stdio.h>
    #include <stdlib.h>
    
    /* change to 0 for no debug info to be printed: */
    #define DO_SHOW 1
    
    #include "cisc.h"
    #include "debug_macros.h"
    
    int main()
    {
      START_MACHINE;
    
      JUMP(CONTINUE);
  
    #include "char.lib"
    #include "io.lib"
    #include "math.lib"
    #include "string.lib"
    #include "system.lib"
    #include "scheme.lib"

    CONTINUE:

    #define SOB_VOID 1
	  #define SOB_NIL 2
	  #define SOB_FALSE 3
	  #define SOB_TRUE 5

/*-------------const table-------------*/

CALL(MAKE_SOB_VOID);
CALL(MAKE_SOB_NIL);
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL);
DROP(IMM(1));
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL);
DROP(IMM(1));

PUSH(IMM(0));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));


PUSH(IMM(1));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));

/*-------------const table-------------*/

/*-------------fvar table-------------*/

MOV(IND(0),13);

//fvar: /
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: map
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: append
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: +
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: =
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: <
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: car
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: cdr
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: integer?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: char?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: pair?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: procedure?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: boolean?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: rational?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: null?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: string?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: symbol?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: string->symbol
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: symbol->string
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: oron/binary-div
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: cons
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: vector-ref
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: oron/binary-add
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: string-length
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: vector-length
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: number?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: numerator
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: denominator
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: not
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: zero?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: char->integer
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: integer->char
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: string-ref
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: vector?
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: set-car!
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: set-cdr!
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: string-set!
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: vector-set!
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: oron/binary=
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: oron/binary<
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: oron/binary>
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: vector
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: make-vector
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);

//fvar: make-string
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);













































/*-------------fvar table-------------*/

/*-------------symbol table-------------*/

MOV(R1,57);
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),SOB_NIL);
DROP(1);

/*-------------symbol table-------------*/

/*-------------runtime-support-------------*/

//CAR
JUMP(L_create_my_car_clos);
L_my_car_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,1));
POP(FP);
RETURN;

L_create_my_car_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_car_body));
MOV(IND(19),R0);

//CDR
JUMP(L_create_my_cdr_clos);
L_my_cdr_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,2));
POP(FP);
RETURN;

L_create_my_cdr_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_cdr_body));
MOV(IND(20),R0);

//INTEGER?
JUMP(L_create_my_integer_clos);
L_my_integer_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_INTEGER);
JUMP_EQ(L_is_integer_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_integer);

L_is_integer_true:
MOV(R0,SOB_TRUE);

L_exit_my_integer:
POP(FP);
RETURN;

L_create_my_integer_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_integer_body));
MOV(IND(21),R0);

//CHAR?
JUMP(L_create_my_char_clos);
L_my_char_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_CHAR);
JUMP_EQ(L_is_char_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_char);

L_is_char_true:
MOV(R0,SOB_TRUE);

L_exit_my_char:
POP(FP);
RETURN;

L_create_my_char_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_char_body));
MOV(IND(22),R0);

//PAIR?
JUMP(L_create_my_pair_clos);
L_my_pair_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_PAIR);
JUMP_EQ(L_is_pair_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_pair);

L_is_pair_true:
MOV(R0,SOB_TRUE);

L_exit_my_pair:
POP(FP);
RETURN;

L_create_my_pair_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_pair_body));
MOV(IND(23),R0);

//PROCEDURE?
JUMP(L_create_my_procedure_clos);
L_my_procedure_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_CLOSURE);
JUMP_EQ(L_is_procedure_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_procedure);

L_is_procedure_true:
MOV(R0,SOB_TRUE);

L_exit_my_procedure:
POP(FP);
RETURN;

L_create_my_procedure_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_procedure_body));
MOV(IND(24),R0);

//BOOLEAN??
JUMP(L_create_my_boolean_clos);
L_my_boolean_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_BOOL);
JUMP_EQ(L_is_boolean_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_boolean);

L_is_boolean_true:
MOV(R0,SOB_TRUE);

L_exit_my_boolean:
POP(FP);
RETURN;

L_create_my_boolean_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_boolean_body));
MOV(IND(25),R0);

//RATIONAL?
JUMP(L_create_my_rational_clos);
L_my_rational_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_FRACTION);
JUMP_EQ(L_is_rational_true);
CMP(R0,T_INTEGER);
JUMP_EQ(L_is_rational_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_rational);

L_is_rational_true:
MOV(R0,SOB_TRUE);

L_exit_my_rational:
POP(FP);
RETURN;

L_create_my_rational_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_rational_body));
MOV(IND(26),R0);

//NULL?
JUMP(L_create_my_null_clos);
L_my_null_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_NIL);
JUMP_EQ(L_is_null_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_null);

L_is_null_true:
MOV(R0,SOB_TRUE);

L_exit_my_null:
POP(FP);
RETURN;

L_create_my_null_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_null_body));
MOV(IND(27),R0);

//STRING?
JUMP(L_create_my_string_clos);
L_my_string_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_STRING);
JUMP_EQ(L_is_string_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_string);

L_is_string_true:
MOV(R0,SOB_TRUE);

L_exit_my_string:
POP(FP);
RETURN;

L_create_my_string_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_string_body));
MOV(IND(28),R0);

//SYMBOL?
JUMP(L_create_my_symbol_clos);
L_my_symbol_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_SYMBOL);
JUMP_EQ(L_is_symbol_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_symbol);

L_is_symbol_true:
MOV(R0,SOB_TRUE);

L_exit_my_symbol:
POP(FP);
RETURN;

L_create_my_symbol_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_symbol_body));
MOV(IND(29),R0);

//NUMBER?
JUMP(L_create_my_number_clos);
L_my_number_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_FRACTION);
JUMP_EQ(L_is_number_true);
CMP(R0,T_INTEGER);
JUMP_EQ(L_is_number_true);
MOV(R0,SOB_FALSE);
JUMP(L_exit_my_number);

L_is_number_true:
MOV(R0,SOB_TRUE);

L_exit_my_number:
POP(FP);
RETURN;

L_create_my_number_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_number_body));
MOV(IND(38),R0);

//STRING->SYMBOL
JUMP(L_create_my_string_to_symbol_clos);
L_my_string_to_symbol_body:
PUSH(FP);
MOV(FP, SP);
MOV(R3,FPARG(2));

MOV(R1,57);
CMP(IND(R1),SOB_NIL);
JUMP_EQ(L_my_string_to_symbol_table_nil);

MOV(R1,IND(R1));
L_my_string_to_symbol_search_loop:
CMP(R1,SOB_NIL);
JUMP_EQ(L_my_string_to_symbol_not_found);
CMP(IND(R1),R3);
JUMP_EQ(L_my_string_to_symbol_found);
MOV(R4,R1);
MOV(R1,INDD(R1,1));
JUMP(L_my_string_to_symbol_search_loop);

L_my_string_to_symbol_found:
PUSH(R3);
CALL(MAKE_SOB_SYMBOL);
DROP(IMM(1));
JUMP(L_exit_my_string_to_symbol);
L_my_string_to_symbol_not_found:
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0), R3);
MOV(INDD(R0,1), SOB_NIL);
MOV(INDD(R4,1), R0);
PUSH(R3);
CALL(MAKE_SOB_SYMBOL);
DROP(IMM(1));
JUMP(L_exit_my_string_to_symbol);
L_my_string_to_symbol_table_nil:
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),R3);
MOV(INDD(R0,1),SOB_NIL);
MOV(IND(R1),R0);

PUSH(R3);
CALL(MAKE_SOB_SYMBOL);
DROP(IMM(1));
L_exit_my_string_to_symbol:
POP(FP);
RETURN;

L_create_my_string_to_symbol_clos:
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_string_to_symbol_body));
MOV(IND(30),R0);

//SYMBOL->STRING
JUMP(L_create_my_symbol_to_string_clos);
L_my_symbol_to_string_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,1));

POP(FP);
RETURN;

L_create_my_symbol_to_string_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_symbol_to_string_body));
MOV(IND(31),R0);

//BINARY-DIV
JUMP(L_create_my_div_clos);
L_my_div_body:
PUSH(FP);
MOV(FP, SP);
MOV(R1,FPARG(1));
CMP(R1,IMM(2));
JUMP_EQ(L_binary_div_2_arg);
PUSH(IMM(1));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
MOV(R5,R0);
MOV(R6,FPARG(2));

JUMP(L_cont_binary_div_1);

L_binary_div_2_arg:
MOV(R5,FPARG(2));
MOV(R6,FPARG(3));

L_cont_binary_div_1:
CMP(INDD(R5,0),T_INTEGER);
JUMP_EQ(L_arg1_integer);
MOV(R1,INDD(R5,1));
MOV(R2,INDD(R5,2));
JUMP(L_parse_arg_2);

L_arg1_integer:
MOV(R1,INDD(R5,1));
MOV(R2,IMM(1));
L_parse_arg_2:
CMP(INDD(R6,0),T_INTEGER);
JUMP_EQ(L_arg2_integer);
MOV(R3,INDD(R6,1));
MOV(R4,INDD(R6,2));
JUMP(L_binary_div_calc);

L_arg2_integer:
MOV(R3,INDD(R6,1));
MOV(R4,IMM(1));
L_binary_div_calc:
MUL(R1,R4);
MUL(R2,R3);

MOV(R10,R1);
MOV(R11,R2);

CMP(R10,0);
JUMP_GE(L_r10_is_positive);
MUL(R10,IMM(-1));
L_r10_is_positive:
CMP(R11,0);
JUMP_GE(L_r11_is_positive);
MUL(R11,IMM(-1));
L_r11_is_positive:

L_gcd_loop:
CMP(R11,IMM(0));
JUMP_EQ(L_gcd_exit);
MOV(R12,R11);
REM(R10,R11);
MOV(R11,R10);
MOV(R10,R12);
JUMP(L_gcd_loop);
L_gcd_exit:

MOV(R0,SOB_VOID);
DIV(R1,R10);
DIV(R2,R10);

CMP(R2,IMM(1));
JUMP_EQ(L_resault_is_integer_with_original_sign);CMP(R2,IMM(-1));
JUMP_EQ(L_resault_is_integer_with_oppisite_sign);PUSH(R2);
PUSH(R1);
CALL(MAKE_SOB_FRACTION);
DROP(IMM(2));
JUMP(L_exit_my_div);

L_resault_is_integer_with_original_sign:
PUSH(R1);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
JUMP(L_exit_my_div);

L_resault_is_integer_with_oppisite_sign:

MUL(R1,IMM(-1));
PUSH(R1);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
L_exit_my_div:

POP(FP);
RETURN;

L_create_my_div_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_div_body));
MOV(IND(32),R0);

//CONS
JUMP(L_create_my_cons_clos);
L_my_cons_body:
PUSH(FP);
MOV(FP, SP);
MOV(R1,FPARG(2));
MOV(R2,FPARG(3));
PUSH(R2);
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));

POP(FP);
RETURN;

L_create_my_cons_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_cons_body));
MOV(IND(33),R0);

//VECTOR-REF
JUMP(L_create_my_vector_ref_clos);
L_my_vector_ref_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
MOV(R1,INDD(R1,1));
MOV(R0,INDD(R0,R1+2));
POP(FP);
RETURN;

L_create_my_vector_ref_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_vector_ref_body));
MOV(IND(34),R0);

//GCD
JUMP(L_jump_over_gcd);
GCD:
PUSH(R1);
PUSH(R2);
PUSH(R3);
PUSH(FP);
MOV(FP, SP);
MOV(R1,FPARG(2));
MOV(R2,FPARG(3));
L_my_gcd_loop:
CMP(R2,IMM(0));
JUMP_EQ(L_exit_my_gcd);
MOV(R3,R1);
MOV(R1,R2);
REM(R3,R2);
MOV(R2,R3);
JUMP(L_my_gcd_loop);

L_exit_my_gcd:
CMP(R1,0);
JUMP_GE(L_my_gcd_ans_is_integer);
MUL(R1,IMM(-1));
L_my_gcd_ans_is_integer:
MOV(R0,R1);
POP(FP);
POP(R3);
POP(R2);
POP(R1);
RETURN;

L_jump_over_gcd:

//BINARY-ADD
JUMP(L_create_my_binary_add_clos);
L_my_binary_add_body:
PUSH(FP);
MOV(FP, SP);
CMP(FPARG(1),IMM(0));
JUMP_NE(L_my_binary_add_not_0_args)
PUSH(IMM(0));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
JUMP(L_my_binary_add_exit);
L_my_binary_add_not_0_args:
CMP(FPARG(1),IMM(1));
JUMP_NE(L_my_binary_add_2_args)
MOV(R0,FPARG(2));
JUMP(L_my_binary_add_exit);
L_my_binary_add_2_args:

MOV(R5,FPARG(2));
MOV(R6,FPARG(3));

CMP(INDD(R5,0),T_INTEGER);
JUMP_EQ(L__my_binary_add_arg1_integer);
MOV(R1,INDD(R5,1));
MOV(R2,INDD(R5,2));
JUMP(L_my_binary_add_parse_arg_2);

L__my_binary_add_arg1_integer:
MOV(R1,INDD(R5,1));
MOV(R2,IMM(1));
L_my_binary_add_parse_arg_2:
CMP(INDD(R6,0),T_INTEGER);
JUMP_EQ(L_my_binary_add_arg2_integer);
MOV(R3,INDD(R6,1));
MOV(R4,INDD(R6,2));
JUMP(L_my_binary_add_cont_calc);

L_my_binary_add_arg2_integer:
MOV(R3,INDD(R6,1));
MOV(R4,IMM(1));

L_my_binary_add_cont_calc:
MOV(R5,R2);
MUL(R1,R4);
MUL(R2,R4);
MUL(R3,R5);
MUL(R4,R5);
ADD(R1,R3);
PUSH(R1);
PUSH(R2);
CALL(GCD);
DROP(IMM(2));
DIV(R1,R0);
DIV(R2,R0);
CMP(R2,IMM(1));
JUMP_EQ(L_my_binary_add_ans_is_integer);
PUSH(R2);
PUSH(R1);
CALL(MAKE_SOB_FRACTION);
DROP(IMM(2));
JUMP(L_my_binary_add_exit);
L_my_binary_add_ans_is_integer:
PUSH(R1);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
L_my_binary_add_exit:

POP(FP);
RETURN;

L_create_my_binary_add_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_binary_add_body));
MOV(IND(35),R0);

//STRING_LENGTH
JUMP(L_create_my_string_length_clos);
L_my_string_length_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R0,INDD(R0,1));
PUSH(R0);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_string_length_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_string_length_body));
MOV(IND(36),R0);

//VECTOR-LENGTH
JUMP(L_create_my_vector_length_clos);
L_my_vector_length_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R0,INDD(R0,1));
PUSH(R0);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_vector_length_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_vector_length_body));
MOV(IND(37),R0);

//NUMERATOR
JUMP(L_create_my_numerator_clos);
L_my_numerator_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,1));
PUSH(R0);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_numerator_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_numerator_body));
MOV(IND(39),R0);

//DENOMINATOR
JUMP(L_create_my_denominator_clos);
L_my_denominator_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,2));
PUSH(R0);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_denominator_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_denominator_body));
MOV(IND(40),R0);

//NOT
JUMP(L_create_my_not_clos);
L_my_not_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
CMP(R0,SOB_FALSE);
JUMP_EQ(L_my_not_ret_true);
MOV(R0,SOB_FALSE);
JUMP(L_my_not_exit);
L_my_not_ret_true:
MOV(R0,SOB_TRUE);
L_my_not_exit:
POP(FP);
RETURN;

L_create_my_not_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_not_body));
MOV(IND(41),R0);

//ZERO?
JUMP(L_create_my_zero_clos);
L_my_zero_body:
PUSH(FP);
MOV(FP, SP);
MOV(R1,FPARG(2));
CMP(INDD(R1,0),T_INTEGER);
JUMP_NE(L_my_zero_return_false);
CMP(INDD(R1,1),IMM(0));
JUMP_NE(L_my_zero_return_false);
MOV(R0,SOB_TRUE);
JUMP(L_my_zero_exit);
L_my_zero_return_false:
MOV(R0,SOB_FALSE);
L_my_zero_exit:
POP(FP);
RETURN;

L_create_my_zero_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_zero_body));
MOV(IND(42),R0);

//CHAR->INTEGER
JUMP(L_create_my_char_to_integer_clos);
L_my_char_to_integer_body:
PUSH(FP);
MOV(FP, SP);
MOV(R1,FPARG(2));
MOV(R0,INDD(R1,1));
PUSH(R0);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_char_to_integer_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_char_to_integer_body));
MOV(IND(43),R0);

//INTEGER->CHAR
JUMP(L_create_my_integer_to_char_clos);
L_my_integer_to_char_body:
PUSH(FP);
MOV(FP, SP);
MOV(R1,FPARG(2));
MOV(R0,INDD(R1,1));
PUSH(R0);
CALL(MAKE_SOB_CHAR);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_integer_to_char_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_integer_to_char_body));
MOV(IND(44),R0);

//STRING-REF
JUMP(L_create_my_string_ref_clos);
L_my_string_ref_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
MOV(R1,INDD(R1,1));
MOV(R1,INDD(R0,R1 + 2));
PUSH(R1);
CALL(MAKE_SOB_CHAR);
DROP(IMM(1));
POP(FP);
RETURN;

L_create_my_string_ref_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_string_ref_body));
MOV(IND(45),R0);

//VECTOR?
JUMP(L_my_vector_clos);
L_my_vector_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R0,IND(R0));
CMP(R0,T_VECTOR);
JUMP_NE(L_my_vector_false);
MOV(R0,SOB_TRUE)
JUMP(L_my_vector_exit);
L_my_vector_false:
MOV(R0,SOB_FALSE)
L_my_vector_exit:
POP(FP);
RETURN;

L_my_vector_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_vector_body));
MOV(IND(46),R0);

//SET-CAR!
JUMP(L_create_my_set_car_clos);
L_my_set_car_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
MOV(INDD(R0,1),R1);
MOV(R0,SOB_VOID);
POP(FP);
RETURN;

L_create_my_set_car_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_set_car_body));
MOV(IND(47),R0);

//SET-CDR!
JUMP(L_create_my_set_cdr_clos);
L_my_set_cdr_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
MOV(INDD(R0,2),R1);
MOV(R0,SOB_VOID);
POP(FP);
RETURN;

L_create_my_set_cdr_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_set_cdr_body));
MOV(IND(48),R0);

//STRING-SET!
JUMP(L_create_my_string_set_clos);
L_my_set_string_set_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
MOV(R1,INDD(R1,1));
MOV(R2,FPARG(4));
MOV(R2,INDD(R2,1));
MOV(INDD(R0,2+R1),R2);
MOV(R0,SOB_VOID);
POP(FP);
RETURN;

L_create_my_string_set_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_set_string_set_body));
MOV(IND(49),R0);

//VECTOR-SET!
JUMP(L_create_my_vector_set_clos);
L_my_vector_set_body:
PUSH(FP);
MOV(FP, SP);

MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
MOV(R1,INDD(R1,1));
MOV(R2,FPARG(4));
MOV(INDD(R0,2+R1),R2);
MOV(R0,SOB_VOID);
POP(FP);
RETURN;

L_create_my_vector_set_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_vector_set_body));
MOV(IND(50),R0);

//BINARY=
JUMP(L_create_my_binary_number_equal_set_clos);
L_my_binary_number_equal_body:
PUSH(FP);
MOV(FP, SP);

CMP(FPARG(1),2);
JUMP_EQ(L_my_binary_number_equal_2_args);
MOV(R0,FPARG(2));
CMP(IND(R0),T_INTEGER);
JUMP_NE(L_my_binary_number_equal_false);
MOV(R0,SOB_TRUE);
JUMP(L_exit_my_binary_number_equal);
L_my_binary_number_equal_2_args:
MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
CMP(IND(R0),T_INTEGER);
JUMP_NE(L_my_binary_number_equal_false);
CMP(IND(R1),T_INTEGER);
JUMP_NE(L_my_binary_number_equal_false);
CMP(INDD(R0,1),INDD(R1,1));
JUMP_NE(L_my_binary_number_equal_false);
MOV(R0,SOB_TRUE);
JUMP(L_exit_my_binary_number_equal);
L_my_binary_number_equal_false:
MOV(R0,SOB_FALSE);
L_exit_my_binary_number_equal:
POP(FP);
RETURN;

L_create_my_binary_number_equal_set_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_binary_number_equal_body));
MOV(IND(51),R0);

//BINARY<
JUMP(L_create_my_binary_lower_then_clos);
L_my_binary_lower_then_body:
PUSH(FP);
MOV(FP, SP);

CMP(FPARG(1),2);
JUMP_EQ(L_my_binary_lower_then_2_args);
MOV(R0,FPARG(2));
CMP(IND(R0),T_INTEGER);
JUMP_NE(L_my_binary_lower_then_false);
MOV(R0,SOB_TRUE);
JUMP(L_exit_my_lower_then_equal);
L_my_binary_lower_then_2_args:
MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
CMP(IND(R0),T_INTEGER);
JUMP_NE(L_my_binary_lower_then_false);
CMP(IND(R1),T_INTEGER);
JUMP_NE(L_my_binary_lower_then_false);
CMP(INDD(R0,1),INDD(R1,1));
JUMP_GT(L_my_binary_lower_then_false);
CMP(INDD(R0,1),INDD(R1,1));
JUMP_EQ(L_my_binary_lower_then_false);
MOV(R0,SOB_TRUE);
JUMP(L_exit_my_lower_then_equal);
L_my_binary_lower_then_false:
MOV(R0,SOB_FALSE);
L_exit_my_lower_then_equal:
POP(FP);
RETURN;

L_create_my_binary_lower_then_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_binary_lower_then_body));
MOV(IND(52),R0);

//BINARY<
JUMP(L_create_my_binary_greater_then_clos);
L_my_binary_greater_then_body:
PUSH(FP);
MOV(FP, SP);

CMP(FPARG(1),2);
JUMP_EQ(L_my_binary_greater_then_2_args);
MOV(R0,FPARG(2));
CMP(IND(R0),T_INTEGER);
JUMP_NE(L_my_binary_greater_then_false);
MOV(R0,SOB_TRUE);
JUMP(L_exit_my_greater_then_equal);
L_my_binary_greater_then_2_args:
MOV(R0,FPARG(2));
MOV(R1,FPARG(3));
CMP(IND(R0),T_INTEGER);
JUMP_NE(L_my_binary_greater_then_false);
CMP(IND(R1),T_INTEGER);
JUMP_NE(L_my_binary_greater_then_false);
CMP(INDD(R0,1),INDD(R1,1));
JUMP_LT(L_my_binary_greater_then_false);
CMP(INDD(R0,1),INDD(R1,1));
JUMP_EQ(L_my_binary_greater_then_false);
MOV(R0,SOB_TRUE);
JUMP(L_exit_my_greater_then_equal);
L_my_binary_greater_then_false:
MOV(R0,SOB_FALSE);
L_exit_my_greater_then_equal:
POP(FP);
RETURN;

L_create_my_binary_greater_then_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_binary_greater_then_body));
MOV(IND(53),R0);

//VECTOR
JUMP(L_create_my_vector_clos);
L_my_create_vector_body:
PUSH(FP);
MOV(FP, SP);

MOV(R1,FPARG(1));
;MOV(R4,FPARG(1));
;L_create_my_vector_loop:
CMP(R1,IMM(0));
JUMP_EQ(L_create_my_vector_exit_loop);
MOV(R2,FPARG(R4 - R1 + 2));
PUSH(R2);
ADD(R1,IMM(-1));
JUMP(L_create_my_vector_loop);
L_create_my_vector_exit_loop:
PUSH(FPARG(1));
CALL(MAKE_SOB_VECTOR);
DROP(FPARG(1) + 1);
POP(FP);
RETURN;

L_create_my_vector_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_create_vector_body));
MOV(IND(54),R0);

//MAKE-VECTOR
JUMP(L_create_my_make_vector_clos);
L_my_create_make_vector_body:
PUSH(FP);
MOV(FP, SP);

MOV(R1,FPARG(1));
MOV(R2,INDD(FPARG(2),1));
CMP(R1,IMM(2));
JUMP_EQ(L_my_make_vector_2_arg);
L_my_make_vector_1_arg:
PUSH(IMM(0));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
MOV(R3,R0);
JUMP(L_my_make_vector_cont);
L_my_make_vector_2_arg:
MOV(R3,FPARG(3));
L_my_make_vector_cont:
MOV(R4,R2);
L_my_make_vector_start_loop:
CMP(R2,IMM(0));
JUMP_EQ(L_my_make_vector_exit_loop);
PUSH(R3);
ADD(R2,IMM(-1));
JUMP(L_my_make_vector_start_loop);
L_my_make_vector_exit_loop:
PUSH(R4);
CALL(MAKE_SOB_VECTOR);
DROP(R4+1);
POP(FP);
RETURN;

L_create_my_make_vector_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_create_make_vector_body));
MOV(IND(55),R0);

//MAKE-STRING
JUMP(L_create_my_make_string_clos);
L_my_create_make_string_body:
PUSH(FP);
MOV(FP, SP);

MOV(R1,FPARG(1));
MOV(R2,INDD(FPARG(2),1));
CMP(R1,IMM(2));
JUMP_EQ(L_my_make_string_2_arg);
L_my_make_string_1_arg:
MOV(R3,0);
JUMP(L_my_make_string_cont);
L_my_make_string_2_arg:
MOV(R3,FPARG(3));
MOV(R3,INDD(R3,1));
L_my_make_string_cont:
MOV(R4,R2);
L_my_make_string_start_loop:
CMP(R2,IMM(0));
JUMP_EQ(L_my_make_string_exit_loop);
PUSH(R3);
ADD(R2,IMM(-1));
JUMP(L_my_make_string_start_loop);
L_my_make_string_exit_loop:
PUSH(R4);
CALL(MAKE_SOB_STRING);
DROP(R4+1);
POP(FP);
RETURN;

L_create_my_make_string_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_create_make_string_body));
MOV(IND(56),R0);

/*-------------runtime-support-------------*/

/*-------------fake frame--------------*/

PUSH(IMM(0));
PUSH(IMM(T_NIL));
PUSH(LABEL(END));
PUSH(FP);
MOV(FP,SP);

/*-------------fake frame--------------*/

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////////////
///code gen: lambda-opt    - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88686:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88685);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88686);
L_copy_old_env_end_88685:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88684:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88683 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88684);
L_copy_args_end_88683:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_opt_body_88687));

JUMP(L_exit_lambda_opt_88682);

//--------------------check here------------------------

L_lambda_opt_body_88687:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_opt_arg_start_88681:
CMP(R2,1 +1);
JUMP_EQ(L_make_opt_arg_end_88680);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_opt_arg_start_88681);
L_make_opt_arg_end_88680:

MOV(FPARG(1 + 2), R1);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88689);


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,FPARG(2));

PUSH(R0)
MOV(R0,IMM(9));

PUSH(R0)

PUSH(IMM(2))
MOV(R0,IND(32));
PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,2 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88708:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88709);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88708);
L_tc_applic_overide_stack_end_88709:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
JUMP(L_if3_exit_88688);
L_if3_dif_88689:


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,IMM(3));

PUSH(R0)

PUSH(IMM(1))


/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88696:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88695);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88696);
L_copy_old_env_end_88695:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88694:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88693 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88694);
L_copy_args_end_88693:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88697));

JUMP(L_exit_lambda_simple_88692);

L_lambda_simple_body_88697:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: seq   - start///
/////////////////////////////
//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(2));
MOV(FPARG(2 +0),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88704:
CMP(R4,IMM(1));
JUMP_GE(L_copy_old_env_end_88703);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88704);
L_copy_old_env_end_88703:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88702:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88701 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88702);
L_copy_args_end_88701:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88705));

JUMP(L_exit_lambda_simple_88700);

L_lambda_simple_body_88705:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88707);
MOV(R0,IMM(9));
JUMP(L_if3_exit_88706);
L_if3_dif_88707:


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(1));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(32));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
L_if3_exit_88706:
POP(FP);
RETURN;

L_exit_lambda_simple_88700:

//box-set-pvar
MOV(R1,FPARG(2 +0));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,1));

PUSH(R0)
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(33));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(1))
//box-get-pvar
MOV(R0, FPARG(2+0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88698:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88699);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88698);
L_tc_applic_overide_stack_end_88699:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

L_exit_lambda_simple_88692:

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88690:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88691);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88690);
L_tc_applic_overide_stack_end_88691:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
L_if3_exit_88688:
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_opt_88682:

MOV(IND(13),R0);
MOV(R0,SOB_VOID);

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88714:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88713);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88714);
L_copy_old_env_end_88713:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88712:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88711 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88712);
L_copy_args_end_88711:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88715));

JUMP(L_exit_lambda_simple_88710);

L_lambda_simple_body_88715:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88717);
MOV(R0,FPARG(3));
JUMP(L_if3_exit_88716);
L_if3_dif_88717:


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(14));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(1));
MOV(R0,FPARG(2));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2))
MOV(R0,IND(33));
PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,2 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88718:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88719);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88718);
L_tc_applic_overide_stack_end_88719:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
L_if3_exit_88716:
POP(FP);
RETURN;

L_exit_lambda_simple_88710:

MOV(IND(14),R0);
MOV(R0,SOB_VOID);

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,IMM(3));

PUSH(R0)
MOV(R0,IMM(3));

PUSH(R0)

PUSH(IMM(2));


/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88624:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88623);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88624);
L_copy_old_env_end_88623:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88622:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88621 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88622);
L_copy_args_end_88621:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88625));

JUMP(L_exit_lambda_simple_88620);

L_lambda_simple_body_88625:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: seq   - start///
/////////////////////////////
//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(2));
MOV(FPARG(2 +0),R0);
MOV(R0,SOB_VOID);

//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(3));
MOV(FPARG(2 +1),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88650:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88649);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88650);
L_copy_old_env_end_88649:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88648:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88647 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88648);
L_copy_args_end_88647:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88651));

JUMP(L_exit_lambda_simple_88646);

L_lambda_simple_body_88651:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88653);
MOV(R0,FPARG(3));
JUMP(L_if3_exit_88652);
L_if3_dif_88653:


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(33));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
L_if3_exit_88652:
POP(FP);
RETURN;

L_exit_lambda_simple_88646:

//box-set-pvar
MOV(R1,FPARG(2 +0));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88642:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88641);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88642);
L_copy_old_env_end_88641:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88640:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88639 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88640);
L_copy_args_end_88639:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88643));

JUMP(L_exit_lambda_simple_88638);

L_lambda_simple_body_88643:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88645);
MOV(R0,FPARG(2));
JUMP(L_if3_exit_88644);
L_if3_dif_88645:


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,1));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(2));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
L_if3_exit_88644:
POP(FP);
RETURN;

L_exit_lambda_simple_88638:

//box-set-pvar
MOV(R1,FPARG(2 +1));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-opt    - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88632:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88631);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88632);
L_copy_old_env_end_88631:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88630:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88629 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88630);
L_copy_args_end_88629:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_var_body_88633));

JUMP(L_exit_lambda_var_88628);

//--------------------check here------------------------

L_lambda_var_body_88633:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_var_arg_start_88627:
CMP(R2,0 +1);
JUMP_EQ(L_make_var_arg_end_88626);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_var_arg_start_88627);
L_make_var_arg_end_88626:

MOV(FPARG(0 + 2), R1);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88635);
MOV(R0,IMM(2));
JUMP(L_if3_exit_88634);
L_if3_dif_88635:


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2))
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,1));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,2 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88636:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88637);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88636);
L_tc_applic_overide_stack_end_88637:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
L_if3_exit_88634:
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_var_88628:

POP(FP);
RETURN;

L_exit_lambda_simple_88620:

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
MOV(IND(15),R0);
MOV(R0,SOB_VOID);

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////////////
///code gen: lambda-opt    - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88660:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88659);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88660);
L_copy_old_env_end_88659:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88658:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88657 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88658);
L_copy_args_end_88657:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_var_body_88661));

JUMP(L_exit_lambda_var_88656);

//--------------------check here------------------------

L_lambda_var_body_88661:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_var_arg_start_88655:
CMP(R2,0 +1);
JUMP_EQ(L_make_var_arg_end_88654);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_var_arg_start_88655);
L_make_var_arg_end_88654:

MOV(FPARG(0 + 2), R1);


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,IMM(3));

PUSH(R0)

PUSH(IMM(1))


/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88668:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88667);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88668);
L_copy_old_env_end_88667:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88666:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88665 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88666);
L_copy_args_end_88665:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88669));

JUMP(L_exit_lambda_simple_88664);

L_lambda_simple_body_88669:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: seq   - start///
/////////////////////////////
//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(2));
MOV(FPARG(2 +0),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88676:
CMP(R4,IMM(1));
JUMP_GE(L_copy_old_env_end_88675);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88676);
L_copy_old_env_end_88675:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88674:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88673 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88674);
L_copy_args_end_88673:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88677));

JUMP(L_exit_lambda_simple_88672);

L_lambda_simple_body_88677:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88679);
MOV(R0,IMM(7));
JUMP(L_if3_exit_88678);
L_if3_dif_88679:


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(1));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(35));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
L_if3_exit_88678:
POP(FP);
RETURN;

L_exit_lambda_simple_88672:

//box-set-pvar
MOV(R1,FPARG(2 +0));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(1))
//box-get-pvar
MOV(R0, FPARG(2+0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88670:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88671);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88670);
L_tc_applic_overide_stack_end_88671:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

L_exit_lambda_simple_88664:

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88662:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88663);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88662);
L_tc_applic_overide_stack_end_88663:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_var_88656:

MOV(IND(16),R0);
MOV(R0,SOB_VOID);

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////////////
///code gen: lambda-opt    - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88570:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88569);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88570);
L_copy_old_env_end_88569:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88568:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88567 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88568);
L_copy_args_end_88567:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_var_body_88571));

JUMP(L_exit_lambda_var_88566);

//--------------------check here------------------------

L_lambda_var_body_88571:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_var_arg_start_88565:
CMP(R2,0 +1);
JUMP_EQ(L_make_var_arg_end_88564);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_var_arg_start_88565);
L_make_var_arg_end_88564:

MOV(FPARG(0 + 2), R1);


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,IMM(3));

PUSH(R0)

PUSH(IMM(1))


/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88578:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88577);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88578);
L_copy_old_env_end_88577:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88576:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88575 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88576);
L_copy_args_end_88575:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88579));

JUMP(L_exit_lambda_simple_88574);

L_lambda_simple_body_88579:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: seq   - start///
/////////////////////////////
//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(2));
MOV(FPARG(2 +0),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88586:
CMP(R4,IMM(1));
JUMP_GE(L_copy_old_env_end_88585);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88586);
L_copy_old_env_end_88585:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88584:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88583 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88584);
L_copy_args_end_88583:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88587));

JUMP(L_exit_lambda_simple_88582);

L_lambda_simple_body_88587:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88589);
MOV(R0,IMM(5));
JUMP(L_if3_exit_88588);
L_if3_dif_88589:


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(51));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88591);


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(3));

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
JUMP(L_if3_exit_88590);
L_if3_dif_88591:
MOV(R0,IMM(3));
L_if3_exit_88590:
L_if3_exit_88588:
POP(FP);
RETURN;

L_exit_lambda_simple_88582:

//box-set-pvar
MOV(R1,FPARG(2 +0));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(2))
//box-get-pvar
MOV(R0, FPARG(2+0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,2 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88580:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88581);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88580);
L_tc_applic_overide_stack_end_88581:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

L_exit_lambda_simple_88574:

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88572:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88573);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88572);
L_tc_applic_overide_stack_end_88573:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_var_88566:

MOV(IND(17),R0);
MOV(R0,SOB_VOID);

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////////////
///code gen: lambda-opt    - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88598:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88597);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88598);
L_copy_old_env_end_88597:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88596:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88595 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88596);
L_copy_args_end_88595:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_var_body_88599));

JUMP(L_exit_lambda_var_88594);

//--------------------check here------------------------

L_lambda_var_body_88599:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_var_arg_start_88593:
CMP(R2,0 +1);
JUMP_EQ(L_make_var_arg_end_88592);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_var_arg_start_88593);
L_make_var_arg_end_88592:

MOV(FPARG(0 + 2), R1);


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,IMM(3));

PUSH(R0)

PUSH(IMM(1))


/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88606:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88605);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88606);
L_copy_old_env_end_88605:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88604:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88603 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88604);
L_copy_args_end_88603:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88607));

JUMP(L_exit_lambda_simple_88602);

L_lambda_simple_body_88607:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: seq   - start///
/////////////////////////////
//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(2));
MOV(FPARG(2 +0),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88614:
CMP(R4,IMM(1));
JUMP_GE(L_copy_old_env_end_88613);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88614);
L_copy_old_env_end_88613:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88612:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88611 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88612);
L_copy_args_end_88611:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88615));

JUMP(L_exit_lambda_simple_88610);

L_lambda_simple_body_88615:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88617);
MOV(R0,IMM(5));
JUMP(L_if3_exit_88616);
L_if3_dif_88617:


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(52));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88619);


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
JUMP(L_if3_exit_88618);
L_if3_dif_88619:
MOV(R0,IMM(3));
L_if3_exit_88618:
L_if3_exit_88616:
POP(FP);
RETURN;

L_exit_lambda_simple_88610:

//box-set-pvar
MOV(R1,FPARG(2 +0));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2))
//box-get-pvar
MOV(R0, FPARG(2+0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,2 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88608:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88609);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88608);
L_tc_applic_overide_stack_end_88609:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

L_exit_lambda_simple_88602:

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88600:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88601);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88600);
L_tc_applic_overide_stack_end_88601:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_var_88594:

MOV(IND(18),R0);
MOV(R0,SOB_VOID);

////////////////////////////////
///code gen: define   - start///
////////////////////////////////



/////////////////////////////////////
///code gen: lambda-opt    - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88542:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_88541);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88542);
L_copy_old_env_end_88541:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88540:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88539 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88540);
L_copy_args_end_88539:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_var_body_88543));

JUMP(L_exit_lambda_var_88538);

//--------------------check here------------------------

L_lambda_var_body_88543:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_var_arg_start_88537:
CMP(R2,0 +1);
JUMP_EQ(L_make_var_arg_end_88536);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_var_arg_start_88537);
L_make_var_arg_end_88536:

MOV(FPARG(0 + 2), R1);


////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////

MOV(R0,IMM(3));

PUSH(R0)

PUSH(IMM(1))


/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88550:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_88549);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88550);
L_copy_old_env_end_88549:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88548:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88547 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88548);
L_copy_args_end_88547:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88551));

JUMP(L_exit_lambda_simple_88546);

L_lambda_simple_body_88551:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: seq   - start///
/////////////////////////////
//set-pvar
//box
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), FPARG(2));
MOV(FPARG(2 +0),R0);
MOV(R0,SOB_VOID);



/////////////////////////////////////
///code gen: lambda-simple - start///
/////////////////////////////////////
MOV(R1,FPARG(0));

PUSH(IMM(2));
CALL(MALLOC);
DROP(1);
MOV(R2, R0);

MOV(R4,IMM(0));
MOV(R5,IMM(1));

L_copy_old_env_start_88558:
CMP(R4,IMM(1));
JUMP_GE(L_copy_old_env_end_88557);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_88558);
L_copy_old_env_end_88557:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_88556:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_88555 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_88556);
L_copy_args_end_88555:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_88559));

JUMP(L_exit_lambda_simple_88554);

L_lambda_simple_body_88559:
PUSH(FP);
MOV(FP,SP);


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88561);
MOV(R0,IMM(5));
JUMP(L_if3_exit_88560);
L_if3_dif_88561:


/////////////////////////////
///code gen: if    - start///
/////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)
MOV(R0,FPARG(3));

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(53));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_88563);


/////////////////////////////
///code gen: applic- start///
/////////////////////////////


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(2));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
//box-get-bvar
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0, INDD(R0,0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
JUMP(L_if3_exit_88562);
L_if3_dif_88563:
MOV(R0,IMM(3));
L_if3_exit_88562:
L_if3_exit_88560:
POP(FP);
RETURN;

L_exit_lambda_simple_88554:

//box-set-pvar
MOV(R1,FPARG(2 +0));
MOV(IND(R1),R0);
MOV(R0,SOB_VOID);



////////////////////////////////
///code gen: tc-applic- start///
////////////////////////////////



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(19));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)


/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0)

PUSH(IMM(1));
MOV(R0,IND(20));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2))
//box-get-pvar
MOV(R0, FPARG(2+0));
MOV(R0,IND(R0));

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,2 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88552:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88553);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88552);
L_tc_applic_overide_stack_end_88553:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

L_exit_lambda_simple_88546:

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_88544:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_88545);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_88544);
L_tc_applic_overide_stack_end_88545:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_var_88538:

MOV(IND(18),R0);
MOV(R0,SOB_VOID);

MOV(R0,IMM(3));

CMP(R0,SOB_VOID);
JUMP_EQ(L_output_is_void);

PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));

CALL(NEWLINE);
L_output_is_void:

END:

STOP_MACHINE;

return 0;
}