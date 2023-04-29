#ifndef NODE_H
#define NODE_H

class Node {
 private:
  int data;
  Node* link;
 public:
  Node();
  Node(int _data, Node* _link);

  int getData();

  void setLink(Node* _link);
  Node* getLink();
  ~Node();
};
#endif