#include "Autocomplete.h"

#include <iostream>

Autocomplete::Autocomplete() { currLevel = &knownWords; }

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
  std::vector<std::string> returnVector;
  bool inTree = false;
  for (size_t i = 0; i < partialWord.length(); i++) {
    for (size_t j = 0; j < currLevel->size(); j++) {
      if (partialWord[i] == currLevel->at(j)->key) {
        currLevel = &currLevel->at(j)->children;
        inTree = true;
        break;
      } else {
        inTree = false;
      }
    }
    if (!inTree) {
      return returnVector;
    }
  }
  returnAllBranches(&returnVector, currLevel, partialWord);

  return returnVector;
}  // return the known words that start with partialWord

void Autocomplete::returnAllBranches(std::vector<std::string> *returnVector,
                                     std::vector<TrieNode *> *tree,
                                     std::string word) {
  std::string currWord;
  std::vector<TrieNode *> *subTree;
  std::vector<std::string> subVector;

  for (size_t i = 0; i < tree->size(); i++) {
    currWord = word;
    currWord.push_back(tree->at(i)->key);
    if (tree->at(i)->isEndOfWord) {
      returnVector->push_back(currWord);
    }
    if (tree->size() > 0) {
      subTree = &tree->at(i)->children;
      returnAllBranches(returnVector, subTree, currWord);
    }
  }
}

void Autocomplete::insert(std::string word) {
  TrieNode *node = new TrieNode{'\0', false};
  bool end = false;

  if (knownWords.empty()) {
    if (word.size() == 1) {
      node->isEndOfWord = true;
    }
    node->key = word[0];
    knownWords.push_back(node);
  }

  for (size_t i = 0; i < word.length(); i++) {
    if (i == word.length() - 1) {
      end = true;
    }
    for (size_t j = 0; j < currLevel->size(); j++) {
      if (word[i] == currLevel->at(j)->key) {
        if (!end) {
          currLevel = &currLevel->at(j)->children;
          insert(word.substr(i + 1));
          currLevel = &knownWords;
          return;
        } else {
          currLevel->at(j)->isEndOfWord = true;
          currLevel = &knownWords;
          return;
        }
      }
    }

    node->key = word[i];
    node->isEndOfWord = end;
    currLevel->push_back(node);
    if (!end) {
      currLevel = &currLevel->back()->children;
      insert(word.substr(i + 1));
      currLevel = &knownWords;
      return;
    }
  }
}  // add a word to the known words