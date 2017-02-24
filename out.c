
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

PUSH(IMM(34));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));

PUSH(IMM(29));
PUSH(IMM(-5));
CALL(MAKE_SOB_FRACTION);
DROP(IMM(2));


PUSH(IMM(114));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));

PUSH(IMM(11));
PUSH(IMM(-3));
CALL(MAKE_SOB_FRACTION);
DROP(IMM(2));

PUSH(IMM(15));
PUSH(IMM(2));
CALL(MAKE_SOB_FRACTION);
DROP(IMM(2));


PUSH(IMM(1));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));


PUSH(IMM(0));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));

/*-------------const table-------------*/

/*-------------fvar table-------------*/

MOV(IND(0),26);

//fvar: +
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



















/*-------------fvar table-------------*/

/*-------------symbol table-------------*/

MOV(R1,44);
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
MOV(IND(27),R0);

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
MOV(IND(28),R0);

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
MOV(IND(29),R0);

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
MOV(IND(30),R0);

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
MOV(IND(31),R0);

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
MOV(IND(32),R0);

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
MOV(IND(33),R0);

//RATIONAL?
JUMP(L_create_my_rational_clos);
L_my_rational_body:
PUSH(FP);
MOV(FP, SP);
MOV(R0,FPARG(2));
MOV(R0,INDD(R0,0));

CMP(R0,T_FRACTION);
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
MOV(IND(34),R0);

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
MOV(IND(35),R0);

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
MOV(IND(36),R0);

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
MOV(IND(37),R0);

//STRING->SYMBOL
JUMP(L_create_my_string_to_symbol_clos);
L_my_string_to_symbol_body:
PUSH(FP);
MOV(FP, SP);
MOV(R3,FPARG(2));

MOV(R1,44);
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
MOV(IND(38),R0);

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
MOV(IND(39),R0);

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
MOV(IND(40),R0);

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
MOV(IND(41),R0);

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
MOV(IND(42),R0);

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
MOV(IND(43),R0);

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

L_copy_old_env_start_7:
CMP(R4,IMM(-1));
JUMP_GE(L_copy_old_env_end_6);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_7);
L_copy_old_env_end_6:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_5:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_4 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_5);
L_copy_args_end_4:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_var_body_8));

JUMP(L_exit_lambda_var_3);

//--------------------check here------------------------

L_lambda_var_body_8:
PUSH(FP);
MOV(FP,SP);

MOV(R1,SOB_NIL);
MOV(R2,FPARG(1)+1);

L_make_var_arg_start_2:
CMP(R2,0 +1);
JUMP_EQ(L_make_var_arg_end_1);
PUSH(R1);
PUSH(FPARG(R2));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
SUB(R2,1);
MOV(R1,R0);
JUMP(L_make_var_arg_start_2);
L_make_var_arg_end_1:

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

L_copy_old_env_start_15:
CMP(R4,IMM(0));
JUMP_GE(L_copy_old_env_end_14);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_15);
L_copy_old_env_end_14:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_13:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_12 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_13);
L_copy_args_end_12:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_16));

JUMP(L_exit_lambda_simple_11);

L_lambda_simple_body_16:
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

L_copy_old_env_start_23:
CMP(R4,IMM(1));
JUMP_GE(L_copy_old_env_end_22);
MOV(INDD(R2,R5),INDD(R1,R4));
ADD(R4,IMM(1));
ADD(R5,IMM(1));
JUMP(L_copy_old_env_start_23);
L_copy_old_env_end_22:


PUSH(FPARG(1));
CALL(MALLOC);
DROP(1);
MOV(R3,R0);
MOV(R4,IMM(0));

L_copy_args_start_21:
CMP(R4,FPARG(1));
JUMP_EQ(L_copy_args_end_20 );
MOV(INDD(R3,R4),FPARG(2 + R4));
ADD(R4,IMM(1));
JUMP(L_copy_args_start_21);
L_copy_args_end_20:

MOV(IND(R2), R3);

PUSH(IMM(3));
CALL(MALLOC);
DROP(1);

MOV(INDD(R0,0), T_CLOSURE);
MOV(INDD(R0,1), R2);
MOV(INDD(R0,2),LABEL(L_lambda_simple_body_24));

JUMP(L_exit_lambda_simple_19);

L_lambda_simple_body_24:
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
MOV(R0,IND(35));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
CMP(R0,IMM(SOB_FALSE));
JUMP_EQ(L_if3_dif_26);
MOV(R0,IMM(22));
JUMP(L_if3_exit_25);
L_if3_dif_26:


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
MOV(R0,IND(28));
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
MOV(R0,IND(27));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0)

PUSH(IMM(2));
MOV(R0,IND(43));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);
L_if3_exit_25:
POP(FP);
RETURN;

L_exit_lambda_simple_19:

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
L_tc_applic_overide_stack_start_17:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_18);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_17);
L_tc_applic_overide_stack_end_18:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

L_exit_lambda_simple_11:

PUSH(INDD(R0,1));
PUSH(FPARG(-1));
MOV(R10,FPARG(-2));

MOV(R1,1 + 3);
MOV(R2, FPARG(1) + 1);
MOV(R3,-3);

MOV(R4,FPARG(1) + 4);
L_tc_applic_overide_stack_start_9:
CMP(R1,IMM(0));
JUMP_EQ(L_tc_applic_overide_stack_end_10);
MOV(FPARG(R2),FPARG(R3));
SUB(R2,IMM(1));
SUB(R3,IMM(1));
SUB(R1,IMM(1));
JUMP(L_tc_applic_overide_stack_start_9);
L_tc_applic_overide_stack_end_10:

DROP(R4);
MOV(FP,R10);
JUMPA(INDD(R0,2));
POP(FP);
RETURN;

//--------------------check here------------------------

L_exit_lambda_var_3:

MOV(IND(26),R0);
MOV(R0,SOB_VOID);



/////////////////////////////
///code gen: applic- start///
/////////////////////////////
MOV(R0,IMM(7));

PUSH(R0)
MOV(R0,IMM(9));

PUSH(R0)
MOV(R0,IMM(12));

PUSH(R0)
MOV(R0,IMM(14));

PUSH(R0)
MOV(R0,IMM(17));

PUSH(R0)
MOV(R0,IMM(20));

PUSH(R0)

PUSH(IMM(6));
MOV(R0,IND(26));
PUSH(INDD(R0,1));
CALLA(INDD(R0,2));
DROP(IMM(1));
POP(R1);
DROP(R1);

PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));

CALL(NEWLINE);
END:
STOP_MACHINE;

return 0;
}