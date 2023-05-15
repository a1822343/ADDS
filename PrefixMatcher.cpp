// #include "PrefixMatcher.h"

// int PrefixMatcher::selectRouter(std::string networkAddress) {

// }  // return the router with the longest matching prefix
// // We've made this a string for ease of implementation, if you'd like to work with binary numbers in your implementation feel free but for testing you need to provide an interface that takes a string

// void PrefixMatcher::insert(std::string address, int routerNumber) {
//   std::unordered_map<int, TrieNode*> empty;
//   TrieNode* node = new TrieNode{0, false, empty};
//   bool end = false;

//   if (knownRouters.empty()){
//     if (address.size() == 1){
//       node->isEndOfAddress = true;
//     }
//     node->key = address[0];
//     knownRouters.insert(node, 1);
//   }

//   for (size_t i = 0; i < word.length(); i++){
//     //std::cout << word.substr(i+1) << std::endl;
//     if (i == address.length() - 1){
//       end = true;
//     }
//     if (!currLevel->empty()){
//       for (size_t j = 0; j < currLevel->size(); j++){
//         if (word[i] == currLevel->at(j)->key){
//           if (!end){
//             currLevel = &currLevel->at(j)->children;
//             insert(address.substr(i+1), routerNumber);
//             currLevel = &knownRouters;

//             return;
//           } else {
//             currLevel->at(j)->isEndOfAddress = true;
//             currLevel = &knownRouters;
//             return;
//           }
//         }
//       }
//     }

//     node->key = word[i];
//     node->isEndOfWord = end;
//     currLevel->push_back(node);
//     if (!end){
//       currLevel = &currLevel->back()->children;
//       insert(word.substr(i+1));
//       currLevel = &knownWords;
//       return;
//     }

//   }
// } // add a router address