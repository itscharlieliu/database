/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#include "Faculty.h"

using namespace std;

Faculty::Faculty():Person()
{
	level = "";
}

Faculty::Faculty(string n, string l, string d, unsigned int i)
{
	name = n;
	level = l;
	department = d;
	id = i;
}

Faculty::~Faculty()
{

}
