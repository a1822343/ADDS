#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list){
  int temp = 0;
  for (size_t i = 1; i < list.size(); i++){
    for (size_t j = 0; j < i; j++){
      if (list[j] > list[i]){
        temp = list[j];
        list[j] = list[i];
        list[i] = temp;
      }
    }
  }

  return list;
}