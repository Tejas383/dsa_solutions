#include <bits/stdc++.h>
using namespace std;

// Approach Name: Min-Heap (Priority Queue) with Index Tracking
// Time Complexity: O(n + k log n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i], i});
    }

    while (k--) {
      int idx = pq.top().second;
      pq.pop();

      nums[idx] *= multiplier;

      pq.push({nums[idx], idx});
    }

    return nums;
  }
};