/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#include "Person.h"

using namespace std;

Person::Person()
{
  name = "";
  id = 0;
  level = "";
}

Person::~Person()
{

}

bool Person::operator==(const Person& s)
{
  if(s.id == id)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool Person::operator==(const int s)
{
  if(s == id)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool Person::operator!=(const Person& s)
{
  if(s.id != id)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool Person::operator<(const Person& s)
{
  if(s.id > id)
  {
    return true;
  }

  else
  {
    return false;
  }
}
bool Person::operator>(const Person& s)
{
  if(s.id < id)
  {
    return true;
  }

  else
  {
    return false;
  }
}
