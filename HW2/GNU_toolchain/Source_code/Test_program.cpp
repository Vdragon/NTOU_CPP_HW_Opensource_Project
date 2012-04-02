/*Test_program.cpp
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
  Test_program.cpp is part of HW2
  HW2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  HW2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with HW2.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要可移植的結束狀態碼*/
#include <cstdlib>
/*我們需要C++的console輸出 */
#include <iostream>

/*我們需要顯示軟體訊息*/
#include "Show_software_info/Show_software_info.h"
/*我們需要暫停程式*/
#include "pauseProgram/Pause_program.h"
/*Graph ADT定義*/
#include "Graph_abstract_data_type/Graph_abstract_data_type.list.h"
/**/
#include "Messages_templates/zh_TW.h"

/*我們需要程式訊息*/
#include "Test_program.h"
/**/
#include "input_output.h"

/*////////常數與巨集(Constants & Macros)////////*/
/**/
/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
int main()
{
  /**/
  Graph graph01;

  /*用來重新運行程式的label*/
  restart_program:

  /*顯示軟體訊息*/
  show_software_info((char*)PROGRAM_NAME);

  /*讀取資料檔案*/
  if(readFile2graph(&graph01)){
    cerr << ERROR_TAG << "讀取資料檔案失敗！程式無法繼續運行。" << endl
         << ERROR_TAG << "請檢查資料檔案是否正確！" << endl;
    goto end_program;
  }


  end_program:
  /*暫停程式運行（於main函式中）*/
  if(pauseProgram() == 1){
    goto restart_program;
  }
  /*正常結束*/
  return EXIT_SUCCESS;
}
