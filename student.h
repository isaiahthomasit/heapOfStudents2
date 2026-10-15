// Student header file

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "date.h"
#include "address.h"

class Student{
protected:
  std::string studentString;
  std::string firstName;
  std::string lastName;
  Date* dob;
  Date* expectedGrad;
  Address* address;
  int creditHours;

public:
  Student();
  ~Student();
  void init(std::string studentString);
  void printStudent();

};
  
#endif
  
