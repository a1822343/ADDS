#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <vector>

struct TrieNode {
  char key;
  bool isEndOfAddress;
  int routerNumber;
  std::vector<TrieNode*> children;
};

class PrefixMatcher {
 public: 
  std::vector<TrieNode*> knownRouters;
  std::vector<TrieNode*> *currLevel;

  PrefixMatcher();

  int traverse(std::vector<TrieNode*> *tree, int currLength, int max);
  int selectRouter(std::string networkAddress);
  void insert(std::string address, int routerNumber);
};
#endif