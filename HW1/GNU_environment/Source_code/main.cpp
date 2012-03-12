/*程式框架(Program Framework)
-----------------------------------
程式名稱(program name)：。
程式描述(program description)：。
程式版本(program version)：0.00(0)
程式框架版本(program framework version)：A
程式框架修訂號(program framework revision number)：201109251624
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
智慧財產授權條款：

*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include的標頭檔(Included Headers)////////*/
#include <iostream>
#include "Sorting_algorithm.h"
#include "Swap_algorithm.h"
#include "Project_specific_configuration/Show_debug_message.h"
#include "Project_specific_configuration/System_category.h"
#include "io.h"
#include "heapsort.h"
#include <stdlib.h>
#include "listDirectoryFiles.h"
#include "main.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/


/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/


/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
int main(void)
  {
    /*分配記憶體給員工資料*/
    Employee * temporary = (Employee *)malloc(sizeof(Employee) * MAX_DATA_SIZE);

    /*員工實際人數*/
    unsigned employee_total = MAX_DATA_SIZE;

    readFile(temporary, &employee_total);


    /*釋放員工資料記憶體*/
    free(temporary);
    return 0;
  }

