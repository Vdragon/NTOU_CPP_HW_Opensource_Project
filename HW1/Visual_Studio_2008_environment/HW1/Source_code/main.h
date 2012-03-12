#ifndef MAIN_H_INCLUDED
  #define MAIN_H_INCLUDED
  /*僱員基本資料結構*/
  typedef struct employee{
    /*ID*/
    char id[10];
    /*姓名*/
    char name[40];
    /*每月工作時數*/
    unsigned monthly_working_time;
    /*時薪*/
    unsigned hourly_salary;
  }Employee;



#endif // MAIN_H_INCLUDED
