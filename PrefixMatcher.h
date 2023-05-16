#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <unordered_map>

struct TrieNode {
  char key;
  bool isEndOfAddress;
  std::unordered_map<int, TrieNode*> children;
};

class PrefixMatcher {
 public: 
  std::unordered_map<int, TrieNode*> knownRouters;
  std::unordered_map<int, TrieNode*> *currLevel;
  int selectRouter(std::string networkAddress);
  void insert(std::string address, int routerNumber);
};
#endif