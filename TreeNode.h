/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

template <class T>
class TreeNode
{
public:
  TreeNode()
  {
    key = NULL;
    left = NULL;
    right = NULL;
  };
  TreeNode(T k)
  {
    key = k;
    left = NULL;
    right = NULL;
  };
  ~TreeNode()
  {

  };

  T key;
  TreeNode *left;
  TreeNode *right;
};



#endif
