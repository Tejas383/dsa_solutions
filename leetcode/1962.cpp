#include <bits/stdc++.h>
using namespace std;

// Approach Name: Greedy + Max Heap (Priority Queue)
// Time Complexity = O((n + k) log n)
// Space Complexity = O(n)

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;
    for (auto pile : piles) pq.push(pile);

    while (k--) {
      int pile = pq.top();
      pq.pop();
      pq.push(pile - pile / 2);
    }

    int sum = 0;
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }

    return sum;
  }
};