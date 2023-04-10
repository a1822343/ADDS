#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list){
  std::vector<int> lessThan;
  std::vector<int> greaterThan;
  std::vector<int> newList;

  if (list.size() < 3){
    if (list.size() == 2){
      if (list[0] > list[1]){
        newList.push_back(list[1]);
        newList.push_back(list[0]);
        return newList;
      }
    }
    return list;
  }

  for (size_t i = 0; i < list.size(); i++){
    if (i != 2){
      if (list[i] <= list[2]){
        lessThan.push_back(list[i]);
      } else {
        greaterThan.push_back(list[i]);
      }
    }
  }

  std::vector<int> sortedLesser = sort(lessThan);
  
  for (size_t i = 0; i < sortedLesser.size(); i++){
    newList.push_back(sortedLesser[i]);
  }

  newList.push_back(list[2]);
  
  std::vector<int> sortedGreater = sort(greaterThan);

  for (size_t i = 0; i < sortedGreater.size(); i++){
    newList.push_back(sortedGreater[i]);
  }

  return newList;
}