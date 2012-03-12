#include <iostream>
#include <fstream>
#include <assert.h>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Project_specific_configuration/Show_debug_message.h"
#include "main.h"
#include "listDirectoryFiles.h"

#define MAX_FILE_NAME_SIZE 30

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
    strncpy(data[i].id, readBuffer.c_str(), MAX_ID_SIZE - 1);
    /*Avoid readBuffer terminates after max id size, cut it manually*/
    data[i].id[MAX_ID_SIZE - 1] = '\0';

    /*2-2 name*/
    getline(inputFile, readBuffer);
    strncpy(data[i].name, readBuffer.c_str(), MAX_NAME_SIZE - 1);
    data[i].name[MAX_NAME_SIZE - 1] = '\0';

    /*2-3 working hour*/
    getline(inputFile, readBuffer);
    data[i].monthly_working_hour = atoi(readBuffer.c_str());

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
