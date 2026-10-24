#include "student.h"
#include <iostream>
#include <sstream>
#include <string>

Student::Student(){
  dob = nullptr;
  expectedGrad = nullptr;
  address = nullptr;

}

void Student::init(std::string studentString){
  std::stringstream ss(studentString);

  // student name

  std::getline(ss, firstName, ',');
  std::getline(ss, lastName, ',');

  // address

  std::string street;
  std::string city;
  std::string state;
  std::string zip;

  std::getline(ss, street, ',');
  std::getline(ss, city, ',');
  std::getline(ss, state, ',');
  std::getline(ss, zip, ',');

  address = new Address();
  address->init(street, city, state, zip);

  // date
  
  std::string dobString;
  std::string gradString;
  
  std::getline(ss, dobString, ',');
  std::getline(ss, gradString, ',');

  dob = new Date();
  dob->init(dobString);

  expectedGrad = new Date();
  expectedGrad->init(gradString);

  std::string creditString;
  std::getline(ss, creditString);

  std::stringstream convert(creditString);
  convert >> creditHours;

}

// deconstructer

Student::~Student(){
  delete dob;
  delete expectedGrad;
  delete address;

}

void Student::printStudent(){
  std::cout << firstName << " " << lastName << std::endl;

  address->printAddress();
  std::cout << std::endl;

  dob->printDate();
  expectedGrad->printDate();

  std::cout << "Credits: " << creditHours << std::endl;

}

std::string Student::getFirstName(){
  return firstName;
}

std::string Student::getLastName(){
  return lastName;
}
