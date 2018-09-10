#include <iostream>

using namespace std;

class GenStack
{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  void push(char d);
  char pop();
  char peek();

  bool isFull();
  bool isEmpty();
  int size;
  int top;

  char *myArray;

};
