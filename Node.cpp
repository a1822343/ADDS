#include "Node.h"

Node::Node(){

}
int Node::getData(){ return data; }
void Node::setData(int _data) { data = _data; }
Node* Node::getLink() { return link; }