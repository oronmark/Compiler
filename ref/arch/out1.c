
    #include <stdio.h>
    #include <stdlib.h>
    
    /* change to 0 for no debug info to be printed: */
    #define DO_SHOW 1
    
    #include "cisc.h"
    
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

PUSH(IMM(10));
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));

/*-------------const table-------------*/

MOV(R0,IMM(1));

PUSH(R0);
CALL(WRITE_SOB);
DROP(IMM(1));

CALL(NEWLINE);
STOP_MACHINE;

return 0;
}