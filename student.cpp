#include "student.h"
#include <iostream>
#include <sstream>
#include <string>

Student::Student(){
  dob = nullptr;
  expectedGrad = nullptr;
  address = nullptr;

}

Student::init(std::string studentString){
  std::sstringsstream ss(studentString);
  std::getline(ss,firstName, ',');
  std::getline(ss,lastName, ',');

