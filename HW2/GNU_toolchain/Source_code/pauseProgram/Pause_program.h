﻿#ifndef INCLUDED_PAUSE_PROGRAM_H
  #define INCLUDED_PAUSE_PROGRAM_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif

    /* 暫停運行函式的function prototype
     * 呼叫此函式將會將程式暫停並提示使用者是否要重新運行程式
     * （透過需手動新增到程式碼的label (restart_program)）
     * 使用範例列於下方*/
    short int pauseProgram(void);
/*用來重新運行程式的label
restart_program:*/
    /*暫停程式運行（於main函式中）
    if(pauseProgram() == 1){
      goto restart_program;
    }
    */
    /*暫停程式運行（於其他函式）
    if(pauseProgram() == 1){
      goto restart_program;
    }
    else{
      return ;
    }
    */
  #ifdef __cplusplus
    }
  #endif
#endif /* PAUSE_PROGRAM_H_INCLUDED*/
