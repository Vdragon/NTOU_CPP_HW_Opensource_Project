/* Test_program.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef TEST_PROGRAM_H_
  #define TEST_PROGRAM_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*程式名稱*/
  #define PROGRAM_NAME "作業二測試程式"


  #ifdef __cplusplus
    }
  #endif
#endif /* TEST_PROGRAM_H_ */
