#include "BigNumCalc.h"
#include <cmath>
#include <list>
#include <iostream>

BigNumCalc::BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString){
  // list to return
  std::list<int> numList;

  // for the length of numString
  for (size_t i = 0; i < numString.size(); i++){
    // get char as int, subtract ASCII value of 0 to account for offset
    numList.push_back(numString[i] - '0');
  }

  // get rid of trailing 0s
  numList = deleteTrailing(numList);

  // finished
  return numList;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
  // if num1[x] + num2[x] > 9, carry = 1, else 0
  int carry = 0;
  // internal variable for temp storing list elements
  int newEntry = 0;

  // list to return
  std::list<int> addedLists;

  // this alg is pretty much long addition
  // so start from the back (ones column) and move left
  std::list<int>::reverse_iterator rit1 = num1.rbegin();
  std::list<int>::reverse_iterator rit2 = num2.rbegin();

  // while there is a value to account for in both lists
  while (rit1 != num1.rend() && rit2 != num2.rend()){
    // num1[end - iteration] + num2[end - iteration] + carry
    newEntry = *rit1 + *rit2 + carry;

    // int rounds down, will give value in 10s place
    carry = newEntry / 10;

    // get rid of 10s place
    newEntry = newEntry % 10;

    // add to the start of the new list
    // as each iteration is worth 10x more
    addedLists.push_front(newEntry);

    // move to the next element
    rit1 = std::next(rit1);
    rit2 = std::next(rit2);
  }

  // if there are still elements left in num1
  while (rit1 != num1.rend()){
    // this is pretty much to just cover the case that carry = 1
    // and every new value in num1 is 9
    // otherwise behaves the same as above
    newEntry = *rit1 + carry;
    carry = newEntry / 10;
    newEntry = newEntry % 10;
    addedLists.push_front(newEntry);
    rit1 = std::next(rit1);
  }

  // if there are still elements left in num2
  while (rit2 != num2.rend()){
    // this is pretty much to just cover the case that carry = 1
    // and every new value in num2 is 9
    // otherwise behaves the same as above
    newEntry = *rit2 + carry;
    carry = newEntry / 10;
    newEntry = newEntry % 10;
    addedLists.push_front(newEntry);
    rit2 = std::next(rit2);
  }

  // last two elements might be > 9, in which case need to add a new order of 10 column
  if (carry != 0){
    addedLists.push_front(carry);
  }

  // get rid of trailing 0s
  addedLists = deleteTrailing(addedLists);

  // finished
  return addedLists;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
  // temp storage
  int newEntry = 0;

  // list to return
  std::list<int> subbedList;

  // get rid of trailing 0s
  // otherwise list.size() is misleading
  num1 = deleteTrailing(num1);
  num2 = deleteTrailing(num2);

  // temp storage lists
  std::list<int> greater = num1;
  std::list<int> lesser = num2;

  // determine which list has a greater value
  // use number of units first
  if (num1.size() > num2.size()){
    greater = num1;
    lesser = num2;
  } else if (num1.size() < num2.size()) {
    greater = num2;
    greater = num1;
  } else {
    // need a second iterator to represent num2
    std::list<int>::iterator it2 = num2.begin();

    // checking from greatest unit to smallest
    for (std::list<int>::iterator it1 = num1.begin(); it1 != num1.end(); it1++){
      // if there is a discrepancy, the list with the greater value wins
      if (*it1 > *it2) {
        greater = num1;
        lesser = num2;
        // leave for loop
        break;
      } else if (*it1 < *it2){
        greater = num2;
        lesser = num1;
        // leave for loop
        break;
      }
      it2++;
    }
  }

  // pretty much long subtraction
  std::list<int>::reverse_iterator rit1 = greater.rbegin();
  std::list<int>::reverse_iterator rit2 = lesser.rbegin();

  // so we don't affect the position of the original iterator
  std::list<int>::reverse_iterator tempRit;

  while (rit1 != greater.rend() && rit2 != lesser.rend()){
    if (*rit2 > *rit1){
      // will need to borrow from the unit over
      *rit1 += 10;

      tempRit = std::next(rit1);

      // in case we try to "borrow" from a 0
      while (*(tempRit) == 0){
        *(tempRit) = 9;
        tempRit = std::next(tempRit);
      }
      // borrow from this unit
      *tempRit = *tempRit - 1;
    }

    // perform the subtraction
    newEntry = *rit1 - *rit2;

    // add to list in correct place
    subbedList.push_front(newEntry);

    // next position
    rit1 = std::next(rit1);
    rit2 = std::next(rit2);
  }
  // in case there are units left
  while (rit1 != greater.rend()){
    subbedList.push_front(*rit1);
    rit1 = std::next(rit1);
  }

  // get rid of possible trailing 0 (if the two highest order columns are equal, it will result in 0....)
  while (*(subbedList.begin()) == 0 && subbedList.size() > 1){
    subbedList.pop_front();
  }

  // finished
  return subbedList;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
  // the tens column of the result of multiplying
  int carry = 0;

  // start from the back (ones column) and move left
  std::list<int>::reverse_iterator rit1 = num1.rbegin();
  std::list<int>::reverse_iterator rit2 = num2.rbegin();

  // use prevResult to store the addition of the already multiplied values
  std::list<int> prevResult (1,0);

  // num2 changes inside the nested while loop,
  // so reset value of num2 after each iteration
  std::list<int> temp = num2;

  // for every position in num1
  while (rit1 != num1.rend()){
    // multiply every value in num2 by current iteration of num1,
    // including carry
    while (rit2 != num2.rend()){
      // initial multiplication
      *rit2 = (*rit1) * (*rit2);
      // add the carry from the last mult
      *rit2 += carry;
      // set the new carry
      carry = *rit2 / 10;
      // limit the current value to the ones
      *rit2 = *rit2 % 10;

      // next position
      rit2++;
    }
    // add carry unit (trailing zeroes doesn't matter)
    num2.push_front(carry);
    // add new calc to result of all previous calcs
    prevResult = add(prevResult, num2);

    // reset num2
    num2 = temp;
    // multiply num2 by 10 to account for unit change
    // of num1 iteration
    num2.push_back(0);

    // set temp to new num2
    temp = num2;
    // reset num2 reverse-iterator
    rit2 = num2.rbegin();

    // reset carry
    carry = 0;
    // next position
    rit1++;
  }

  // return calcs
  return prevResult;
}

std::list<int> BigNumCalc::deleteTrailing(std::list<int> list){
    while (*(list.begin()) == 0 && list.size() > 1){
    list.pop_front();
  }
  return list;
}

BigNumCalc::~BigNumCalc() {}