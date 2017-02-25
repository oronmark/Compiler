
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

PUSH(IMM(98));
PUSH(IMM(99));
PUSH(IMM(2));
CALL(MAKE_SOB_STRING);
DROP(3);


PUSH(IMM(97));
PUSH(IMM(1));
CALL(MAKE_SOB_STRING);
DROP(2);


PUSH(IMM(7));
CALL(MAKE_SOB_SYMBOL);
DROP(IMM(1));

PUSH(IMM(2));
PUSH(IMM(14));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));


PUSH(IMM(11));
CALL(MAKE_SOB_SYMBOL);
DROP(IMM(1));

PUSH(IMM(16));
PUSH(IMM(19));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));


PUSH(IMM(2));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));


PUSH(IMM(1));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));

/*-------------const table-------------*/

/*-------------fvar table-------------*/

MOV(IND(0),30);

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

//fvar: list
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),T_UNDEF);
DROP(1);








































/*-------------fvar table-------------*/

/*-------------symbol table-------------*/

MOV(R1,69);
PUSH(IMM(1));
CALL(MALLOC);
MOV(IND(R0),SOB_NIL);
DROP(1);

MOV(IND(69),69  + 1  );
PUSH(IMM(2));
CALL(MALLOC);
MOV(INDD(R0,0),11);
MOV(INDD(R0,1),R0 + 2);
DROP(IMM(1));

PUSH(IMM(2));
CALL(MALLOC);
MOV(INDD(R0,0),7);
MOV(INDD(R0,1),SOB_NIL);
DROP(IMM(1));

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
MOV(IND(30),R0);

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
MOV(IND(31),R0);

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
MOV(IND(32),R0);

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
MOV(IND(33),R0);

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
MOV(IND(34),R0);

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
MOV(IND(35),R0);

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
MOV(IND(36),R0);

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
MOV(IND(37),R0);

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
MOV(IND(38),R0);

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
MOV(IND(39),R0);

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
MOV(IND(40),R0);

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
MOV(IND(49),R0);

//STRING->SYMBOL
JUMP(L_create_my_string_to_symbol_clos);
L_my_string_to_symbol_body:
PUSH(FP);
MOV(FP, SP);
MOV(R3,FPARG(2));

MOV(R1,69);
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
MOV(IND(41),R0);

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
MOV(IND(42),R0);

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
MOV(IND(43),R0);

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
MOV(IND(44),R0);

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
MOV(IND(45),R0);

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
MOV(IND(46),R0);

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
MOV(IND(47),R0);

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
MOV(IND(48),R0);

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
MOV(IND(50),R0);

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
MOV(IND(51),R0);

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
MOV(IND(52),R0);

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
MOV(IND(53),R0);

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
MOV(IND(54),R0);

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
MOV(IND(55),R0);

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
MOV(IND(56),R0);

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
MOV(IND(57),R0);

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
MOV(IND(58),R0);

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
MOV(IND(59),R0);

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
MOV(IND(60),R0);

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
MOV(IND(61),R0);

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
MOV(IND(62),R0);

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
MOV(IND(63),R0);

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
MOV(IND(64),R0);

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
MOV(IND(65),R0);

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
MOV(IND(66),R0);

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
MOV(IND(67),R0);

//LIST
JUMP(L_create_my_list_clos);
L_my_list_body:
PUSH(FP);
MOV(FP, SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1));
L_my_list_start_loop:
CMP(R2,IMM(0));
JUMP_EQ(L_my_list_end_loop);
MOV(R3,FPARG(R2+1));
PUSH(R1);
PUSH(R3);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(R1,R0);
ADD(R2,IMM(-1));
JUMP(L_my_list_start_loop);
L_my_list_end_loop:
MOV(R0,R1);
POP(FP);
RETURN;

L_create_my_list_clos:
PUSH(3);
CALL(MALLOC);
DROP(1);
MOV(INDD(R0,0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(L_my_list_body));
MOV(IND(68),R0);

/*-------------runtime-support-------------*/

/*-------------fake frame--------------*/

PUSH(IMM(0));
PUSH(IMM(T_NIL));
PUSH(LABEL(END));
PUSH(FP);
MOV(FP,SP);

/*-------------fake frame--------------*/



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,IMM(21));

PUSH(R0)
MOV(R0,IMM(24));

PUSH(R0)
MOV(R0,IMM(26));

PUSH(R0)

PUSH(IMM(3));
MOV(R0,IND(68));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

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