#include <bits/stdc++.h>
using namespace std;

// Approach Name: Monotonic Decreasing Deque
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
      int j = i - k + 1;

      if (!dq.empty() && j > dq.front()) dq.pop_front();

      while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

      dq.push_back(i);

      if (j >= 0) {
        ans.push_back(nums[dq.front()]);
      }
    }

    return ans;
  }
};