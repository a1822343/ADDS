#ifndef NODE_H
#define NODE_H

class Node {
 private:
  int data;
  Node* link;
 public:
  Node();
  int getData();
  void setData(int _data);
  Node* getLink();
  
  ~Node();
};
#endif