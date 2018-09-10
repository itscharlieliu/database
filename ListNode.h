#include <typeinfo>
/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <class T>
class ListNode
{


public:
  ListNode *next;
  ListNode *prev;
  T data;

  ListNode()
  {
    next = NULL;
    prev = NULL;


  };
  ListNode(T d)
  {
    ListNode();
    data = d;
  };
  ~ListNode()
  {


    next = NULL;

    prev = NULL;




  };




};




#endif
