#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

#include <iostream>

int main(int argc, char* argv[]){
  QuickSort ascOrder;
  RecursiveBinarySearch result;
  std::vector<int> list;

  for (size_t i = 1; i < argc; i++){
    list.push_back(atoi(argv[i]));
  }

  list = ascOrder.sort(list);

  std::cout << std::boolalpha << result.search(list, 1);
  
  for (size_t i = 0; i < list.size(); i++){
    std::cout << " " << list[i];
  }

  std::cout << std::endl;

  return 0;
}