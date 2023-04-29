#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class LinkedList {
 private:
  Node* head;

  // get and search exist, so not used outside of LinkedList 
  Node* traverse(int pos);
 public:
  // constructors
  LinkedList();
  LinkedList(int* array, int len);

  // methods

  // insert new node at pos with data newNum
  void insertPosition(int pos, int newNum);
  // change link of Node[pos-1] to pos+1
  bool deletePosition(int pos);
  // return Node->getData()
  int get(int pos);
  // search for first instance of Node->getData() == target and return pos, else return -1
  int search(int target);
  void printList();

  //destructor
  ~LinkedList();
};
#endif