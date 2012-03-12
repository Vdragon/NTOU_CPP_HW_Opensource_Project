#ifndef IO_H_INCLUDED
  #define IO_H_INCLUDED
  #include "main.h"

  /*讀取員工資料的函式
      回傳數值
        -1：檔案開啟失敗
  */
  short readFile(Employee data[], unsigned * size);


#endif /* IO_H_INCLUDED*/
