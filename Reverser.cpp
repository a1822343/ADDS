#include "Reverser.h"

int Reverser::reverseDigit(int value) {
  std::string reversedVal = std::to_string(value);
  return stoi(reverseString(reversedVal));
}

std::string Reverser::reverseString(std::string characters) {
  // base case
  if (characters.size() <= 1) {
    reversed.append(characters);
    return reversed;
  }

  // recursive case
    char last_letter = characters.back();
    characters.erase(characters.size() - 1, 1);
    reversed.append(1, last_letter);
    reverseString(characters);

  return reversed;
}