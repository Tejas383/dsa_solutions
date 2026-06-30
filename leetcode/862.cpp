#include <bits/stdc++.h>
using namespace std;

// Approach Name: Prefix Sum + Monotonic Deque
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();

    vector<long long> preSum;
    preSum.push_back(0);
    long long sum = 0;
    for (auto num : nums) {
      sum += num;
      preSum.push_back(sum);
    }

    int ans = INT_MAX;

    deque<int> dq;
    for (int i = 0; i <= n; i++) {
      // finding the point when prefix >= k , and shrinking the window
      while (!dq.empty() && preSum[i] - preSum[dq.front()] >= k) {
        ans = min(ans, i - dq.front());
        dq.pop_front();
      }

      // checking if curr prefix < prev prefix
      while (!dq.empty() && preSum[dq.back()] >= preSum[i]) {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    if (ans == INT_MAX) return -1;
    return ans;
  }
};