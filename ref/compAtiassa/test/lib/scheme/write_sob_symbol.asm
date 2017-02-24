/* scheme/write_sob_symbol.asm
 * Take a pointer to a Scheme symbol object, and 
 * prints (to stdout) the character representation
 * of that object.
 * 
 * Programmer: Avichay Kapach, 2015
 */

 WRITE_SOB_SYMBOL:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  MOV(R0, FPARG(0));
  MOV(R1,INDD(R0, 1));
  MOV(R2,INDD(R1,1));
  MOV(R3,IMM(2));
  LOOP_WRITE_SYM_CHAR:
  CMP(R2,IMM(0));
  JUMP_EQ(FINISH_WRITE_SYMBOL);
  PUSH(INDD(R1,R3));
  CALL(PUTCHAR);
  DROP(1);
  INCR(R3);
  DECR(R2);
  JUMP(LOOP_WRITE_SYM_CHAR);
  FINISH_WRITE_SYMBOL:
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;

