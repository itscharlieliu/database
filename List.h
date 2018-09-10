/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

//doubly linked list

#ifndef LIST_H
#define LIST_H



#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class List
{
public:
virtual void insertFront(T data) = 0;
virtual void insertBack(T data) = 0;
virtual bool removeFront()=0;
virtual T removeBack()=0;
virtual bool contains(T value) = 0;
virtual bool remove(T key) = 0;
virtual unsigned int getSize() = 0;
virtual bool isEmpty() = 0;
};

template <class T>
class DoublyLinkedList: public List<T>
{
private:

	ListNode<T> *back;
	unsigned int size;

public:
	ListNode<T> *front;
  DoublyLinkedList()
  {


  	size = 0;
  	front = NULL;
  	back = NULL;
  };
  ~DoublyLinkedList()
  {



  };

	void insertFront(T data)
  {
  	ListNode<T> *node = new ListNode<T> (data);

  	if(isEmpty()) //empty ListNode
  	{
  		back = node;
  	}
  	else //not empty
  	{
  		front ->prev = node;
  		node-> next = front;
  	}
  	front = node;
  	size++;

  };

	void insertBack(T data)
  {
  	ListNode<T> *node = new ListNode<T> (data);

  	if(isEmpty())
  		front = node;
  	else
  	{
  		back->next = node;
  		node->prev = back;
  	}

  	back = node;
  	size++;

  };
	bool removeFront()
  {


  	ListNode<T> *node = front;
		if (front == NULL)
		{

				T temp;
				return false;
		}
  	if (front ->next == NULL)
  	{

  		back = NULL;
  	}
  	else
  	{

  		front -> next -> prev = NULL;
  	}

  	front = front -> next;
  	--size;
  	node -> next = NULL;
  	T temp = node -> data;
  	delete node;

  	return true;
  };
	T removeBack()
  {
    ListNode<T> *node = back;
  	if (front ->next == NULL)
  	{
  		back = NULL;
  	}
  	else
  	{
  		back -> prev -> next = NULL;
  	}

  	back = back -> prev;

  	node -> prev = NULL;
  	T temp = node -> data;
  	delete node;
		--size;
  	return temp;
  };

  bool contains(T value)
  {
    ListNode<T>* curr;
		cout << front->data << endl;
		curr = front;
    while (curr != NULL)
    {
      if (curr->data == value)
      {
        return true;
      }
    }
    return false;
  }

	bool remove (T key)
  {
  	ListNode<T> *curr;
		curr = front;

  	while (curr->data != key)
  	{

  		if (curr == NULL)
  		{
  			return false;
  		}
			curr = curr -> next;
  	}


  	//found it, now let's delte it
  	if (curr == front)
  	{
  		front = curr -> next;
  	}
  	else
  	{
  		curr ->prev->next = curr ->next;
  	}
  	if (curr == back)
  	{
  		back = curr -> prev;
  	}
  	else
  	{
  		curr ->next->prev = curr ->prev;
  	}

  	 curr -> next = NULL;
  	 curr ->prev = NULL;
  	 --size;

  	 delete curr;
  	 return true;
  };

  void printList()
  {
  	ListNode<T> *curr = front;
  	while (curr !=NULL)
  		{
  			cout << curr->data <<endl;
  			curr = curr->next;
  		}
  };

	int find(T value)
  {
  	int idx = -1;
  	ListNode<T> *current = front;
  	while(current!=NULL)
  	{
  		++idx;
  		if(current->data == value)
  		{
  			break;
  		}
  		else
  		{
  			current = current -> next;
  		}
  	}
  	if (current == NULL){
  		idx = -1;
  	}

  	return idx;
  };
	unsigned int getSize()
  {
    return size;
  };
	bool isEmpty()
  {
    if (size <= 0)
    {
      return true;
    }
    return false;
  };
};





#endif
