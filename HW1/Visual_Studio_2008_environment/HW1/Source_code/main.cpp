/*main.cpp
-----------------------------------
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
著作權宣告：
  Copyright 2012 林博仁(Henry Lin)
智慧財產授權條款：
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/
/*We need to show debug messages*/
#include "Project_specific_configuration/Show_debug_message.h"

/*OS specific settings*/
#include "Project_specific_configuration/System_category.h"

/*////////程式所include的標頭檔(Included Headers)////////*/
/*we need cout cin...*/
#include <iostream>

/*we need malloc free...
    TODO: switch to C++ counterparts*/
#include <cstdlib>

/*some project scope declarations*/
#include "main.h"

/*functions about input/output */
#include "io.h"

/*funcitons to pause the program*/
#include "pauseProgram/Pause_program.h"

/* functions to sort */
#include "Sorting_algorithm/Heap_sort.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
int main()
  {

    /*員工實際人數*/
    unsigned employee_total = MAX_DATA_SIZE;

    unsigned temp_total;


  /*pause program label*/
  restart_program:

    /*分配記憶體給員工資料*/
    Employee * temporary = (Employee *)malloc(sizeof(Employee) * MAX_DATA_SIZE);

    /*read file*/
    if(readFile(temporary, &employee_total) != 0){
      /*error msg*/
      cout << "資料檔案讀取失敗！程式異常終止…" << endl;

      /*fail exit*/
      if(pauseProgram() == 1){
        goto restart_program;
      }else{
        return -1;
      }
    }

    /* we will modify it later, so backup */
    temp_total = employee_total;

    /*sort data*/
    heapSortEmployee(temporary, &temp_total);

    /*顯示結果*/
    displayResult(temporary, employee_total);

    /*釋放員工資料記憶體*/
    free(temporary);

    /*pause program*/
    if(pauseProgram() == 1){
      goto restart_program;
    }

    /*exit*/
    return 0;
  }

