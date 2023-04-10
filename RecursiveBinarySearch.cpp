#include "RecursiveBinarySearch.h"
#include <iostream>

bool RecursiveBinarySearch::search(std::vector<int> tree, int n){
  if (tree.size() <= 1){
    if (tree.size() == 0) { return false; }
    if (tree[0] == n){
      return true;
    } else {
      return false;
    }
  }

  std::vector<int> branch;

  if (tree[tree.size() / 2] == n){
    return true;
  } else if (tree[tree.size() / 2] > n){
    for (size_t i = 0; i < tree.size() / 2; i++){
      branch.push_back(tree[i]);
    }
    return search(branch, n);
  } else if (tree[tree.size() / 2] < n){
    for (size_t i = tree.size() / 2 + 1; i < tree.size(); i++){
      branch.push_back(tree[i]);
    }
    return search(branch, n);
  }
  return false;
}