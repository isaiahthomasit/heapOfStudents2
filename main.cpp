#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "address.h"
#include "date.h"
#include "student.h"

// loadStudents function
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

// printStudents function
void printStudents(std::vector<Student*>& students){
  for (Student* student : students){
    student->printStudent();
    std::cout << "__________________________________" << std::endl;
  }
}

// showStudentNames function
void showStudentNames(std::vector<Student*>& students){
  for (Student* student : students){
    std::cout << student->getLastName() << ", " << student->getFirstName() << std::endl;
  }
}

// findStudent function
void findStudent(std::vector<Student*>& students){
  std::string searchName;
  std::cout << "Enter a last name to search for: ";
  std::cin >>  searchName;

  bool found = false;

  for (Student* student : students){
    if (student->getLastName().find(searchName) != std::string::npos){
      found = true;
      student->printStudent();
      std::cout << std::endl;
    }
  }

  if (found == false){
    std::cout << "No students matching: " << searchName << std::endl; 
  }
}


// main
int main(){
  std::vector<Student*> students;

  loadStudents(students);
  //printStudents(students);
  findStudent(students);

  for (Student* student : students){
    delete student;
  }

  return 0;
}




