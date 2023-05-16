#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include "TrieNode.h"

class Autocomplete {
 private:
  std::vector<TrieNode*> knownWords;
  std::vector<TrieNode*> *currLevel;
 public:
  Autocomplete();

  void returnAllBranches(std::vector<std::string> *returnVector, std::vector<TrieNode*> *tree, std::string partialWord);
  std::vector<std::string> getSuggestions(std::string partialWord);  // return the known words that start with partialWord
  void insert(std::string word); // add a word to the known words
};
#endif