#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>

class TrieNode{
  friend class PrefixMatcher;
  friend class Autocomplete;
 private:
  char key;
  bool isEndOf;
  int routerNumber;
  std::vector<TrieNode*> children;
  TrieNode() {}
  TrieNode(char _key, bool _end) { key = _key; isEndOf = _end; }
};
#endif