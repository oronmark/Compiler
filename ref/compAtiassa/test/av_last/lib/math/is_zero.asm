/* is_zero.asm
 * R0 <- 1, 0 -- depending on whether ARG[0] is zero
 *
 * Programmer: Mayer Goldberg, 2010
 */

 IS_ZERO:
  PUSH(FP);
  MOV(FP,SP);
  CMP(FPARG(1),IMM(1));
  JUMP_NE(ARGS_FAULT);
  
  MOV(R1,FPARG(2));
  
  CMP(IND(R1),IMM(T_INTEGER));
  JUMP_NE(NOT_INTEGER_ERROR);
  
  CMP(INDD(R1,1), IMM(0));
  JUMP_NE(L_IS_ZERO_F);
  
  
  MOV(R0, IMM(5));
  JUMP(END_IS_ZERO);
 L_IS_ZERO_F:
  MOV(R0, IMM(3));
  
 END_IS_ZERO:
  POP(FP);
  RETURN;
