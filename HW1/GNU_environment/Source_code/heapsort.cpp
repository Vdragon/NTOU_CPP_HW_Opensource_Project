
short compareMonthPay(Employee person1, Employee person2)
{
  if(calcMonthPay(person1) > calcMonthPay(person2)){
     return 1;
  }
  else if(calcMonthPay(person1) < calcMonthPay(person2)){
    return -1;
  }
  return 0;
}

inline unsigned calcMonthPay(Employee person)
{
  return person.monthly_working_hour  * person.hourly_salary;
}
