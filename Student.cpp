/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#include "Student.h"



Student::Student():Person()
{
  major = "";
  gpa = 0;
  advisor = 0;
}

Student::Student(string n, string g, string m, double gr, unsigned int i):Person()
{
  name = n;
  level = g;
  major = m;
  gpa = gr;
  id = i;
  advisor = 0;
}

Student::~Student()
{

}
