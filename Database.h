/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#ifndef DATABASE_H
#define DATABASE_H

#include "Tree.h"
#include "Student.h"
#include "Faculty.h"
#include "Queue.h"



class Database
{
private:
  BST<Student> studentTable;
  BST<Faculty> facultyTable;

  int currentSave;

  unsigned int assignID(string type);

  void printOptions();
  bool run(int userInput);
  TreeNode <Faculty> *assignAdvisor();


public:
  Database();
  ~Database();


  bool addStudent(string name, string level, string major, double gpa);
  bool addFaculty(string name, string level, string department);

  bool printStudents(unsigned int id);
  bool printFaculty(unsigned int id);

  Student *findStudent();
  Faculty *findFaculty();

  bool deleteStudent(unsigned int id);
  bool deleteFaculty(unsigned int id);

  bool printAdvisor(unsigned int id);
  bool printAdvisees(unsigned int id);

  bool changeAdvisor(unsigned int studentId, unsigned int facultyId);
  bool removeAdvisee(unsigned int studentId, unsigned int facultyId);

  bool rollBack();


  bool saveToFile(string fileName);
  bool loadFromFile(string fileName);



};



#endif
