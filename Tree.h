/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/


#ifndef TREE_H
#define TREE_H


#include "TreeNode.h"
#include <sstream>

using namespace std;

template <class T>
class BST
{
private:
  TreeNode<T> *root;
  unsigned int size;

  void deleteAll(TreeNode<T> *node)
  {
    if (node == NULL)
    {

    }

    else if (node->left != NULL)
    {
      deleteAll(node->left);
    }
    else if (node->right != NULL)
    {
      deleteAll(node->right);
    }
    else
    {
      deleteNode(node->key);
    }
    root = NULL;
  };

  TreeNode<T>* getRoot()
  {
    return root;
  }

  int AddToArray(TreeNode<T> *node, TreeNode<T>* arr[], int i) // Used to add faculty table to an array and choosing a random advisor https://stackoverflow.com/questions/29582431/convert-binary-tree-to-array-in-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
  {
       if(node == NULL)
            return i;


       arr[i] = node;
       i++;
       if(node->left != NULL)
            i = AddToArray(node->left, arr, i);
       if(node->right != NULL)
            i = AddToArray(node->right, arr, i);

       return i;
  }

public:
  BST()
  {
    root = NULL;
  };
  ~BST()
  {
    deleteAll(root);
  };

  void deleteAll()
  {
    deleteAll(root);
  }

  void insert(T k)
  {
    TreeNode<T> *node = new TreeNode<T>(k);

    if(root == NULL) //empty tree
    {
      root = node;
      ++size;
    }
    else //non empty tree
    {

      TreeNode<T> *curr = root;
      TreeNode<T> *parent = NULL;

      //traverse and compare
      while(true)
      {

        parent = curr;
        if(k < curr->key)
        {

          curr = curr->left;

          if (curr == NULL) //foudnt the insertion point
          {
          parent->left = node;
          ++size;
          break;
          }
        }
        else if(k > curr->key) //go right
        {
          curr = curr->right;

          if (curr == NULL) //foudnt the insertion point
          {
          parent->right = node;
          ++size;
          break;
          }
        }
        else //key already exists
        {
          break;
        }
      }
    }
  };
  bool contains(T k)
  {
    if (root == NULL)
    {
      return false;
    }
    TreeNode<T> *curr = root;
    while(curr->key != k)
    {
      if(k < curr->key)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
      if (curr == NULL)
      {
        return false;
      }
    }
    return true;
  };
  bool deleteNode(T k)
  {
    if (root == NULL) // empty tree
    {
      return false;
    }

    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    //let's look for node to be delete

    while(curr->key != k)
    {
      parent = curr;
      if (k < curr->key)
      {
        //cout << "Left" << endl;
        isLeft = true;
        curr = curr->left;
      }
      else
      {
        //cout << "Right" << endl;
        isLeft = false;
        curr = curr->right;
      }
      if (curr == NULL) //value does not exist
      {
        return false;
      }
    }
    //no children, easiest case
    if(curr->left == NULL && curr->right == NULL)
    {
      //cout << "No children" << endl;
      if(curr == root)
      {
        root = NULL;
      }
      else if(isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
      delete curr;
      --size;
    }
    //one child
    //no right child
    else if(curr->right == NULL)
    {
      if(curr == root)
      {
        root = curr->left;
      }
      else if(isLeft)
      {
        parent->left = curr->left;
      }
      else
      {
        parent->right = curr->left;
      }
      delete curr;
      --size;
    }
    //no Left child
    else if(curr->left == NULL)
    {
      if(curr == root)
      {
        root = curr->right;
      }
      else if(isLeft)
      {
        parent->left = curr->right;
      }
      else
      {
        parent->right = curr->right;
      }
      delete curr;
      --size;
    }
    else //node to be deleted has two children
    {
      //cout << "Two children" << endl;
      TreeNode<T> *successor = getSuccessor(curr);

      if(curr == root)
      {
      //  cout << "root = successor" << endl;
        root == successor;
      }
      else if(isLeft)
      {
        parent->left = successor;
      }
      else
      {
      //  cout << "is right" << endl;
        parent->right = successor;
      }
      successor->left = curr->left;
      delete curr;
      --size;
    }
    return true;
  };


  TreeNode<T> *getMin()
  {
    //todo
    TreeNode<T> *curr = root;

    if(root == NULL)
    {
      return NULL;
    }

    while(curr->left != NULL)
    {
      curr = curr -> left;
    }

    return curr;
  };
  TreeNode<T> *getMax()
  {
    TreeNode<T> *curr = root;

    if(root == NULL)
    {
      return NULL;
    }

    while(curr->right != NULL)
    {
      curr = curr -> right;
    }

    return curr;
  };

  bool isEmpty()
  {
    return (size == 0);
  }
  int getSize()
  {
    return size;
  }



  string printTree(int traversalType)//1. inOrder 2. preOrder 3. postOrder
  {
    return printTree(root, traversalType);
  };


  string printTree(TreeNode <T>*node, int traversalType)
  {
    ostringstream output;
    switch (traversalType)
    {
      case 1://inOrder
      {
        if (node == NULL)
        {
          return output.str();
        }
        output << printTree(node->left, traversalType);
        output << node->key << endl;
        output << printTree(node->right, traversalType);
        break;
      }
      case 2://preOrder
      {
        if (node == NULL)
        {
          return output.str();
        }
        output << node->key << endl;
        output << printTree(node->left, traversalType);
        output << printTree(node->right, traversalType);
        break;
      }
      case 3://postOrder
      {
        if (node == NULL)
        {
          return output.str();
        }
        output << printTree(node->left, traversalType);
        output << printTree(node->right, traversalType);
        output << node->key << endl;
        break;
      }
    }
    return output.str();
  }

  //for cout the whole tree and/or printing tree to file
  friend ostream &operator<<(ostream &os, const BST<T> &t)
  {
    os << t.root;
    return os;
  }

  TreeNode <T>*getSuccessor(TreeNode <T>*d) // d represents the node that we are going to deleted
  {
    TreeNode <T> *sp = d; // successor parents
    TreeNode <T> *successor = d; // should be one right, all the way Left
    TreeNode <T> *curr = d->right;

    while(curr != NULL)
    {
      sp = successor;
      successor = curr;
      curr = curr->left;
    }

    if(successor != d->right) //not the right child of d
    {
      sp->left = successor->right;
      successor->right = d->right;
    }

    return successor;
  };

  TreeNode <T> *getKey(unsigned int idx) //get a node from the tree as if it was an array
  {
    TreeNode<T> **arr = new TreeNode<T>*[getSize()];
    AddToArray(root, arr, 0);


    return arr[idx];
  }

  TreeNode<T> *find(T k)
  {
    if (root == NULL)
    {
      return NULL;
    }
    TreeNode<T> *curr = root;
    while(curr->key != k)
    {
      if(k < curr->key)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
      if (curr == NULL)
      {
        return NULL;
      }
    }
    return curr;
  }

};

















#endif
