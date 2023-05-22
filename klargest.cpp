#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k){
  std::priority_queue<int> p_q;
  for (int i =0; i < values.size(); i++){
    p_q.push(values.at(i));
  }
  for (int i = 0; i < k; i++){
     p_q.pop();
  }
  return p_q.top();
}