#include "Autocomplete.h"

#include <iostream>

Autocomplete::Autocomplete(){
  currLevel = &knownWords;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
  std::vector<std::string> returnVector;
  for (size_t i = 0; i < partialWord.length(); i++){
    bool inTree = false;
    for (size_t j = 0; j < currLevel->size(); j++){
      if (partialWord[i] == currLevel->at(j)->key){
        inTree = true;
        currLevel = &currLevel->at(j)->children;
        if (i != partialWord.length() - 1){
          break;
        }
      }
    }
    if (!inTree){
      currLevel = &knownWords;
      return returnVector;
    }
  }

  while (!currLevel->empty()){
    for (size_t i = 0; i < currLevel->size(); i++){
      
    }
  }

  return returnVector;
}  // return the known words that start with partialWord

void Autocomplete::insert(std::string word) {
  std::vector<TrieNode*> empty;
  TrieNode* node = new TrieNode{NULL, false, empty};
  bool end = false;

  if (knownWords.empty()){
    if (word.size() == 1){
      node->isEndOfWord = true;
    }
    node->key = word[0];
    knownWords.push_back(node);
  }

  for (size_t i = 0; i < word.length(); i++){
    //std::cout << word.substr(i+1) << std::endl;
    if (i == word.length() - 1){
      end = true;
    }
    if (!currLevel->empty()){
      for (size_t j = 0; j < currLevel->size(); j++){
        if (word[i] == currLevel->at(j)->key){
          if (!end){
            currLevel = &currLevel->at(j)->children;
            insert(word.substr(i+1));
            currLevel = &knownWords;
            return;
          } else {
            currLevel->at(j)->isEndOfWord = true;
            currLevel = &knownWords;
            return;
          }
        }
      }
    }

    node->key = word[i];
    node->isEndOfWord = end;
    currLevel->push_back(node);
    if (!end){
      currLevel = &currLevel->back()->children;
      insert(word.substr(i+1));
      currLevel = &knownWords;
      return;
    }

  }
}  // add a word to the known words