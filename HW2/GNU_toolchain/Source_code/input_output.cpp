/*input_output.cpp
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
  input_output.cpp is part of HW2
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
/**/
#include "Operate_resources_helper/Operate_file_CPP.h"
/**/
#include "Graph_abstract_data_type/Graph_abstract_data_type.list.h"
/**/
#include "Messages_templates/zh_TW.h"
/*we need portable getline*/
#include "portableEOLalgorithm/portableEOLalgorithm.h"

/**/
#include <cstdio>
/**/
#include <fstream>
/**/
#include <iostream>
/**/
#include <cassert>
/**/
#include <string>
/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;

  /*讀取檔案到圖中的函式*/
  short readFile2graph(Graph *target)
  {
    /**/
    char filename[FILENAME_MAX];
    /**/
    ifstream input_file;

    /*開啟檔案*/
    askFile(filename);
    if(openFile(filename, "rw", input_file))
    {
      return -1;
    }

    {
      /*read buffer*/
      int read_bufferInt01;
      string read_bufferString;

      /*第1行為點(vertex)數*/
      input_file >> read_bufferInt01;
      if(read_bufferInt01 < 0){
        cerr << ERROR_TAG << "點(vertex)數不可為負數！" << endl;
        return -1;
      }
      portableGetline(input_file, read_bufferString);
#ifndef NDEBUG
      cout << DEBUG_TAG << "vertex=" << read_bufferInt01 << "  " << "comment=" << read_bufferString << endl;
#endif

      /*第2行為邊(edge)數*/
      input_file >> read_bufferInt01;
      if(read_bufferInt01 < 0){
        cerr << ERROR_TAG << "邊(edge)數不可為負數！" << endl;
        return -1;
      }
      portableGetline(input_file, read_bufferString);
#ifndef NDEBUG
      cout << DEBUG_TAG << "edge=" << read_bufferInt01 << "  " << "comment=" << read_bufferString << endl;
#endif
    }



    /**/
    closeFile(filename, input_file);
    /*成功*/
    return 0;
  }
