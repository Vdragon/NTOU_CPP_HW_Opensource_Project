/*
 * calculation.h
 *
 *  Created on: 2012/3/13
 *      Author: vdragon
 */

#ifndef CALCULATION_H_
  #define CALCULATION_H_
  #ifdef __cplusplus
    extern "C"{
  #endif

  /*計算月薪的函式
      person 員工structure
      return 員工的月薪*/
  unsigned calcMonthPay(Employee person);
    #ifdef __cplusplus
      }
    #endif
#endif /* CALCULATION_H_ */
