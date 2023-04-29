#include "LinkedList.h"

#include <iostream>
#include <limits>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::LinkedList(int* array, int len) { 
    head = nullptr;
    for (int i = 1; i < len + 1; i++){
      insertPosition(i, array[i-1]);
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
  // if adding in front of the current head (including if the list is empty)
  if (pos <= 1) {
    head = new Node(newNum, head);
    return;
  }
  // if inserting between two nodes; i.e. [A, C] -> [A, B, C]
  Node* prevNode = traverse(pos - 1);
  // if inserting out of bounds, abort
  if (prevNode == nullptr) {
    return;
  }
  Node* newNode = new Node(newNum, prevNode->getLink());
  prevNode->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
  Node* prevNode = traverse(pos - 1);
  if (prevNode->getLink() == nullptr) {
    return false;
  }
  prevNode->setLink(traverse(pos)->getLink());
  return true;
}

int LinkedList::get(int pos) {
  Node* nodeAtPos = traverse(pos);
  if (nodeAtPos == nullptr) {
    return std::numeric_limits<int>::max();
  }
  return nodeAtPos->getData();
}

int LinkedList::search(int target) {
  int pos = 0;
  Node* currNode = head;
  while (currNode->getLink() != nullptr) {
    if (currNode->getData() == target){
      return pos;
    }
    currNode = currNode->getLink();
    pos++;
  }
  return -1;
}

void LinkedList::printList() {
  Node* currNode = head;
  std::cout << "[" << currNode->getData();
  currNode = currNode->getLink();
  while (currNode != nullptr) {
    std::cout << " " << currNode->getData();
    currNode = currNode->getLink();
  }
  std::cout << "]" << std::endl;
}

Node* LinkedList::traverse(int pos) {
  int position = 1;
  Node* currNode = head;
  while (currNode != nullptr && position < pos) {
    currNode = currNode->getLink();
    position++;
  }
  return currNode;
}

void LinkedList::deleteFromFront() {
  if (head == nullptr) {
    return;
  }
  Node* temp = head;
  head = head->getLink();
  delete temp;
}

LinkedList::~LinkedList() {
  while (head != nullptr) {
    deleteFromFront();
  }
}