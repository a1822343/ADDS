#include "Node.h"

Node::Node() {}

Node::Node(int _data, Node* _link){
  data = _data;
  link = _link;
}

int Node::getData() { return data; }

void Node::setLink(Node* _link) { link = _link; }
Node* Node::getLink() { return link; }

Node::~Node(){}