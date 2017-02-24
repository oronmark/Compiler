	
#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"

void printStack(long* arr){
  printf("\n**************** STACK **********************\n");
  int i;
  for (i = 0; i < 130; i++){
     if (i % 10 == 0){
      printf("\n");
    }
    
    printf("[%d]: %ld\t", i, arr[i]);
  }
  printf("\n");
}

int main()
{
	START_MACHINE;
	
	JUMP(CONTINUE);

	#include "scheme.lib"
	#include "char.lib"
	#include "io.lib"
	#include "math.lib"
	#include "string.lib"
	#include "system.lib"
	
	#include "debug_macros.h"
	
	#define SOB_VOID 1
	#define SOB_NIL 2
	#define SOB_FALSE 3
	#define SOB_TRUE 5

	
CONTINUE:
	
	/* Initialize stack with default values */

	
	/* Void */
	MOV(ADDR(1), IMM(T_VOID));
	
	/* Nil (Empty List) */
	MOV(ADDR(2), IMM(T_NIL));
	
	/* False (Boolean) */
	MOV(ADDR(3), IMM(T_BOOL));
	MOV(ADDR(4), IMM(0));
	
	/* True (Boolean) */
	MOV(ADDR(5), IMM(T_BOOL));
	MOV(ADDR(6), IMM(1));
	/*Place of run-time symbol list*/
 	MOV(ADDR(10),IMM(2));
	/* Increase address */
	ADD(ADDR(0), IMM(100))
;
	MOV(R15,107);

	/* create constants table*/

	PUSH(IMM(0));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
PUSH(IMM(800000));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
PUSH(IMM(1));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
/* end of constants table creation */
/* Add values to symbols */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0), IMM(T_SYMBOL));
MOV(INDD(R0,1), IMM(T_UNDEF));
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(IS_NULL));
MOV(R1,109);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(CAR));
MOV(R1,111);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(CONS));
MOV(R1,113);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(APPLY));
MOV(R1,115);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(CDR));
MOV(R1,117);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(BIN_PLUS));
MOV(R1,123);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(BIN_MINUS));
MOV(R1,127);
MOV(INDD(R1,1),R0);
PUSH(IMM(3));
CALL(MALLOC);
DROP(1);
MOV(IND(R0),IMM(T_CLOSURE));
MOV(INDD(R0,1),IMM(0));
MOV(INDD(R0,2),LABEL(IS_ZERO));
MOV(R1,129);
MOV(INDD(R1,1),R0);
/* end insert values to symbols */

	/* Fake Env */

	PUSH(IMM(0));
	PUSH(IMM(SOB_NIL));
	PUSH(LABEL(END));
	PUSH(FP);
	MOV(FP,SP);

	/* code generation */
	/*Genrate code foe the definition and save the pointer to the result in R0*/
/* START_applic16697*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16697 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16796:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16795);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16796);
end_extend_env_16795:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16794:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16793);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16794);
end_add_param_16793:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16765));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16765);
lambda_body_16765:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16766*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16766 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16792:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16791);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16792);
end_extend_env_16791:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16790:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16789);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16790);
end_add_param_16789:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16780));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16780);
lambda_body_16780:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16781*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16781 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16788:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_16787);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16788);
end_extend_env_16787:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16786:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16785);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16786);
end_add_param_16785:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16782));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16782);
lambda_body_16782:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16783*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16783 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16783 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/* START_applic16784*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16784 - operand #1 value */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16782:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16780:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16779:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16778);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16779);
end_extend_env_16778:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16777:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16776);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16777);
end_add_param_16776:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16767));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16767);
lambda_body_16767:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16768*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16768 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16775:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_16774);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16775);
end_extend_env_16774:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16773:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16772);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16773);
end_add_param_16772:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16769));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16769);
lambda_body_16769:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16770*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16770 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16770 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/* START_applic16771*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16771 - operand #1 value */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16769:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16767:
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16765:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16764:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16763);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16764);
end_extend_env_16763:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16762:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16761);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16762);
end_add_param_16761:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16698));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16698);
lambda_body_16698:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16699*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16699 - operand #1 value */
/* START_applic16741*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16741 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16760:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16759);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16760);
end_extend_env_16759:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16758:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16757);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16758);
end_add_param_16757:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16742));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16742);
lambda_body_16742:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16756:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_16755);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16756);
end_extend_env_16755:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16754:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16753);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16754);
end_add_param_16753:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16743));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16743);
lambda_body_16743:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16749*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16749 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,109);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

CMP (IND(R0), T_BOOL);
JUMP_NE(dit16750);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif16752);
dit16750:
MOV(R0, IMM(SOB_NIL));

JUMP(exit16751);
dif16752:
/* START_applic16744*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16744 - operand #2 value */
/* START_applic16747*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16747 - operand #2 value */
/* START_applic16748*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16748 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,117);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16747 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16744 - operand #1 value */
/* START_applic16745*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16745 - operand #1 value */
/* START_applic16746*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16746 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,111);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(2));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,113);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);


exit16751:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16743:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16742:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(2));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16740:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16739);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16740);
end_extend_env_16739:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16738:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16737);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16738);
end_add_param_16737:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16700));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16700);
lambda_body_16700:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16701*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16701 - operand #1 value */
/* START_applic16716*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16716 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16736:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_16735);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16736);
end_extend_env_16735:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16734:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16733);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16734);
end_add_param_16733:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16717));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16717);
lambda_body_16717:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16732:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_16731);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16732);
end_extend_env_16731:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16730:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16729);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16730);
end_add_param_16729:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16718));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16718);
lambda_body_16718:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16724*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16724 - operand #1 value */
/* START_applic16725*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16725 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,111);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,109);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

CMP (IND(R0), T_BOOL);
JUMP_NE(dit16726);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif16728);
dit16726:
MOV(R0, IMM(SOB_NIL));

JUMP(exit16727);
dif16728:
/* START_applic16719*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16719 - operand #2 value */
/* START_applic16722*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16722 - operand #2 value */
/* START_applic16723*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16723 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16723 - operand #1 value */
/*Find the fvar index in the const table*/
MOV(R0,117);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,1));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16722 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16719 - operand #1 value */
/* START_applic16720*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16720 - operand #2 value */
/* START_applic16721*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16721 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16721 - operand #1 value */
/*Find the fvar index in the const table*/
MOV(R0,111);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,1));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16720 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,115);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,113);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);


exit16727:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16718:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16717:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16715:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_16714);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16715);
end_extend_env_16714:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16713:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16712);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16713);
end_add_param_16712:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16702));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16702);
lambda_body_16702:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16711:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_16710);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16711);
end_extend_env_16710:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16709:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16708);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16709);
end_add_param_16708:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_opt_body_lbl_16706));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_opt_body_lbl_16706);
lambda_opt_body_lbl_16706:
/*Save current FP,R5 value and move fp to the start of the stack */
PUSH(FP);
MOV(FP,SP);
PUSH(R5);
/* Get the parameters number*/
MOV(R5,FPARG(1));
/*Check if there are parameters you dont know about them */
CMP(R5,IMM(1));
JUMP_EQ(generate_body_16705);
/*Create list of pairs and save the parameters value on the last known parameter*/
/*Create the last pair, magic+nill*/
ADD(R5,IMM(1));
PUSH(IMM(SOB_NIL));
PUSH(FPARG(R5));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*Return to r5 the paramters number*/
SUB(R5,IMM(1));
/*foreach parameter create pair with his value and pointer to the next parameter backward*/
add_param_to_list_16704:
/*check if we finish to over all the parameters we dont know about them*/
CMP(R5,IMM(3));
JUMP_LT(end_add_param_to_list_16703);
/*Else, add the current parameter to the list*/
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*push the current parameter value*/
PUSH(FPARG(R5));
/*Make pair of them, R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*next parameter backward*/
SUB(R5,IMM(1));
JUMP(add_param_to_list_16704);
/*Finished to add all the opt parameter*/
end_add_param_to_list_16703:
/*put the list on the first unknown parameter*/
MOV(FPARG(3),R0);
generate_body_16705:
POP(R5);
/* Genreate code for the lambda body */
/* START_applic16707*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16707 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16707 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/* Return to the old frame pointer*/
POP(FP);
RETURN;
end_lambda_opt_body_lbl_16706:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16702:
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16700:
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16698:
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Get the symbol index we want to define, add 1 for the index of his value*/
MOV(R1,108);
/*Save in his value the pointer to the definition result*/
MOV(IND(R1),R0);
/*Return void in R0*/
MOV(R0,T_VOID);
CMP(R0,T_VOID);
JUMP_EQ(next_16696);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_16696:
/*Genrate code foe the definition and save the pointer to the result in R0*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16841:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16840);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16841);
end_extend_env_16840:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16839:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16838);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16839);
end_add_param_16838:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_16800));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_16800);
lambda_var_body_lbl_16800:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_16799);
/*Else create a list of pairs from the parameters*/
/*Create the last pair, magic +nil*/
ADD(R6,IMM(1));
PUSH(IMM(SOB_NIL));
PUSH(FPARG(R6));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*Return to r6 the parameters number*/
SUB(R6,IMM(1));
/*Loop over all the parameters backward*/
add_param_to_list_16798:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_16798);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_16798);
end_add_param_to_list_16798:
MOV(FPARG(2),R0);
generate_var_body_16799:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic16801*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16801 - operand #1 value */
/* START_applic16809*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16809 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16809 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16837:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16836);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16837);
end_extend_env_16836:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16835:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16834);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16835);
end_add_param_16834:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16810));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16810);
lambda_body_16810:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16833:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_16832);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16833);
end_extend_env_16832:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16831:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16830);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16831);
end_add_param_16830:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_16813));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_16813);
lambda_var_body_lbl_16813:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_16812);
/*Else create a list of pairs from the parameters*/
/*Create the last pair, magic +nil*/
ADD(R6,IMM(1));
PUSH(IMM(SOB_NIL));
PUSH(FPARG(R6));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*Return to r6 the parameters number*/
SUB(R6,IMM(1));
/*Loop over all the parameters backward*/
add_param_to_list_16811:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_16811);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_16811);
end_add_param_to_list_16811:
MOV(FPARG(2),R0);
generate_var_body_16812:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic16814*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16814 - operand #2 value */
/* START_applic16815*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16815 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16815 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16829:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_16828);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16829);
end_extend_env_16828:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16827:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16826);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16827);
end_add_param_16826:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16816));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16816);
lambda_body_16816:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16825:
/*Check if we end to copy all the env*/
CMP(R2,IMM(4));
JUMP_GE(end_extend_env_16824);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16825);
end_extend_env_16824:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16823:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16822);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16823);
end_add_param_16822:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_16819));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_16819);
lambda_var_body_lbl_16819:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_16818);
/*Else create a list of pairs from the parameters*/
/*Create the last pair, magic +nil*/
ADD(R6,IMM(1));
PUSH(IMM(SOB_NIL));
PUSH(FPARG(R6));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*Return to r6 the parameters number*/
SUB(R6,IMM(1));
/*Loop over all the parameters backward*/
add_param_to_list_16817:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_16817);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_16817);
end_add_param_to_list_16817:
MOV(FPARG(2),R0);
generate_var_body_16818:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic16820*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16820 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16820 - operand #1 value */
/* START_applic16821*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16821 - operand #2 value */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,1));
MOV(R0,INDD(R0,0));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16821 - operand #1 value */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,115);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,115);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return to the old frame pointer, R0 hold the lambda value*/
POP(FP);
RETURN;
end_lambda_var_body_lbl_16819:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16816:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,107);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16814 - operand #1 value */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,115);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return to the old frame pointer, R0 hold the lambda value*/
POP(FP);
RETURN;
end_lambda_var_body_lbl_16813:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16810:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,107);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16808:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16807);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16808);
end_extend_env_16807:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(1);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16806:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_16805);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16806);
end_add_param_16805:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16802));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16802);
lambda_body_16802:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16803*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16803 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16803 - operand #1 value */
/* START_applic16804*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16804 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,111);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,115);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16802:
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return to the old frame pointer, R0 hold the lambda value*/
POP(FP);
RETURN;
end_lambda_var_body_lbl_16800:
/*Get the symbol index we want to define, add 1 for the index of his value*/
MOV(R1,120);
/*Save in his value the pointer to the definition result*/
MOV(IND(R1),R0);
/*Return void in R0*/
MOV(R0,T_VOID);
CMP(R0,T_VOID);
JUMP_EQ(next_16797);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_16797:
/*Genrate code foe the definition and save the pointer to the result in R0*/
/* START_applic16843*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16843 - operand #2 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16874:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16873);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16874);
end_extend_env_16873:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16872:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16871);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16872);
end_add_param_16871:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16857));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16857);
lambda_body_16857:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16870:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16869);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16870);
end_extend_env_16869:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(2);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16868:
/*Check if we copy all the parameters*/
CMP(R4,2);
JUMP_GE(end_add_param_16867);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16868);
end_add_param_16867:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16858));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16858);
lambda_body_16858:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16863*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16863 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,109);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

CMP (IND(R0), T_BOOL);
JUMP_NE(dit16864);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif16866);
dit16864:
MOV(R0,IMM(101));

JUMP(exit16865);
dif16866:
/* START_applic16859*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16859 - operand #2 value */
/* START_applic16861*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16861 - operand #1 value */
/* START_applic16862*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16862 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,117);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,1));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16859 - operand #1 value */
/* START_applic16860*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16860 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,111);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,123);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);


exit16865:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16858:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16857:
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16843 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16856:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16855);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16856);
end_extend_env_16855:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16854:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16853);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16854);
end_add_param_16853:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16844));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16844);
lambda_body_16844:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16852:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_16851);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16852);
end_extend_env_16851:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(2);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16850:
/*Check if we copy all the parameters*/
CMP(R4,2);
JUMP_GE(end_add_param_16849);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16850);
end_add_param_16849:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_16847));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_16847);
lambda_var_body_lbl_16847:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_16846);
/*Else create a list of pairs from the parameters*/
/*Create the last pair, magic +nil*/
ADD(R6,IMM(1));
PUSH(IMM(SOB_NIL));
PUSH(FPARG(R6));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*Return to r6 the parameters number*/
SUB(R6,IMM(1));
/*Loop over all the parameters backward*/
add_param_to_list_16845:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_16845);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_16845);
end_add_param_to_list_16845:
MOV(FPARG(2),R0);
generate_var_body_16846:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic16848*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16848 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,1));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return to the old frame pointer, R0 hold the lambda value*/
POP(FP);
RETURN;
end_lambda_var_body_lbl_16847:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16844:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,119);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Get the symbol index we want to define, add 1 for the index of his value*/
MOV(R1,122);
/*Save in his value the pointer to the definition result*/
MOV(IND(R1),R0);
/*Return void in R0*/
MOV(R0,T_VOID);
CMP(R0,T_VOID);
JUMP_EQ(next_16842);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_16842:
/*Genrate code foe the definition and save the pointer to the result in R0*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16890:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16889);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16890);
end_extend_env_16889:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16888:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16887);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16888);
end_add_param_16887:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_opt_body_lbl_16879));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_opt_body_lbl_16879);
lambda_opt_body_lbl_16879:
/*Save current FP,R5 value and move fp to the start of the stack */
PUSH(FP);
MOV(FP,SP);
PUSH(R5);
/* Get the parameters number*/
MOV(R5,FPARG(1));
/*Check if there are parameters you dont know about them */
CMP(R5,IMM(1));
JUMP_EQ(generate_body_16878);
/*Create list of pairs and save the parameters value on the last known parameter*/
/*Create the last pair, magic+nill*/
ADD(R5,IMM(1));
PUSH(IMM(SOB_NIL));
PUSH(FPARG(R5));
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*Return to r5 the paramters number*/
SUB(R5,IMM(1));
/*foreach parameter create pair with his value and pointer to the next parameter backward*/
add_param_to_list_16877:
/*check if we finish to over all the parameters we dont know about them*/
CMP(R5,IMM(3));
JUMP_LT(end_add_param_to_list_16876);
/*Else, add the current parameter to the list*/
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*push the current parameter value*/
PUSH(FPARG(R5));
/*Make pair of them, R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*next parameter backward*/
SUB(R5,IMM(1));
JUMP(add_param_to_list_16877);
/*Finished to add all the opt parameter*/
end_add_param_to_list_16876:
/*put the list on the first unknown parameter*/
MOV(FPARG(3),R0);
generate_body_16878:
POP(R5);
/* Genreate code for the lambda body */
/* START_applic16883*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16883 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,109);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

CMP (IND(R0), T_BOOL);
JUMP_NE(dit16884);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif16886);
dit16884:
/* START_applic16882*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16882 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16882 - operand #1 value */
MOV(R0,IMM(101));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,127);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);


JUMP(exit16885);
dif16886:
/* START_applic16880*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16880 - operand #2 value */
/* START_applic16881*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16881 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16881 - operand #1 value */
/*Find the fvar index in the const table*/
MOV(R0,121);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,115);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16880 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,127);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);


exit16885:/* Return to the old frame pointer*/
POP(FP);
RETURN;
end_lambda_opt_body_lbl_16879:
/*Get the symbol index we want to define, add 1 for the index of his value*/
MOV(R1,126);
/*Save in his value the pointer to the definition result*/
MOV(IND(R1),R0);
/*Return void in R0*/
MOV(R0,T_VOID);
CMP(R0,T_VOID);
JUMP_EQ(next_16875);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_16875:
/* START_applic16892*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16892 - operand #1 value */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16909:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16908);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16909);
end_extend_env_16908:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16907:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16906);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16907);
end_add_param_16906:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16899));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16899);
lambda_body_16899:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16902*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16902 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,129);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

CMP (IND(R0), T_BOOL);
JUMP_NE(dit16903);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif16905);
dit16903:
MOV(R0, IMM(SOB_TRUE));

JUMP(exit16904);
dif16905:
/* START_applic16900*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16900 - operand #2 value */
/* START_applic16901*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16901 - operand #2 value */
MOV(R0,IMM(105));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16901 - operand #1 value */
MOV(R0,FPARG(3));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,125);
/*Check if we found the fvar*/
CMP(R0,IMM(SOB_NIL));
JUMP_EQ(ERROR_VAR_NOT_FOUND);
/*Put the value of the fvar in R0*/
MOV(R0,INDD(R0,1));
CMP(R0,T_UNDEF);
JUMP_EQ(UNDEF_VAR);
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16900 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(2));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);


exit16904:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16899:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/*Create closure to the current lambda*/
/*Save current registers value*/
PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);
/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(IND(R0),IMM(T_CLOSURE));
/*Save the pointer for the new clouser*/
MOV(R1,R0);
/*extend the env*/
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_16898:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_16897);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_16898);
end_extend_env_16897:
/*Save in r2 the new env pointer*/
MOV(R2,R0);
/*Create place to the lambda parameters*/
PUSH(0);
CALL(MALLOC);
DROP(IMM(1));
/*Connect the env in place 0 to the lambda params*/
MOV(IND(R2),R0);
/*Define iterators to copy parameters*/
MOV(R4,IMM(0));
MOV(R5,IMM(2));
add_param_16896:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_16895);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_16896);
end_add_param_16895:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_16893));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_16893);
lambda_body_16893:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic16894*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic16894 - operand #2 value */
MOV(R0,IMM(103));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic16894 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
MOV(R0,FPARG(2));
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_16893:
/* final stage of the procedure */
CMP(IND(R0),IMM(T_CLOSURE));
JUMP_NE(ERROR_APPLIC);
PUSH(INDD(R0,1));
/* stack is ready - call the code address */
CALLA(INDD(R0,2));
/* calculate sum of "push"es to the stack and drop */ 
MOV(R1,STARG(0));
ADD(R1,IMM(3));
DROP(IMM(R1));
POP(R1);

CMP(R0,T_VOID);
JUMP_EQ(next_16891);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_16891:

JUMP(END);

ERROR_APPLIC:
PUSH(49);
JUMP(WRITE_ERROR);

UNDEF_VAR:
PUSH(50);
JUMP(WRITE_ERROR);

ERROR_VAR_NOT_FOUND:
PUSH(51);
JUMP(WRITE_ERROR);

ARGS_FAULT:
PUSH(52);
JUMP(WRITE_ERROR);

NOT_INTEGER_ERROR:
PUSH(53);
JUMP(WRITE_ERROR);

NOT_PAIR_ERROR:
PUSH(54);
JUMP(WRITE_ERROR);

NOT_STRING_ERROR:
PUSH(55);
JUMP(WRITE_ERROR);

NOT_SYMBOL_ERROR:
PUSH(56);
JUMP(WRITE_ERROR);

NOT_CLOSURE_ERROR:
PUSH(57);
JUMP(WRITE_ERROR);

NOT_VECTOR_ERROR:
PUSH(58);
JUMP(WRITE_ERROR);

NOT_CHAR_ERROR:
PUSH(59);
JUMP(WRITE_ERROR);

INDEXES_MISMATCH:
PUSH(60);
JUMP(WRITE_ERROR);

WRITE_ERROR:
PUSH(69);
PUSH(82);
PUSH(82);
PUSH(79);
PUSH(82);
PUSH(6);
CALL(MAKE_SOB_STRING);
DROP(6);
PUSH(R0);
CALL(WRITE_SOB_STRING);
return 1;


END:			
	STOP_MACHINE;

	return 0;
}
