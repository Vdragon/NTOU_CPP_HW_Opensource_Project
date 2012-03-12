#include <iostream>
#include <fstream>
#include "listDirectoryFiles.h"
#define MAX_FILE_NAME_SIZE 30
#include "main.h"
#include <assert.h>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
short readFile(Employee data[], unsigned * size)
{
  /*file name buffer*/
  char filename[MAX_FILE_NAME_SIZE];

  ifstream inputFile;

  /*unsigned dataTotal;*/

  /*counter*/
  unsigned i;

  string readBuffer;

  /***開啟檔案階段***/
  listDirectoryFiles();

  cout << "目前的工作目錄所包含的檔案如上，請輸入要讀取的資料檔案名稱：";
  cin.getline(filename, MAX_FILE_NAME_SIZE);

  /*FILE * filePtr = fopen(filename, "r");*/
  inputFile.open(filename, ifstream::in);

  /*預期檔案開啟成功*/
  assert(inputFile.is_open());
  if(!inputFile.is_open()){
    return -1;
  }

  /***讀取檔案階段***/
  /*1.總資料筆數*/
  inputFile >> *size;

  inputFile.ignore(2);
  /*2.員工資料*/
  for(i = 0; i < *size; ++i){
    /*2-1 ID*/
    inputFile >> data[i].id;

    /*2-2 name*/
    /*inputFile >> data[i].name;*/
    getline(inputFile, readBuffer);
    strcpy(data[i].name, readBuffer.c_str());

    /*2-3 working hour*/
    inputFile >> data[i].monthly_working_time;

    /*2-4 hourly salary*/
    inputFile >> data[i].hourly_salary;

    /*#ifdef DEBUG*/
    cout << data[i].id << endl
         << data[i].name << endl
         << data[i].monthly_working_time << endl
         << data[i].hourly_salary << endl << endl;
    /*#endif*/
  }

  /***關閉檔案階段***/
  /*fclose(filePtr);*/
  inputFile.close();


  return 0;
}
