#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

struct TrieNode {
  char key;
  bool isEndOfWord;
  std::vector<TrieNode* > children;
};

class Autocomplete {
 public:
  std::vector<TrieNode*> knownWords;
  std::vector<TrieNode*> *currLevel;

  Autocomplete();

  //std::vector<std::string> getSuggestions(std::string partialWord);  // return the known words that start with partialWord
  void insert(std::string word); // add a word to the known words
};
#endif