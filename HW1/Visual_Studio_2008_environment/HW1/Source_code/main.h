#ifndef MAIN_H_INCLUDED
  #define MAIN_H_INCLUDED

  /* max data size to store*/
  #define MAX_DATA_SIZE 200
  /*max ID size, 9 characters + null character*/
  #define MAX_ID_SIZE 10
  /*max name size, 40 characters + null character*/
  #define MAX_NAME_SIZE 41
  /*employee資料結構*/
  typedef struct employee{
    /*ID*/
    char id[MAX_ID_SIZE];
    /*姓名*/
    char name[MAX_NAME_SIZE];
    /*每月工作時數*/
    unsigned monthly_working_hour;
    /*時薪*/
    unsigned hourly_salary;
  }Employee;

#endif /* MAIN_H_INCLUDED*/
