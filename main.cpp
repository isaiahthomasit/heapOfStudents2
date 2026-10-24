#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "address.h"
#include "date.h"
#include "student.h"

void loadStudents(std::vector<Student*>& students){
  std::ifstream file("students.csv");
  if (!file.is_open()){
    std::cout << "ERROR: students.csv not found" << std::endl; 
  }

  std::string line;

  while (std::getline(file, line)){
    Student* student = new Student();
    student->init(line);
    students.push_back(student);
  }

  file.close();
}

void showStudentNames(std::vector<Student*>& students){
  for (Student* student : students){
    std::cout << student->getLastName() << ", " << student->getFirstName() << std::endl;
  }
}

int main(){
  std::vector<Student*> students;

  loadStudents(students);

  std::cout << "Students loaded: " << students.size() << std::endl;

  showStudentNames(students);
  
  for (Student* student : students){
    delete student;
  }

  students.clear();

    //Address a;
    //a.init("123 W Main St", "Muncie", "IN", "47303");
    //a.printAddress();
    // end testAddress

    //Date d;
    //d.init("01/27/1997");
    //d.printDate();
    // end testDate

    //Student r;
    //r.init("Ava,Nguyen,12 Oak St,Springfield,IL,62701,01/15/2006,06/01/2024,24");
    //r.printStudent();
    // end testStudent

    return 0;
}
