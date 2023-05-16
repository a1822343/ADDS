#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() { currLevel = &knownRouters; }

int PrefixMatcher::selectRouter(std::string networkAddress) {
  int returnRouter = 0;
  int max = 0;
  bool inTree = false;
  for (size_t i = 0; i < networkAddress.length(); i++) {
    for (size_t j = 0; j < currLevel->size(); j++) {
      if (networkAddress[i] == currLevel->at(j)->key) {
        currLevel = &currLevel->at(j)->children;
        inTree = true;
        break;
      } else {
        inTree = false;
      }
    }
    if (!inTree) {
      return returnRouter;
    }
  }

  returnRouter = traverse(currLevel, 0, max);

  return returnRouter;
}  // return the router with the longest matching prefix

int PrefixMatcher::traverse(std::vector<TrieNode*> *tree, int currLength, int max){
  std::vector<TrieNode *> *subTree;
  int returnRouter = tree->front()->routerNumber;
  for (size_t i = 0; i < tree->size(); i++) {
    if (tree->at(i)->isEndOf) {
      if (currLength > max){
        max = currLength;
        returnRouter = tree->at(i)->routerNumber;
      }
    } else {
      subTree = &tree->at(i)->children;
      currLength++;
      traverse(subTree, currLength, max);
    }
  }
  return returnRouter;
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
  // use Autocomplete::insert with an unordered_map
  TrieNode* node = new TrieNode{'\0', false};
  bool end = false;

  if (knownRouters.empty()) {
    if (address.size() == 1) {
      node->isEndOf = true;
    }
    node->key = address[0];
    node->routerNumber = routerNumber;
  }

  for (size_t i = 0; i < address.length(); i++) {
    if (i == address.length() - 1) {
      end = true;
    }
    for (size_t j = 0; j < currLevel->size(); j++) {
      if (address[i] == currLevel->at(j)->key) {
        if (!end) {
          currLevel = &currLevel->at(j)->children;
          insert(address.substr(i + 1), routerNumber);
          currLevel = &knownRouters;
          return;
        } else {
          currLevel->at(j)->isEndOf = true;
          currLevel = &knownRouters;
          return;
        }
      }
    }

    node->key = address[i];
    node->isEndOf = end;
    node->routerNumber = routerNumber;
    currLevel->push_back(node);
    if (!end) {
      currLevel = &currLevel->at(currLevel->size() - 1)->children;
      insert(address.substr(i + 1), routerNumber);
      currLevel = &knownRouters;
      return;
    }
  }
}  // add a router address