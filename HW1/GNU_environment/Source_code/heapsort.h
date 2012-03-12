#ifndef HEAPSORT_H_INCLUDED
  #define HEAPSORT_H_INCLUDED

  /*compareMonthPay function
      compare and return selection to heapsort function
    parameters:
      person1, person2 - person to compare
    return value:
      if 1 > 2 -> 1
      if 1 = 2 -> 0
      if 1 < 2 -> -1*/
  short compareMonthPay(Employee person1, Employee person2);

  /*計算月薪的函式
      person 員工structure
      return 員工的月薪*/
  inline unsigned calcMonthPay(Employee person);

#endif // HEAPSORT_H_INCLUDED
