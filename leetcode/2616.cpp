#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer + Greedy Pair Formation
// Time complexity = O(n log n)
// Space complexity = O(1)

class Solution {
 public:
  int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());

    int low = 0;
    int high = nums[nums.size() - 1] - nums[0];

    while (low < high) {
      int mid = (low + high) / 2;

      int count = 0;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1] <= mid) {
          count++;
          i++;
        }
      }

      if (count >= p) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};