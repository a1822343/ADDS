#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize){
  if (numCrates < 2 || numCrates > 10000){
    return 1;
  }
  if (loadSize < 1 || loadSize > (numCrates - 1)){
    return 1;
  }
  return (numTrucks(numCrates/2 + numCrates % 2, loadSize) + numTrucks(numCrates/2, loadSize));
}