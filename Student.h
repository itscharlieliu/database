/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person
{
public:

  string major;
  double gpa;
  unsigned int advisor;

  Student();
  Student(string name, string grade, string major, double gpa, unsigned int id);
  ~Student();

  operator string()
  {
    stringstream ss;
    ss << id << "|" << name << "|" << level << "|" << major << "|" << gpa << "|" << advisor;
    return ss.str();

  };


};

inline ostream &operator<<(ostream &os, const Student &p)
{
  os << p.id << "|" << p.name << "|" << p.level << "|" << p.major << "|" << p.gpa << "|" << p.advisor;
  return os;
}


#endif
