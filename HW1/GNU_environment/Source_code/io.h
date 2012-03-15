#ifndef IO_H_INCLUDED
  #define IO_H_INCLUDED

  /*for Employee data structure definition*/
  #include "main.h"

  /*讀取員工資料的函式
      回傳數值
        -1：檔案開啟失敗*/
  short readFile(Employee data[], unsigned * size);

  /*輸出結果的函式*/
  void displayResult(Employee data[], const unsigned size);


#endif /* IO_H_INCLUDED*/
