	
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
PUSH(IMM(1));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
PUSH(IMM(8));
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
MOV(INDD(R0,2),LABEL(IS_ZERO));
MOV(R1,127);
MOV(INDD(R1,1),R0);
/* end insert values to symbols */

	/* Fake Env */

	PUSH(IMM(0));
	PUSH(IMM(T_NIL));
	PUSH(LABEL(END));
	PUSH(FP);
	MOV(FP,SP);

	/* code generation */
	/*Genrate code foe the definition and save the pointer to the result in R0*/
/* START_applic25942*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25942 - operand #1 value */
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
extend_env_26041:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26040);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26041);
end_extend_env_26040:
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
add_param_26039:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26038);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26039);
end_add_param_26038:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26010));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26010);
lambda_body_26010:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26011*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26011 - operand #1 value */
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
extend_env_26037:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26036);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26037);
end_extend_env_26036:
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
add_param_26035:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26034);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26035);
end_add_param_26034:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26025));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26025);
lambda_body_26025:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26026*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26026 - operand #1 value */
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
extend_env_26033:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26032);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26033);
end_extend_env_26032:
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
add_param_26031:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26030);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26031);
end_add_param_26030:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26027));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26027);
lambda_body_26027:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26028*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26028 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26028 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/* START_applic26029*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26029 - operand #1 value */
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
end_lambda_body_26027:
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
end_lambda_body_26025:
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
extend_env_26024:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26023);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26024);
end_extend_env_26023:
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
add_param_26022:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26021);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26022);
end_add_param_26021:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26012));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26012);
lambda_body_26012:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26013*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26013 - operand #1 value */
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
extend_env_26020:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26019);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26020);
end_extend_env_26019:
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
add_param_26018:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26017);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26018);
end_add_param_26017:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26014));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26014);
lambda_body_26014:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26015*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26015 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26015 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/* START_applic26016*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26016 - operand #1 value */
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
end_lambda_body_26014:
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
end_lambda_body_26012:
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
end_lambda_body_26010:
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
extend_env_26009:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26008);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26009);
end_extend_env_26008:
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
add_param_26007:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26006);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26007);
end_add_param_26006:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25943));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25943);
lambda_body_25943:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic25944*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25944 - operand #1 value */
/* START_applic25986*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25986 - operand #1 value */
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
extend_env_26005:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26004);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26005);
end_extend_env_26004:
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
add_param_26003:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26002);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26003);
end_add_param_26002:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25987));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25987);
lambda_body_25987:
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
extend_env_26001:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26000);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26001);
end_extend_env_26000:
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
add_param_25999:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_25998);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_25999);
end_add_param_25998:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25988));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25988);
lambda_body_25988:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic25994*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25994 - operand #1 value */
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
JUMP_NE(dit25995);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif25997);
dit25995:
MOV(R0, IMM(SOB_NIL));

JUMP(exit25996);
dif25997:
/* START_applic25989*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25989 - operand #2 value */
/* START_applic25992*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25992 - operand #2 value */
/* START_applic25993*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25993 - operand #1 value */
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
/* generating applic25992 - operand #1 value */
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
/* generating applic25989 - operand #1 value */
/* START_applic25990*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25990 - operand #1 value */
/* START_applic25991*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25991 - operand #1 value */
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


exit25996:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_25988:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_25987:
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
extend_env_25985:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_25984);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_25985);
end_extend_env_25984:
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
add_param_25983:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_25982);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_25983);
end_add_param_25982:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25945));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25945);
lambda_body_25945:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic25946*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25946 - operand #1 value */
/* START_applic25961*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25961 - operand #1 value */
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
extend_env_25981:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_25980);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_25981);
end_extend_env_25980:
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
add_param_25979:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_25978);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_25979);
end_add_param_25978:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25962));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25962);
lambda_body_25962:
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
extend_env_25977:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_25976);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_25977);
end_extend_env_25976:
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
add_param_25975:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_25974);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_25975);
end_add_param_25974:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25963));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25963);
lambda_body_25963:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic25969*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25969 - operand #1 value */
/* START_applic25970*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25970 - operand #1 value */
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
JUMP_NE(dit25971);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif25973);
dit25971:
MOV(R0, IMM(SOB_NIL));

JUMP(exit25972);
dif25973:
/* START_applic25964*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25964 - operand #2 value */
/* START_applic25967*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25967 - operand #2 value */
/* START_applic25968*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25968 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic25968 - operand #1 value */
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
/* generating applic25967 - operand #1 value */
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
/* generating applic25964 - operand #1 value */
/* START_applic25965*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25965 - operand #2 value */
/* START_applic25966*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25966 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic25966 - operand #1 value */
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
/* generating applic25965 - operand #1 value */
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


exit25972:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_25963:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_25962:
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
extend_env_25960:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_25959);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_25960);
end_extend_env_25959:
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
add_param_25958:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_25957);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_25958);
end_add_param_25957:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_25947));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_25947);
lambda_body_25947:
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
extend_env_25956:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_25955);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_25956);
end_extend_env_25955:
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
add_param_25954:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_25953);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_25954);
end_add_param_25953:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_opt_body_lbl_25951));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_opt_body_lbl_25951);
lambda_opt_body_lbl_25951:
/*Save current FP,R5 value and move fp to the start of the stack */
PUSH(FP);
MOV(FP,SP);
PUSH(R5);
/* Get the parameters number*/
MOV(R5,FPARG(1));
/*Check if there are parameters you dont know about them */
CMP(R5,IMM(1));
JUMP_EQ(generate_body_25950);
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
add_param_to_list_25949:
/*check if we finish to over all the parameters we dont know about them*/
CMP(R5,IMM(3));
JUMP_LT(end_add_param_to_list_25948);
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
JUMP(add_param_to_list_25949);
/*Finished to add all the opt parameter*/
end_add_param_to_list_25948:
/*put the list on the first unknown parameter*/
MOV(FPARG(3),R0);
generate_body_25950:
POP(R5);
/* Genreate code for the lambda body */
/* START_applic25952*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic25952 - operand #2 value */
MOV(R0,FPARG(3));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic25952 - operand #1 value */
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
end_lambda_opt_body_lbl_25951:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_25947:
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
end_lambda_body_25945:
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
end_lambda_body_25943:
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
JUMP_EQ(next_25941);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_25941:
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
extend_env_26086:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26085);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26086);
end_extend_env_26085:
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
add_param_26084:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26083);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26084);
end_add_param_26083:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_26045));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_26045);
lambda_var_body_lbl_26045:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_26044);
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
add_param_to_list_26043:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_26043);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_26043);
end_add_param_to_list_26043:
MOV(FPARG(2),R0);
generate_var_body_26044:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic26046*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26046 - operand #1 value */
/* START_applic26054*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26054 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26054 - operand #1 value */
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
extend_env_26082:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26081);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26082);
end_extend_env_26081:
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
add_param_26080:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26079);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26080);
end_add_param_26079:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26055));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26055);
lambda_body_26055:
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
extend_env_26078:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26077);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26078);
end_extend_env_26077:
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
add_param_26076:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26075);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26076);
end_add_param_26075:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_26058));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_26058);
lambda_var_body_lbl_26058:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_26057);
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
add_param_to_list_26056:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_26056);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_26056);
end_add_param_to_list_26056:
MOV(FPARG(2),R0);
generate_var_body_26057:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic26059*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26059 - operand #2 value */
/* START_applic26060*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26060 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26060 - operand #1 value */
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
extend_env_26074:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_26073);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26074);
end_extend_env_26073:
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
add_param_26072:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26071);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26072);
end_add_param_26071:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26061));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26061);
lambda_body_26061:
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
extend_env_26070:
/*Check if we end to copy all the env*/
CMP(R2,IMM(4));
JUMP_GE(end_extend_env_26069);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26070);
end_extend_env_26069:
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
add_param_26068:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26067);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26068);
end_add_param_26067:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_26064));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_26064);
lambda_var_body_lbl_26064:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_26063);
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
add_param_to_list_26062:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_26062);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_26062);
end_add_param_to_list_26062:
MOV(FPARG(2),R0);
generate_var_body_26063:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic26065*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26065 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26065 - operand #1 value */
/* START_applic26066*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26066 - operand #2 value */
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,1));
MOV(R0,INDD(R0,0));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26066 - operand #1 value */
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
end_lambda_var_body_lbl_26064:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26061:
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
/* generating applic26059 - operand #1 value */
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
end_lambda_var_body_lbl_26058:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26055:
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
extend_env_26053:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26052);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26053);
end_extend_env_26052:
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
add_param_26051:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26050);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26051);
end_add_param_26050:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26047));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26047);
lambda_body_26047:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26048*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26048 - operand #2 value */
MOV(R0,FPARG(2));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26048 - operand #1 value */
/* START_applic26049*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26049 - operand #1 value */
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
end_lambda_body_26047:
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
end_lambda_var_body_lbl_26045:
/*Get the symbol index we want to define, add 1 for the index of his value*/
MOV(R1,120);
/*Save in his value the pointer to the definition result*/
MOV(IND(R1),R0);
/*Return void in R0*/
MOV(R0,T_VOID);
CMP(R0,T_VOID);
JUMP_EQ(next_26042);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_26042:
/*Genrate code foe the definition and save the pointer to the result in R0*/
/* START_applic26088*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26088 - operand #2 value */
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
extend_env_26119:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26118);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26119);
end_extend_env_26118:
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
add_param_26117:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26116);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26117);
end_add_param_26116:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26102));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26102);
lambda_body_26102:
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
extend_env_26115:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26114);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26115);
end_extend_env_26114:
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
add_param_26113:
/*Check if we copy all the parameters*/
CMP(R4,2);
JUMP_GE(end_add_param_26112);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26113);
end_add_param_26112:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26103));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26103);
lambda_body_26103:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26108*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26108 - operand #1 value */
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
JUMP_NE(dit26109);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif26111);
dit26109:
MOV(R0,IMM(101));

JUMP(exit26110);
dif26111:
/* START_applic26104*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26104 - operand #2 value */
/* START_applic26106*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26106 - operand #1 value */
/* START_applic26107*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26107 - operand #1 value */
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
/* generating applic26104 - operand #1 value */
/* START_applic26105*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26105 - operand #1 value */
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


exit26110:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26103:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26102:
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26088 - operand #1 value */
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
extend_env_26101:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26100);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26101);
end_extend_env_26100:
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
add_param_26099:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26098);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26099);
end_add_param_26098:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26089));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26089);
lambda_body_26089:
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
extend_env_26097:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26096);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26097);
end_extend_env_26096:
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
add_param_26095:
/*Check if we copy all the parameters*/
CMP(R4,2);
JUMP_GE(end_add_param_26094);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26095);
end_add_param_26094:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_var_body_lbl_26092));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_var_body_lbl_26092);
lambda_var_body_lbl_26092:
/*Save current FP,R6 value and move fo to the start of the stack*/
PUSH(FP);
MOV(FP,SP);
PUSH(R6);
/* Get the parameters number*/
MOV(R6,FPARG(1));
/*Check if there are parameters*/
CMP(R6,IMM(0));
/*If there is not any parameters generate body*/
JUMP_EQ(generate_var_body_26091);
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
add_param_to_list_26090:
/*Check if we finished to over all the parameters*/
CMP(R6,IMM(2));
JUMP_LT(end_add_param_to_list_26090);
/*Push the pointer to the next parameter in the list*/
PUSH(R0);
/*Push the current parameter value*/
PUSH(FPARG(R6));
/*Make pair of them , R0 will be the pointer to the pair*/
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
/*move the next parameter backward*/
SUB(R6,IMM(1));
JUMP(add_param_to_list_26090);
end_add_param_to_list_26090:
MOV(FPARG(2),R0);
generate_var_body_26091:
/*Return r6 to the value before we start the lambda*/
POP(R6);
/*Genrate CISC code for the body*/
/* START_applic26093*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26093 - operand #1 value */
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
end_lambda_var_body_lbl_26092:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26089:
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
JUMP_EQ(next_26087);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_26087:
/*Genrate code foe the definition and save the pointer to the result in R0*/
/* START_applic26121*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26121 - operand #2 value */
/* START_applic26949*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26949 - operand #1 value */
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
extend_env_27001:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_27000);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_27001);
end_extend_env_27000:
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
add_param_26999:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26998);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26999);
end_add_param_26998:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26956));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26956);
lambda_body_26956:
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
extend_env_26997:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26996);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26997);
end_extend_env_26996:
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
add_param_26995:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26994);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26995);
end_add_param_26994:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26957));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26957);
lambda_body_26957:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26990*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26990 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
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

CMP (IND(R0), T_BOOL);
JUMP_NE(dit26991);
CMP (INDD(R0,1),IMM(0));
JUMP_EQ(dif26993);
dit26991:
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
extend_env_26989:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26988);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26989);
end_extend_env_26988:
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
add_param_26987:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26986);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26987);
end_add_param_26986:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26980));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26980);
lambda_body_26980:
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
extend_env_26985:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_26984);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26985);
end_extend_env_26984:
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
add_param_26983:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26982);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26983);
end_add_param_26982:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26981));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26981);
lambda_body_26981:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
MOV(R0,FPARG(2));
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26981:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26980:

JUMP(exit26992);
dif26993:
/* START_applic26958*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26958 - operand #1 value */
/* START_applic26977*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26977 - operand #1 value */
/* START_applic26979*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26979 - operand #2 value */
MOV(R0,IMM(103));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26979 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26978*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26978 - operand #1 value */
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
extend_env_26976:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26975);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26976);
end_extend_env_26975:
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
add_param_26974:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26973);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26974);
end_add_param_26973:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26959));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26959);
lambda_body_26959:
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
extend_env_26972:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_26971);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26972);
end_extend_env_26971:
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
add_param_26970:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26969);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26970);
end_add_param_26969:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26960));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26960);
lambda_body_26960:
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
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
/*Save pointer to the new env*/
MOV(INDD(R1,1),R0);
/*Define iterator to copy env pointers*/
MOV(R2,IMM(0));
MOV(R3,IMM(1));
extend_env_26968:
/*Check if we end to copy all the env*/
CMP(R2,IMM(4));
JUMP_GE(end_extend_env_26967);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26968);
end_extend_env_26967:
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
add_param_26966:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26965);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26966);
end_add_param_26965:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26961));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26961);
lambda_body_26961:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26962*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26962 - operand #1 value */
/* START_applic26963*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26963 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26964*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26964 - operand #1 value */
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
end_lambda_body_26961:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26960:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26959:
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


exit26992:/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26957:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26956:
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
extend_env_26955:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26954);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26955);
end_extend_env_26954:
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
add_param_26953:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26952);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26953);
end_add_param_26952:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26950));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26950);
lambda_body_26950:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26951*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26951 - operand #1 value */
MOV(R0,FPARG(2));
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

/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26950:
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
/* generating applic26121 - operand #1 value */
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
extend_env_26948:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26947);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26948);
end_extend_env_26947:
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
add_param_26946:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26945);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26946);
end_add_param_26945:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26914));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26914);
lambda_body_26914:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26915*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26915 - operand #1 value */
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
extend_env_26944:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26943);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26944);
end_extend_env_26943:
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
add_param_26942:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26941);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26942);
end_add_param_26941:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26935));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26935);
lambda_body_26935:
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
extend_env_26940:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26939);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26940);
end_extend_env_26939:
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
add_param_26938:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26937);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26938);
end_add_param_26937:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26936));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26936);
lambda_body_26936:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
MOV(R0,FPARG(0));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26936:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26935:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26916*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26916 - operand #1 value */
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
extend_env_26934:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26933);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26934);
end_extend_env_26933:
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
add_param_26932:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26931);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26932);
end_add_param_26931:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26917));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26917);
lambda_body_26917:
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
extend_env_26930:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26929);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26930);
end_extend_env_26929:
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
add_param_26928:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26927);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26928);
end_add_param_26927:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26918));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26918);
lambda_body_26918:
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
extend_env_26926:
/*Check if we end to copy all the env*/
CMP(R2,IMM(3));
JUMP_GE(end_extend_env_26925);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26926);
end_extend_env_26925:
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
add_param_26924:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26923);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26924);
end_add_param_26923:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26919));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26919);
lambda_body_26919:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26920*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26920 - operand #1 value */
/* START_applic26922*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26922 - operand #1 value */
MOV(R0,FPARG(2));
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
/* START_applic26921*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26921 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
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
end_lambda_body_26919:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26918:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26917:
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
end_lambda_body_26914:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
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
extend_env_26913:
/*Check if we end to copy all the env*/
CMP(R2,IMM(0));
JUMP_GE(end_extend_env_26912);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26913);
end_extend_env_26912:
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
add_param_26911:
/*Check if we copy all the parameters*/
CMP(R4,0);
JUMP_GE(end_add_param_26910);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26911);
end_add_param_26910:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26122));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26122);
lambda_body_26122:
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
extend_env_26909:
/*Check if we end to copy all the env*/
CMP(R2,IMM(1));
JUMP_GE(end_extend_env_26908);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26909);
end_extend_env_26908:
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
add_param_26907:
/*Check if we copy all the parameters*/
CMP(R4,2);
JUMP_GE(end_add_param_26906);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26907);
end_add_param_26906:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26123));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26123);
lambda_body_26123:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26124*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26124 - operand #1 value */
MOV(R0,IMM(101));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26125*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26125 - operand #1 value */
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
extend_env_26905:
/*Check if we end to copy all the env*/
CMP(R2,IMM(2));
JUMP_GE(end_extend_env_26904);
/*Get the last env pointer from the stack*/
MOV(R4,FPARG(0));
/*Copy from the last env to the new env in index+1*/
MOV(INDD(R0,R3),INDD(R4,R2));
/*Increase Iterators*/
ADD(R2,IMM(1));
ADD(R3,IMM(1));
JUMP(extend_env_26905);
end_extend_env_26904:
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
add_param_26903:
/*Check if we copy all the parameters*/
CMP(R4,1);
JUMP_GE(end_add_param_26902);
/*Copy the current parameter from the stack*/
MOV(INDD(R0,R4),FPARG(R5));
/*Increase iterators*/
ADD(R5,IMM(1));
ADD(R4,IMM(1));
JUMP(add_param_26903);
end_add_param_26902:
/*Save pointer to the lambda body in the clousre we created*/
MOV(INDD(R1,2),LABEL(lambda_body_26900));
/*R0 will hold the pointer to the new clouser*/
MOV(R0,R1);
/*Return the registers to the previous state*/
POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);
JUMP(end_lambda_body_26900);
lambda_body_26900:
/*Save FP,SP current value*/
	PUSH(FP);
	MOV(FP,SP);
/*Generate code for the body of the lambda*/
/* START_applic26901*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26901 - operand #2 value */
MOV(R0,IMM(103));
/*push operand #2 evaluated result*/
PUSH(R0);
/* generating applic26901 - operand #1 value */
MOV(R0,FPARG(2));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(2));
/* generate applic's operator code */
/*Find the fvar index in the const table*/
MOV(R0,121);
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
end_lambda_body_26900:
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26126*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26126 - operand #1 value */
/* START_applic26899*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26899 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26127*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26127 - operand #1 value */
/* START_applic26883*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26883 - operand #1 value */
/* START_applic26887*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26887 - operand #1 value */
/* START_applic26896*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26896 - operand #1 value */
/* START_applic26897*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26897 - operand #1 value */
/* START_applic26898*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26898 - operand #1 value */
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
/* START_applic26888*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26888 - operand #1 value */
/* START_applic26893*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26893 - operand #1 value */
/* START_applic26894*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26894 - operand #1 value */
/* START_applic26895*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26895 - operand #1 value */
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
/* START_applic26889*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26889 - operand #1 value */
/* START_applic26890*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26890 - operand #1 value */
/* START_applic26891*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26891 - operand #1 value */
/* START_applic26892*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26892 - operand #1 value */
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
/* START_applic26884*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26884 - operand #1 value */
/* START_applic26885*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26885 - operand #1 value */
/* START_applic26886*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26886 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26128*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26128 - operand #1 value */
/* START_applic26173*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26173 - operand #1 value */
/* START_applic26692*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26692 - operand #1 value */
/* START_applic26844*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26844 - operand #1 value */
/* START_applic26867*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26867 - operand #1 value */
/* START_applic26871*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26871 - operand #1 value */
/* START_applic26880*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26880 - operand #1 value */
/* START_applic26881*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26881 - operand #1 value */
/* START_applic26882*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26882 - operand #1 value */
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
/* START_applic26872*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26872 - operand #1 value */
/* START_applic26877*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26877 - operand #1 value */
/* START_applic26878*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26878 - operand #1 value */
/* START_applic26879*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26879 - operand #1 value */
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
/* START_applic26873*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26873 - operand #1 value */
/* START_applic26874*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26874 - operand #1 value */
/* START_applic26875*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26875 - operand #1 value */
/* START_applic26876*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26876 - operand #1 value */
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
/* START_applic26868*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26868 - operand #1 value */
/* START_applic26869*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26869 - operand #1 value */
/* START_applic26870*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26870 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26845*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26845 - operand #1 value */
/* START_applic26850*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26850 - operand #1 value */
/* START_applic26864*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26864 - operand #1 value */
/* START_applic26865*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26865 - operand #1 value */
/* START_applic26866*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26866 - operand #1 value */
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
/* START_applic26851*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26851 - operand #1 value */
/* START_applic26856*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26856 - operand #1 value */
/* START_applic26860*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26860 - operand #1 value */
/* START_applic26861*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26861 - operand #1 value */
/* START_applic26862*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26862 - operand #1 value */
/* START_applic26863*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26863 - operand #1 value */
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
/* START_applic26857*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26857 - operand #1 value */
/* START_applic26858*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26858 - operand #1 value */
/* START_applic26859*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26859 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26852*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26852 - operand #1 value */
/* START_applic26853*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26853 - operand #1 value */
/* START_applic26854*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26854 - operand #1 value */
/* START_applic26855*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26855 - operand #1 value */
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
/* START_applic26846*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26846 - operand #1 value */
/* START_applic26847*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26847 - operand #1 value */
/* START_applic26848*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26848 - operand #1 value */
/* START_applic26849*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26849 - operand #1 value */
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
/* START_applic26693*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26693 - operand #1 value */
/* START_applic26805*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26805 - operand #1 value */
/* START_applic26828*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26828 - operand #1 value */
/* START_applic26832*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26832 - operand #1 value */
/* START_applic26841*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26841 - operand #1 value */
/* START_applic26842*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26842 - operand #1 value */
/* START_applic26843*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26843 - operand #1 value */
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
/* START_applic26833*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26833 - operand #1 value */
/* START_applic26838*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26838 - operand #1 value */
/* START_applic26839*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26839 - operand #1 value */
/* START_applic26840*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26840 - operand #1 value */
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
/* START_applic26834*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26834 - operand #1 value */
/* START_applic26835*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26835 - operand #1 value */
/* START_applic26836*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26836 - operand #1 value */
/* START_applic26837*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26837 - operand #1 value */
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
/* START_applic26829*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26829 - operand #1 value */
/* START_applic26830*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26830 - operand #1 value */
/* START_applic26831*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26831 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26806*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26806 - operand #1 value */
/* START_applic26811*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26811 - operand #1 value */
/* START_applic26825*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26825 - operand #1 value */
/* START_applic26826*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26826 - operand #1 value */
/* START_applic26827*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26827 - operand #1 value */
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
/* START_applic26812*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26812 - operand #1 value */
/* START_applic26817*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26817 - operand #1 value */
/* START_applic26821*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26821 - operand #1 value */
/* START_applic26822*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26822 - operand #1 value */
/* START_applic26823*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26823 - operand #1 value */
/* START_applic26824*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26824 - operand #1 value */
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
/* START_applic26818*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26818 - operand #1 value */
/* START_applic26819*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26819 - operand #1 value */
/* START_applic26820*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26820 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26813*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26813 - operand #1 value */
/* START_applic26814*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26814 - operand #1 value */
/* START_applic26815*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26815 - operand #1 value */
/* START_applic26816*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26816 - operand #1 value */
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
/* START_applic26807*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26807 - operand #1 value */
/* START_applic26808*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26808 - operand #1 value */
/* START_applic26809*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26809 - operand #1 value */
/* START_applic26810*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26810 - operand #1 value */
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
/* START_applic26694*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26694 - operand #1 value */
/* START_applic26748*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26748 - operand #1 value */
/* START_applic26793*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26793 - operand #1 value */
/* START_applic26802*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26802 - operand #1 value */
/* START_applic26803*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26803 - operand #1 value */
/* START_applic26804*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26804 - operand #1 value */
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
/* START_applic26794*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26794 - operand #1 value */
/* START_applic26799*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26799 - operand #1 value */
/* START_applic26800*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26800 - operand #1 value */
/* START_applic26801*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26801 - operand #1 value */
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
/* START_applic26795*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26795 - operand #1 value */
/* START_applic26796*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26796 - operand #1 value */
/* START_applic26797*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26797 - operand #1 value */
/* START_applic26798*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26798 - operand #1 value */
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
/* START_applic26749*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26749 - operand #1 value */
/* START_applic26786*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26786 - operand #1 value */
/* START_applic26790*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26790 - operand #1 value */
/* START_applic26791*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26791 - operand #1 value */
/* START_applic26792*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26792 - operand #1 value */
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
/* START_applic26787*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26787 - operand #1 value */
/* START_applic26788*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26788 - operand #1 value */
/* START_applic26789*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26789 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26750*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26750 - operand #1 value */
/* START_applic26755*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26755 - operand #1 value */
/* START_applic26769*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26769 - operand #1 value */
/* START_applic26782*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26782 - operand #1 value */
/* START_applic26783*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26783 - operand #1 value */
/* START_applic26784*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26784 - operand #1 value */
/* START_applic26785*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26785 - operand #1 value */
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
/* START_applic26770*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26770 - operand #1 value */
/* START_applic26775*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26775 - operand #1 value */
/* START_applic26779*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26779 - operand #1 value */
/* START_applic26780*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26780 - operand #1 value */
/* START_applic26781*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26781 - operand #1 value */
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
/* START_applic26776*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26776 - operand #1 value */
/* START_applic26777*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26777 - operand #1 value */
/* START_applic26778*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26778 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26771*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26771 - operand #1 value */
/* START_applic26772*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26772 - operand #1 value */
/* START_applic26773*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26773 - operand #1 value */
/* START_applic26774*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26774 - operand #1 value */
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
/* START_applic26756*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26756 - operand #1 value */
/* START_applic26761*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26761 - operand #1 value */
/* START_applic26765*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26765 - operand #1 value */
/* START_applic26766*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26766 - operand #1 value */
/* START_applic26767*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26767 - operand #1 value */
/* START_applic26768*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26768 - operand #1 value */
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
/* START_applic26762*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26762 - operand #1 value */
/* START_applic26763*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26763 - operand #1 value */
/* START_applic26764*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26764 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26757*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26757 - operand #1 value */
/* START_applic26758*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26758 - operand #1 value */
/* START_applic26759*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26759 - operand #1 value */
/* START_applic26760*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26760 - operand #1 value */
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
/* START_applic26751*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26751 - operand #1 value */
/* START_applic26752*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26752 - operand #1 value */
/* START_applic26753*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26753 - operand #1 value */
/* START_applic26754*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26754 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26695*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26695 - operand #1 value */
/* START_applic26700*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26700 - operand #1 value */
/* START_applic26704*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26704 - operand #1 value */
/* START_applic26741*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26741 - operand #1 value */
/* START_applic26745*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26745 - operand #1 value */
/* START_applic26746*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26746 - operand #1 value */
/* START_applic26747*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26747 - operand #1 value */
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
/* START_applic26742*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26742 - operand #1 value */
/* START_applic26743*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26743 - operand #1 value */
/* START_applic26744*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26744 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26705*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26705 - operand #1 value */
/* START_applic26710*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26710 - operand #1 value */
/* START_applic26724*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26724 - operand #1 value */
/* START_applic26737*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26737 - operand #1 value */
/* START_applic26738*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26738 - operand #1 value */
/* START_applic26739*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26739 - operand #1 value */
/* START_applic26740*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26740 - operand #1 value */
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
/* START_applic26725*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26725 - operand #1 value */
/* START_applic26730*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26730 - operand #1 value */
/* START_applic26734*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26734 - operand #1 value */
/* START_applic26735*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26735 - operand #1 value */
/* START_applic26736*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26736 - operand #1 value */
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
/* START_applic26731*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26731 - operand #1 value */
/* START_applic26732*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26732 - operand #1 value */
/* START_applic26733*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26733 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26726*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26726 - operand #1 value */
/* START_applic26727*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26727 - operand #1 value */
/* START_applic26728*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26728 - operand #1 value */
/* START_applic26729*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26729 - operand #1 value */
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
/* START_applic26711*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26711 - operand #1 value */
/* START_applic26716*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26716 - operand #1 value */
/* START_applic26720*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26720 - operand #1 value */
/* START_applic26721*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26721 - operand #1 value */
/* START_applic26722*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26722 - operand #1 value */
/* START_applic26723*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26723 - operand #1 value */
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
/* START_applic26717*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26717 - operand #1 value */
/* START_applic26718*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26718 - operand #1 value */
/* START_applic26719*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26719 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26712*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26712 - operand #1 value */
/* START_applic26713*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26713 - operand #1 value */
/* START_applic26714*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26714 - operand #1 value */
/* START_applic26715*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26715 - operand #1 value */
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
/* START_applic26706*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26706 - operand #1 value */
/* START_applic26707*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26707 - operand #1 value */
/* START_applic26708*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26708 - operand #1 value */
/* START_applic26709*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26709 - operand #1 value */
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
/* START_applic26701*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26701 - operand #1 value */
/* START_applic26702*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26702 - operand #1 value */
/* START_applic26703*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26703 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26696*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26696 - operand #1 value */
/* START_applic26697*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26697 - operand #1 value */
/* START_applic26698*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26698 - operand #1 value */
/* START_applic26699*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26699 - operand #1 value */
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
/* START_applic26174*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26174 - operand #1 value */
/* START_applic26219*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26219 - operand #1 value */
/* START_applic26277*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26277 - operand #1 value */
/* START_applic26515*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26515 - operand #1 value */
/* START_applic26618*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26618 - operand #1 value */
/* START_applic26676*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26676 - operand #1 value */
/* START_applic26680*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26680 - operand #1 value */
/* START_applic26689*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26689 - operand #1 value */
/* START_applic26690*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26690 - operand #1 value */
/* START_applic26691*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26691 - operand #1 value */
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
/* START_applic26681*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26681 - operand #1 value */
/* START_applic26686*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26686 - operand #1 value */
/* START_applic26687*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26687 - operand #1 value */
/* START_applic26688*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26688 - operand #1 value */
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
/* START_applic26682*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26682 - operand #1 value */
/* START_applic26683*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26683 - operand #1 value */
/* START_applic26684*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26684 - operand #1 value */
/* START_applic26685*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26685 - operand #1 value */
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
/* START_applic26677*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26677 - operand #1 value */
/* START_applic26678*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26678 - operand #1 value */
/* START_applic26679*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26679 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26619*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26619 - operand #1 value */
/* START_applic26664*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26664 - operand #1 value */
/* START_applic26673*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26673 - operand #1 value */
/* START_applic26674*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26674 - operand #1 value */
/* START_applic26675*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26675 - operand #1 value */
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
/* START_applic26665*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26665 - operand #1 value */
/* START_applic26670*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26670 - operand #1 value */
/* START_applic26671*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26671 - operand #1 value */
/* START_applic26672*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26672 - operand #1 value */
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
/* START_applic26666*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26666 - operand #1 value */
/* START_applic26667*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26667 - operand #1 value */
/* START_applic26668*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26668 - operand #1 value */
/* START_applic26669*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26669 - operand #1 value */
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
/* START_applic26620*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26620 - operand #1 value */
/* START_applic26657*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26657 - operand #1 value */
/* START_applic26661*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26661 - operand #1 value */
/* START_applic26662*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26662 - operand #1 value */
/* START_applic26663*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26663 - operand #1 value */
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
/* START_applic26658*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26658 - operand #1 value */
/* START_applic26659*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26659 - operand #1 value */
/* START_applic26660*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26660 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26621*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26621 - operand #1 value */
/* START_applic26626*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26626 - operand #1 value */
/* START_applic26640*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26640 - operand #1 value */
/* START_applic26653*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26653 - operand #1 value */
/* START_applic26654*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26654 - operand #1 value */
/* START_applic26655*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26655 - operand #1 value */
/* START_applic26656*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26656 - operand #1 value */
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
/* START_applic26641*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26641 - operand #1 value */
/* START_applic26646*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26646 - operand #1 value */
/* START_applic26650*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26650 - operand #1 value */
/* START_applic26651*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26651 - operand #1 value */
/* START_applic26652*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26652 - operand #1 value */
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
/* START_applic26647*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26647 - operand #1 value */
/* START_applic26648*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26648 - operand #1 value */
/* START_applic26649*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26649 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26642*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26642 - operand #1 value */
/* START_applic26643*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26643 - operand #1 value */
/* START_applic26644*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26644 - operand #1 value */
/* START_applic26645*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26645 - operand #1 value */
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
/* START_applic26627*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26627 - operand #1 value */
/* START_applic26632*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26632 - operand #1 value */
/* START_applic26636*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26636 - operand #1 value */
/* START_applic26637*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26637 - operand #1 value */
/* START_applic26638*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26638 - operand #1 value */
/* START_applic26639*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26639 - operand #1 value */
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
/* START_applic26633*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26633 - operand #1 value */
/* START_applic26634*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26634 - operand #1 value */
/* START_applic26635*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26635 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26628*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26628 - operand #1 value */
/* START_applic26629*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26629 - operand #1 value */
/* START_applic26630*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26630 - operand #1 value */
/* START_applic26631*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26631 - operand #1 value */
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
/* START_applic26622*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26622 - operand #1 value */
/* START_applic26623*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26623 - operand #1 value */
/* START_applic26624*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26624 - operand #1 value */
/* START_applic26625*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26625 - operand #1 value */
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
/* START_applic26516*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26516 - operand #1 value */
/* START_applic26521*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26521 - operand #1 value */
/* START_applic26557*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26557 - operand #1 value */
/* START_applic26615*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26615 - operand #1 value */
/* START_applic26616*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26616 - operand #1 value */
/* START_applic26617*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26617 - operand #1 value */
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
/* START_applic26558*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26558 - operand #1 value */
/* START_applic26603*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26603 - operand #1 value */
/* START_applic26612*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26612 - operand #1 value */
/* START_applic26613*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26613 - operand #1 value */
/* START_applic26614*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26614 - operand #1 value */
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
/* START_applic26604*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26604 - operand #1 value */
/* START_applic26609*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26609 - operand #1 value */
/* START_applic26610*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26610 - operand #1 value */
/* START_applic26611*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26611 - operand #1 value */
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
/* START_applic26605*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26605 - operand #1 value */
/* START_applic26606*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26606 - operand #1 value */
/* START_applic26607*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26607 - operand #1 value */
/* START_applic26608*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26608 - operand #1 value */
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
/* START_applic26559*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26559 - operand #1 value */
/* START_applic26596*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26596 - operand #1 value */
/* START_applic26600*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26600 - operand #1 value */
/* START_applic26601*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26601 - operand #1 value */
/* START_applic26602*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26602 - operand #1 value */
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
/* START_applic26597*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26597 - operand #1 value */
/* START_applic26598*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26598 - operand #1 value */
/* START_applic26599*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26599 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26560*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26560 - operand #1 value */
/* START_applic26565*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26565 - operand #1 value */
/* START_applic26579*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26579 - operand #1 value */
/* START_applic26592*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26592 - operand #1 value */
/* START_applic26593*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26593 - operand #1 value */
/* START_applic26594*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26594 - operand #1 value */
/* START_applic26595*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26595 - operand #1 value */
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
/* START_applic26580*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26580 - operand #1 value */
/* START_applic26585*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26585 - operand #1 value */
/* START_applic26589*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26589 - operand #1 value */
/* START_applic26590*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26590 - operand #1 value */
/* START_applic26591*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26591 - operand #1 value */
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
/* START_applic26586*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26586 - operand #1 value */
/* START_applic26587*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26587 - operand #1 value */
/* START_applic26588*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26588 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26581*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26581 - operand #1 value */
/* START_applic26582*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26582 - operand #1 value */
/* START_applic26583*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26583 - operand #1 value */
/* START_applic26584*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26584 - operand #1 value */
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
/* START_applic26566*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26566 - operand #1 value */
/* START_applic26571*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26571 - operand #1 value */
/* START_applic26575*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26575 - operand #1 value */
/* START_applic26576*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26576 - operand #1 value */
/* START_applic26577*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26577 - operand #1 value */
/* START_applic26578*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26578 - operand #1 value */
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
/* START_applic26572*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26572 - operand #1 value */
/* START_applic26573*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26573 - operand #1 value */
/* START_applic26574*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26574 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26567*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26567 - operand #1 value */
/* START_applic26568*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26568 - operand #1 value */
/* START_applic26569*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26569 - operand #1 value */
/* START_applic26570*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26570 - operand #1 value */
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
/* START_applic26561*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26561 - operand #1 value */
/* START_applic26562*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26562 - operand #1 value */
/* START_applic26563*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26563 - operand #1 value */
/* START_applic26564*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26564 - operand #1 value */
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
/* START_applic26522*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26522 - operand #1 value */
/* START_applic26540*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26540 - operand #1 value */
/* START_applic26554*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26554 - operand #1 value */
/* START_applic26555*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26555 - operand #1 value */
/* START_applic26556*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26556 - operand #1 value */
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
/* START_applic26541*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26541 - operand #1 value */
/* START_applic26546*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26546 - operand #1 value */
/* START_applic26550*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26550 - operand #1 value */
/* START_applic26551*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26551 - operand #1 value */
/* START_applic26552*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26552 - operand #1 value */
/* START_applic26553*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26553 - operand #1 value */
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
/* START_applic26547*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26547 - operand #1 value */
/* START_applic26548*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26548 - operand #1 value */
/* START_applic26549*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26549 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26542*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26542 - operand #1 value */
/* START_applic26543*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26543 - operand #1 value */
/* START_applic26544*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26544 - operand #1 value */
/* START_applic26545*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26545 - operand #1 value */
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
/* START_applic26523*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26523 - operand #1 value */
/* START_applic26537*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26537 - operand #1 value */
/* START_applic26538*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26538 - operand #1 value */
/* START_applic26539*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26539 - operand #1 value */
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
/* START_applic26524*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26524 - operand #1 value */
/* START_applic26529*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26529 - operand #1 value */
/* START_applic26533*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26533 - operand #1 value */
/* START_applic26534*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26534 - operand #1 value */
/* START_applic26535*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26535 - operand #1 value */
/* START_applic26536*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26536 - operand #1 value */
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
/* START_applic26530*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26530 - operand #1 value */
/* START_applic26531*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26531 - operand #1 value */
/* START_applic26532*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26532 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26525*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26525 - operand #1 value */
/* START_applic26526*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26526 - operand #1 value */
/* START_applic26527*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26527 - operand #1 value */
/* START_applic26528*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26528 - operand #1 value */
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
/* START_applic26517*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26517 - operand #1 value */
/* START_applic26518*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26518 - operand #1 value */
/* START_applic26519*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26519 - operand #1 value */
/* START_applic26520*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26520 - operand #1 value */
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
/* START_applic26278*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26278 - operand #1 value */
/* START_applic26283*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26283 - operand #1 value */
/* START_applic26413*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26413 - operand #1 value */
/* START_applic26454*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26454 - operand #1 value */
/* START_applic26512*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26512 - operand #1 value */
/* START_applic26513*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26513 - operand #1 value */
/* START_applic26514*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26514 - operand #1 value */
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
/* START_applic26455*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26455 - operand #1 value */
/* START_applic26500*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26500 - operand #1 value */
/* START_applic26509*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26509 - operand #1 value */
/* START_applic26510*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26510 - operand #1 value */
/* START_applic26511*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26511 - operand #1 value */
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
/* START_applic26501*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26501 - operand #1 value */
/* START_applic26506*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26506 - operand #1 value */
/* START_applic26507*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26507 - operand #1 value */
/* START_applic26508*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26508 - operand #1 value */
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
/* START_applic26502*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26502 - operand #1 value */
/* START_applic26503*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26503 - operand #1 value */
/* START_applic26504*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26504 - operand #1 value */
/* START_applic26505*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26505 - operand #1 value */
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
/* START_applic26456*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26456 - operand #1 value */
/* START_applic26493*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26493 - operand #1 value */
/* START_applic26497*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26497 - operand #1 value */
/* START_applic26498*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26498 - operand #1 value */
/* START_applic26499*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26499 - operand #1 value */
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
/* START_applic26494*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26494 - operand #1 value */
/* START_applic26495*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26495 - operand #1 value */
/* START_applic26496*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26496 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26457*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26457 - operand #1 value */
/* START_applic26462*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26462 - operand #1 value */
/* START_applic26476*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26476 - operand #1 value */
/* START_applic26489*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26489 - operand #1 value */
/* START_applic26490*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26490 - operand #1 value */
/* START_applic26491*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26491 - operand #1 value */
/* START_applic26492*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26492 - operand #1 value */
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
/* START_applic26477*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26477 - operand #1 value */
/* START_applic26482*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26482 - operand #1 value */
/* START_applic26486*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26486 - operand #1 value */
/* START_applic26487*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26487 - operand #1 value */
/* START_applic26488*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26488 - operand #1 value */
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
/* START_applic26483*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26483 - operand #1 value */
/* START_applic26484*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26484 - operand #1 value */
/* START_applic26485*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26485 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26478*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26478 - operand #1 value */
/* START_applic26479*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26479 - operand #1 value */
/* START_applic26480*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26480 - operand #1 value */
/* START_applic26481*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26481 - operand #1 value */
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
/* START_applic26463*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26463 - operand #1 value */
/* START_applic26468*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26468 - operand #1 value */
/* START_applic26472*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26472 - operand #1 value */
/* START_applic26473*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26473 - operand #1 value */
/* START_applic26474*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26474 - operand #1 value */
/* START_applic26475*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26475 - operand #1 value */
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
/* START_applic26469*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26469 - operand #1 value */
/* START_applic26470*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26470 - operand #1 value */
/* START_applic26471*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26471 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26464*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26464 - operand #1 value */
/* START_applic26465*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26465 - operand #1 value */
/* START_applic26466*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26466 - operand #1 value */
/* START_applic26467*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26467 - operand #1 value */
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
/* START_applic26458*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26458 - operand #1 value */
/* START_applic26459*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26459 - operand #1 value */
/* START_applic26460*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26460 - operand #1 value */
/* START_applic26461*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26461 - operand #1 value */
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
/* START_applic26414*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26414 - operand #1 value */
/* START_applic26432*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26432 - operand #1 value */
/* START_applic26437*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26437 - operand #1 value */
/* START_applic26451*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26451 - operand #1 value */
/* START_applic26452*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26452 - operand #1 value */
/* START_applic26453*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26453 - operand #1 value */
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
/* START_applic26438*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26438 - operand #1 value */
/* START_applic26443*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26443 - operand #1 value */
/* START_applic26447*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26447 - operand #1 value */
/* START_applic26448*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26448 - operand #1 value */
/* START_applic26449*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26449 - operand #1 value */
/* START_applic26450*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26450 - operand #1 value */
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
/* START_applic26444*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26444 - operand #1 value */
/* START_applic26445*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26445 - operand #1 value */
/* START_applic26446*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26446 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26439*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26439 - operand #1 value */
/* START_applic26440*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26440 - operand #1 value */
/* START_applic26441*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26441 - operand #1 value */
/* START_applic26442*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26442 - operand #1 value */
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
/* START_applic26433*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26433 - operand #1 value */
/* START_applic26434*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26434 - operand #1 value */
/* START_applic26435*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26435 - operand #1 value */
/* START_applic26436*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26436 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26415*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26415 - operand #1 value */
/* START_applic26429*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26429 - operand #1 value */
/* START_applic26430*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26430 - operand #1 value */
/* START_applic26431*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26431 - operand #1 value */
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
/* START_applic26416*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26416 - operand #1 value */
/* START_applic26421*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26421 - operand #1 value */
/* START_applic26425*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26425 - operand #1 value */
/* START_applic26426*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26426 - operand #1 value */
/* START_applic26427*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26427 - operand #1 value */
/* START_applic26428*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26428 - operand #1 value */
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
/* START_applic26422*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26422 - operand #1 value */
/* START_applic26423*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26423 - operand #1 value */
/* START_applic26424*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26424 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26417*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26417 - operand #1 value */
/* START_applic26418*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26418 - operand #1 value */
/* START_applic26419*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26419 - operand #1 value */
/* START_applic26420*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26420 - operand #1 value */
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
/* START_applic26284*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26284 - operand #1 value */
/* START_applic26302*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26302 - operand #1 value */
/* START_applic26356*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26356 - operand #1 value */
/* START_applic26401*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26401 - operand #1 value */
/* START_applic26410*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26410 - operand #1 value */
/* START_applic26411*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26411 - operand #1 value */
/* START_applic26412*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26412 - operand #1 value */
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
/* START_applic26402*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26402 - operand #1 value */
/* START_applic26407*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26407 - operand #1 value */
/* START_applic26408*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26408 - operand #1 value */
/* START_applic26409*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26409 - operand #1 value */
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
/* START_applic26403*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26403 - operand #1 value */
/* START_applic26404*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26404 - operand #1 value */
/* START_applic26405*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26405 - operand #1 value */
/* START_applic26406*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26406 - operand #1 value */
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
/* START_applic26357*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26357 - operand #1 value */
/* START_applic26394*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26394 - operand #1 value */
/* START_applic26398*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26398 - operand #1 value */
/* START_applic26399*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26399 - operand #1 value */
/* START_applic26400*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26400 - operand #1 value */
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
/* START_applic26395*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26395 - operand #1 value */
/* START_applic26396*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26396 - operand #1 value */
/* START_applic26397*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26397 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26358*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26358 - operand #1 value */
/* START_applic26363*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26363 - operand #1 value */
/* START_applic26377*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26377 - operand #1 value */
/* START_applic26390*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26390 - operand #1 value */
/* START_applic26391*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26391 - operand #1 value */
/* START_applic26392*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26392 - operand #1 value */
/* START_applic26393*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26393 - operand #1 value */
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
/* START_applic26378*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26378 - operand #1 value */
/* START_applic26383*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26383 - operand #1 value */
/* START_applic26387*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26387 - operand #1 value */
/* START_applic26388*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26388 - operand #1 value */
/* START_applic26389*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26389 - operand #1 value */
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
/* START_applic26384*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26384 - operand #1 value */
/* START_applic26385*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26385 - operand #1 value */
/* START_applic26386*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26386 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26379*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26379 - operand #1 value */
/* START_applic26380*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26380 - operand #1 value */
/* START_applic26381*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26381 - operand #1 value */
/* START_applic26382*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26382 - operand #1 value */
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
/* START_applic26364*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26364 - operand #1 value */
/* START_applic26369*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26369 - operand #1 value */
/* START_applic26373*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26373 - operand #1 value */
/* START_applic26374*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26374 - operand #1 value */
/* START_applic26375*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26375 - operand #1 value */
/* START_applic26376*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26376 - operand #1 value */
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
/* START_applic26370*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26370 - operand #1 value */
/* START_applic26371*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26371 - operand #1 value */
/* START_applic26372*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26372 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26365*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26365 - operand #1 value */
/* START_applic26366*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26366 - operand #1 value */
/* START_applic26367*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26367 - operand #1 value */
/* START_applic26368*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26368 - operand #1 value */
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
/* START_applic26359*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26359 - operand #1 value */
/* START_applic26360*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26360 - operand #1 value */
/* START_applic26361*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26361 - operand #1 value */
/* START_applic26362*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26362 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26303*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26303 - operand #1 value */
/* START_applic26308*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26308 - operand #1 value */
/* START_applic26312*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26312 - operand #1 value */
/* START_applic26349*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26349 - operand #1 value */
/* START_applic26353*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26353 - operand #1 value */
/* START_applic26354*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26354 - operand #1 value */
/* START_applic26355*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26355 - operand #1 value */
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
/* START_applic26350*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26350 - operand #1 value */
/* START_applic26351*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26351 - operand #1 value */
/* START_applic26352*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26352 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26313*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26313 - operand #1 value */
/* START_applic26318*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26318 - operand #1 value */
/* START_applic26332*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26332 - operand #1 value */
/* START_applic26345*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26345 - operand #1 value */
/* START_applic26346*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26346 - operand #1 value */
/* START_applic26347*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26347 - operand #1 value */
/* START_applic26348*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26348 - operand #1 value */
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
/* START_applic26333*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26333 - operand #1 value */
/* START_applic26338*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26338 - operand #1 value */
/* START_applic26342*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26342 - operand #1 value */
/* START_applic26343*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26343 - operand #1 value */
/* START_applic26344*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26344 - operand #1 value */
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
/* START_applic26339*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26339 - operand #1 value */
/* START_applic26340*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26340 - operand #1 value */
/* START_applic26341*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26341 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26334*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26334 - operand #1 value */
/* START_applic26335*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26335 - operand #1 value */
/* START_applic26336*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26336 - operand #1 value */
/* START_applic26337*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26337 - operand #1 value */
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
/* START_applic26319*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26319 - operand #1 value */
/* START_applic26324*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26324 - operand #1 value */
/* START_applic26328*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26328 - operand #1 value */
/* START_applic26329*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26329 - operand #1 value */
/* START_applic26330*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26330 - operand #1 value */
/* START_applic26331*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26331 - operand #1 value */
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
/* START_applic26325*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26325 - operand #1 value */
/* START_applic26326*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26326 - operand #1 value */
/* START_applic26327*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26327 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26320*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26320 - operand #1 value */
/* START_applic26321*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26321 - operand #1 value */
/* START_applic26322*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26322 - operand #1 value */
/* START_applic26323*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26323 - operand #1 value */
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
/* START_applic26314*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26314 - operand #1 value */
/* START_applic26315*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26315 - operand #1 value */
/* START_applic26316*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26316 - operand #1 value */
/* START_applic26317*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26317 - operand #1 value */
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
/* START_applic26309*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26309 - operand #1 value */
/* START_applic26310*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26310 - operand #1 value */
/* START_applic26311*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26311 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26304*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26304 - operand #1 value */
/* START_applic26305*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26305 - operand #1 value */
/* START_applic26306*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26306 - operand #1 value */
/* START_applic26307*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26307 - operand #1 value */
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
/* START_applic26285*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26285 - operand #1 value */
/* START_applic26299*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26299 - operand #1 value */
/* START_applic26300*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26300 - operand #1 value */
/* START_applic26301*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26301 - operand #1 value */
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
/* START_applic26286*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26286 - operand #1 value */
/* START_applic26291*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26291 - operand #1 value */
/* START_applic26295*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26295 - operand #1 value */
/* START_applic26296*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26296 - operand #1 value */
/* START_applic26297*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26297 - operand #1 value */
/* START_applic26298*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26298 - operand #1 value */
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
/* START_applic26292*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26292 - operand #1 value */
/* START_applic26293*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26293 - operand #1 value */
/* START_applic26294*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26294 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26287*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26287 - operand #1 value */
/* START_applic26288*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26288 - operand #1 value */
/* START_applic26289*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26289 - operand #1 value */
/* START_applic26290*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26290 - operand #1 value */
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
/* START_applic26279*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26279 - operand #1 value */
/* START_applic26280*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26280 - operand #1 value */
/* START_applic26281*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26281 - operand #1 value */
/* START_applic26282*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26282 - operand #1 value */
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
/* START_applic26220*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26220 - operand #1 value */
/* START_applic26265*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26265 - operand #1 value */
/* START_applic26274*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26274 - operand #1 value */
/* START_applic26275*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26275 - operand #1 value */
/* START_applic26276*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26276 - operand #1 value */
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
/* START_applic26266*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26266 - operand #1 value */
/* START_applic26271*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26271 - operand #1 value */
/* START_applic26272*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26272 - operand #1 value */
/* START_applic26273*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26273 - operand #1 value */
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
/* START_applic26267*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26267 - operand #1 value */
/* START_applic26268*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26268 - operand #1 value */
/* START_applic26269*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26269 - operand #1 value */
/* START_applic26270*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26270 - operand #1 value */
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
/* START_applic26221*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26221 - operand #1 value */
/* START_applic26258*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26258 - operand #1 value */
/* START_applic26262*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26262 - operand #1 value */
/* START_applic26263*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26263 - operand #1 value */
/* START_applic26264*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26264 - operand #1 value */
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
/* START_applic26259*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26259 - operand #1 value */
/* START_applic26260*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26260 - operand #1 value */
/* START_applic26261*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26261 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26222*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26222 - operand #1 value */
/* START_applic26227*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26227 - operand #1 value */
/* START_applic26241*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26241 - operand #1 value */
/* START_applic26254*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26254 - operand #1 value */
/* START_applic26255*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26255 - operand #1 value */
/* START_applic26256*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26256 - operand #1 value */
/* START_applic26257*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26257 - operand #1 value */
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
/* START_applic26242*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26242 - operand #1 value */
/* START_applic26247*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26247 - operand #1 value */
/* START_applic26251*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26251 - operand #1 value */
/* START_applic26252*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26252 - operand #1 value */
/* START_applic26253*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26253 - operand #1 value */
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
/* START_applic26248*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26248 - operand #1 value */
/* START_applic26249*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26249 - operand #1 value */
/* START_applic26250*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26250 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26243*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26243 - operand #1 value */
/* START_applic26244*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26244 - operand #1 value */
/* START_applic26245*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26245 - operand #1 value */
/* START_applic26246*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26246 - operand #1 value */
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
/* START_applic26228*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26228 - operand #1 value */
/* START_applic26233*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26233 - operand #1 value */
/* START_applic26237*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26237 - operand #1 value */
/* START_applic26238*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26238 - operand #1 value */
/* START_applic26239*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26239 - operand #1 value */
/* START_applic26240*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26240 - operand #1 value */
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
/* START_applic26234*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26234 - operand #1 value */
/* START_applic26235*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26235 - operand #1 value */
/* START_applic26236*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26236 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26229*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26229 - operand #1 value */
/* START_applic26230*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26230 - operand #1 value */
/* START_applic26231*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26231 - operand #1 value */
/* START_applic26232*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26232 - operand #1 value */
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
/* START_applic26223*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26223 - operand #1 value */
/* START_applic26224*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26224 - operand #1 value */
/* START_applic26225*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26225 - operand #1 value */
/* START_applic26226*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26226 - operand #1 value */
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
/* START_applic26175*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26175 - operand #1 value */
/* START_applic26212*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26212 - operand #1 value */
/* START_applic26216*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26216 - operand #1 value */
/* START_applic26217*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26217 - operand #1 value */
/* START_applic26218*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26218 - operand #1 value */
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
/* START_applic26213*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26213 - operand #1 value */
/* START_applic26214*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26214 - operand #1 value */
/* START_applic26215*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26215 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26176*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26176 - operand #1 value */
/* START_applic26181*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26181 - operand #1 value */
/* START_applic26195*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26195 - operand #1 value */
/* START_applic26208*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26208 - operand #1 value */
/* START_applic26209*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26209 - operand #1 value */
/* START_applic26210*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26210 - operand #1 value */
/* START_applic26211*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26211 - operand #1 value */
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
/* START_applic26196*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26196 - operand #1 value */
/* START_applic26201*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26201 - operand #1 value */
/* START_applic26205*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26205 - operand #1 value */
/* START_applic26206*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26206 - operand #1 value */
/* START_applic26207*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26207 - operand #1 value */
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
/* START_applic26202*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26202 - operand #1 value */
/* START_applic26203*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26203 - operand #1 value */
/* START_applic26204*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26204 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26197*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26197 - operand #1 value */
/* START_applic26198*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26198 - operand #1 value */
/* START_applic26199*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26199 - operand #1 value */
/* START_applic26200*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26200 - operand #1 value */
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
/* START_applic26182*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26182 - operand #1 value */
/* START_applic26187*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26187 - operand #1 value */
/* START_applic26191*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26191 - operand #1 value */
/* START_applic26192*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26192 - operand #1 value */
/* START_applic26193*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26193 - operand #1 value */
/* START_applic26194*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26194 - operand #1 value */
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
/* START_applic26188*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26188 - operand #1 value */
/* START_applic26189*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26189 - operand #1 value */
/* START_applic26190*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26190 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26183*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26183 - operand #1 value */
/* START_applic26184*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26184 - operand #1 value */
/* START_applic26185*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26185 - operand #1 value */
/* START_applic26186*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26186 - operand #1 value */
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
/* START_applic26177*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26177 - operand #1 value */
/* START_applic26178*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26178 - operand #1 value */
/* START_applic26179*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26179 - operand #1 value */
/* START_applic26180*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26180 - operand #1 value */
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
/* START_applic26129*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26129 - operand #1 value */
/* START_applic26166*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26166 - operand #1 value */
/* START_applic26170*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26170 - operand #1 value */
/* START_applic26171*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26171 - operand #1 value */
/* START_applic26172*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26172 - operand #1 value */
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
/* START_applic26167*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26167 - operand #1 value */
/* START_applic26168*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26168 - operand #1 value */
/* START_applic26169*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26169 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26130*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26130 - operand #1 value */
/* START_applic26135*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26135 - operand #1 value */
/* START_applic26149*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26149 - operand #1 value */
/* START_applic26162*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26162 - operand #1 value */
/* START_applic26163*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26163 - operand #1 value */
/* START_applic26164*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26164 - operand #1 value */
/* START_applic26165*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26165 - operand #1 value */
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
/* START_applic26150*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26150 - operand #1 value */
/* START_applic26155*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26155 - operand #1 value */
/* START_applic26159*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26159 - operand #1 value */
/* START_applic26160*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26160 - operand #1 value */
/* START_applic26161*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26161 - operand #1 value */
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
/* START_applic26156*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26156 - operand #1 value */
/* START_applic26157*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26157 - operand #1 value */
/* START_applic26158*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26158 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26151*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26151 - operand #1 value */
/* START_applic26152*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26152 - operand #1 value */
/* START_applic26153*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26153 - operand #1 value */
/* START_applic26154*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26154 - operand #1 value */
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
/* START_applic26136*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26136 - operand #1 value */
/* START_applic26141*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26141 - operand #1 value */
/* START_applic26145*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26145 - operand #1 value */
/* START_applic26146*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26146 - operand #1 value */
/* START_applic26147*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26147 - operand #1 value */
/* START_applic26148*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26148 - operand #1 value */
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
/* START_applic26142*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26142 - operand #1 value */
/* START_applic26143*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26143 - operand #1 value */
/* START_applic26144*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26144 - operand #1 value */
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

/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
/* generate applic's operator code */
/* START_applic26137*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26137 - operand #1 value */
/* START_applic26138*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26138 - operand #1 value */
/* START_applic26139*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26139 - operand #1 value */
/* START_applic26140*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26140 - operand #1 value */
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
/* START_applic26131*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26131 - operand #1 value */
/* START_applic26132*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26132 - operand #1 value */
/* START_applic26133*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26133 - operand #1 value */
/* START_applic26134*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic26134 - operand #1 value */
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
end_lambda_body_26123:
/*Return the FP to the previous place*/
	POP(FP);
RETURN;
end_lambda_body_26122:
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
MOV(R1,126);
/*Save in his value the pointer to the definition result*/
MOV(IND(R1),R0);
/*Return void in R0*/
MOV(R0,T_VOID);
CMP(R0,T_VOID);
JUMP_EQ(next_26120);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_26120:
/* START_applic27003*/
/* backup R1 */PUSH(R1);
/* MAGIC - after the operands */PUSH(IMM(SOB_NIL));

/* pushes the operands to stack */ 
	 /* -------------------- */
/* generating applic27003 - operand #1 value */
MOV(R0,IMM(105));
/*push operand #1 evaluated result*/
PUSH(R0);

 /* -------------------- */

/* pushing number of operands to stack */
PUSH(IMM(1));
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

CMP(R0,T_VOID);
JUMP_EQ(next_27002);
PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));
next_27002:

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
