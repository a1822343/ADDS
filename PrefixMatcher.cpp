#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(std::string networkAddress) {
  // use Autocomplete::getSuggestions and return the routerNumber of the largest
}  // return the router with the longest matching prefix

void PrefixMatcher::insert(std::string address, int routerNumber) {
  // use Autocomplete::insert with an unordered_map
  std::unordered_map<int, TrieNode*> empty;
  TrieNode* node = new TrieNode{'\0', false, empty};
  bool end = false;

  if (knownRouters.empty()){
    if (address.size() == 1){
      node->isEndOfAddress = true;
    }
    node->key = address[0];
    knownRouters.insert({routerNumber, node});
  }

  for (size_t i = 0; i < address.length(); i++){
    if (i == address.length() - 1){
      end = true;
    }
    if (!currLevel->empty()){
      for (size_t j = 0; j < currLevel->size(); j++){
        if (address[i] == currLevel->at(j)->key){
          if (!end){
            currLevel = &currLevel->at(j)->children;
            insert(address.substr(i+1), routerNumber);
            currLevel = &knownRouters;
            return;
          } else {
            currLevel->at(j)->isEndOfAddress = true;
            currLevel = &knownRouters;
            return;
          }
        }
      }
    }

    node->key = address[i];
    node->isEndOfAddress = end;
    currLevel->insert({routerNumber, node});
    if (!end){
      currLevel = &currLevel->at(currLevel->size() - 1)->children;
      insert(address.substr(i+1), routerNumber);
      currLevel = &knownRouters;
      return;
    }

  }
} // add a router address