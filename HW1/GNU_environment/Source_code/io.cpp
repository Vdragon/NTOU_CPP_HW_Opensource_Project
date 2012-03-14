/*io.cpp
-----------------------------------
更新紀錄(changelog)：
  Changelog is now stored on GitHub
已知問題(known issues)：
  Known issues is now stored on GitHub
待辦事項(todo)：
  Todo is now stored on GitHub
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
#include "Project_specific_configuration/Show_debug_message.h"

/*////////程式所include的標頭檔(Included Headers)////////*/
/*for basic input output*/
#include <iostream>

/*for file management*/
#include <fstream>

/*for string object*/
#include <string>

/*we need c string manipulation functions*/
#include <cstring>

/*we need atoi() to parse number in c string*/
#include <cstdlib>

/*for assertion support*/
#include <cassert>

/* for Employee data structure*/
#include "main.h"

/* we need listDirectory functions*/
#include "List_directory_files/listDirectoryFiles.h"

/*we need salary calculation function*/
#include "calculation.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/
/*max size for storing file name*/
#define MAX_FILE_NAME_SIZE 30

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
short readFile(Employee data[], unsigned * size)
{
  /*file name buffer*/
  char filename[MAX_FILE_NAME_SIZE];

  /*a file opject to read file*/
  ifstream inputFile;

  /*counter*/
  unsigned i;

  /* unsigned to temporary hold string length */
  unsigned string_length;

  /*a string object to store string*/
  string readBuffer;

  /***開啟檔案階段***/
  listDirectoryFiles();
  cout << "目前的工作目錄所包含的檔案如上所示，請輸入要讀取的資料檔案名稱：";
  cin.getline(filename, MAX_FILE_NAME_SIZE);
  inputFile.open(filename, ifstream::in);
  /*預期檔案開啟成功*/
  if(!inputFile.is_open()){
    cout << "檔案開啟失敗！請確認您輸入的檔案名稱是否正確，或是您是否有權限存取此檔案。" << endl;

    /*fail, leave*/
    return -1;
  }

  /***讀取檔案階段***/
  /*1.總資料筆數*/
  /*inputFile >> *size;*/
  /*inputFile.ignore(2);*/
  /*We need to eat the END OF LINE character sequence from the stream, so we
    have to find a *more* portable way...*/
  getline(inputFile, readBuffer);
  *size = atoi(readBuffer.c_str());

  #ifdef DEBUG
    cout << "[DEBUG] Total data detected are " << *size << " items" << endl;
  #endif

  /*2.員工資料*/
  for(i = 0; i < *size; ++i){
    /*2-1 ID*/
    getline(inputFile, readBuffer);
    #ifdef DEBUG
      cout << "[DEBUG] id c_str size=" << strlen(readBuffer.c_str()) << endl;
    #endif
    strncpy(data[i].id, readBuffer.c_str(), MAX_ID_SIZE - 1);
    /*Avoid readBuffer terminates after max id size, cut it manually*/
    data[i].id[MAX_ID_SIZE - 1] = '\0';

    /*2-2 name*/
    getline(inputFile, readBuffer);
    #ifdef DEBUG
      cout << "[DEBUG] name c_str size=" << strlen(readBuffer.c_str()) << endl;
    #endif
    strncpy(data[i].name, readBuffer.c_str(), MAX_NAME_SIZE - 1);
    /*data[i].name[MAX_NAME_SIZE - 1] = '\0';*/
    /*去掉Windows平台會殘留的換行字元序列\r*/
    string_length = strlen(readBuffer.c_str());
    if(data[i].name[string_length - 1] == '\r'){
      data[i].name[string_length - 1] = '\0';
    }else{
      data[i].name[string_length] = '\0';
    }

    /*2-3 working hour*/
    getline(inputFile, readBuffer);
    data[i].monthly_working_hour = atoi(readBuffer.c_str());
    /*working hour shouldn't be negative*/
    assert(data[i].monthly_working_hour >= 0);

    /*2-4 hourly salary*/
    getline(inputFile, readBuffer);
    data[i].hourly_salary = atoi(readBuffer.c_str());

    #ifdef DEBUG
      cout << "[DEBUG] data #" << i << endl;
      cout << "[DEBUG] ID=" << data[i].id << endl;
      cout << "[DEBUG] NAME=" << data[i].name << endl;
      cout << "[DEBUG] Working hour=" << data[i].monthly_working_hour << endl;
      cout << "[DEBUG] Salary=" << data[i].hourly_salary << endl << endl;
    #endif
  }

  /***關閉檔案階段***/
  /*fclose(filePtr);*/
  inputFile.close();

  /*read successfully*/
  return 0;
}

void displayResult(Employee data[], const unsigned size)
{
  /*counter*/
  unsigned i;

  /*total*/
  unsigned sum_buffer = 0;

  #ifdef DEBUG
    cout << "[DEBUG] ";
    for(i = 0; i < size; i++){
      cout << calcMonthPay(data[i]) << "  ";
    }cout << endl;
  #endif

  /*show result*/
  cout << "月薪前5名的平均值：";
  /*加總前5名*/
  for(i = 0; i < 5; i++){
    sum_buffer += calcMonthPay(data[size - 1 - i]);
  }/*取平均值*/
  cout << sum_buffer / (double)5 << endl;

  /*reset sum*/
  sum_buffer = 0;

  cout << "月薪後5名的平均值：";
  /*加總前5名*/
  for(i = 0; i < 5; i++){
    sum_buffer += calcMonthPay(data[i]);
  }/*取平均值*/
  cout << sum_buffer / (double)5 << endl;

  /*顯示倒數第二薪資的員工資料*/
  cout << "薪水排名倒數第二名的僱員資料" << endl
       << "　　姓名：" << data[1].name << endl
       << "　　ID：" << data[1].id << endl;

  /*done*/
  return;
}
