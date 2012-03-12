#ifndef MAIN_H_INCLUDED
  #define MAIN_H_INCLUDED
  /*僱員基本資料結構*/
  #define MAX_DATA_SIZE 200
  #define MAX_ID_SIZE 11
  #define MAX_NAME_SIZE 41


  typedef struct employee{
    /*ID*/
    char id[MAX_ID_SIZE];
    /*姓名*/
    char name[MAX_NAME_SIZE];
    /*每月工作時數*/
    unsigned monthly_working_hour ;
    /*時薪*/
    unsigned hourly_salary;
  }Employee;



#endif // MAIN_H_INCLUDED
