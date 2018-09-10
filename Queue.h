/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

//updated for rollback
//added remove back

#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <class T>
class Queue
{
private:
  int size;
  DoublyLinkedList<T> myQueue;

public:
  Queue()
  {
    size = 0;
  };
  ~Queue()
  {

  };

  void insert(T data)
  {
    myQueue.insertBack(data);
    ++size;
  };
  T remove()
  {
    if (getSize() <= 0)
    {
      cout << "unable to remove" << endl;
    }

    T temp = myQueue.front->data;
    myQueue.removeFront();
    --size;
    return temp;
  };
  T removeBack()
  {
    if (getSize() <= 0)
    {
      cout << "unable to remove" << endl;
    }

    T temp = myQueue.back->data;
    myQueue.removeBack();
    --size;
    return temp;
  }

  T peek()
  {
    if (getSize() <= 0)
    {
      cout << "unable to peek" << endl;
    }
    return myQueue.front->data;
  };


  bool isEmpty()
  {
    return (size == 0);
  };

  int getSize()
  {
    return size;
  };
};


#endif
