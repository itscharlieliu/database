/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <sstream>
using namespace std;

class Person
{
public:
  string name;
  unsigned int id;
  string level;

  Person();
  ~Person();

  bool operator==(const Person& s);
  bool operator==(const int s);
  bool operator!=(const Person& s);
  bool operator<(const Person& s);
  bool operator>(const Person& s);

  operator string()
  {
    stringstream ss;
    ss << id;
    return ss.str();

  };

};

inline ostream &operator<<(ostream &os, const Person &p)
{
  os << p.id;
  return os;
}


#endif
