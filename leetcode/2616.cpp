#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer + Greedy Pair Formation
// Time complexity = O(n log n)
// Space complexity = O(1)

class Solution {
 public:
  int minimizeMax(vector<int>& nums, int p) {
    // Sort the array so that close values become adjacent.
    sort(nums.begin(), nums.end());

    // minimum possible maximum difference = 0
    int low = 0;
    // maximum possible maximum difference
    int high = nums.back() - nums.front();

    while (low < high) {
      int mid = (low + high) / 2;

      // number of non-overlapping pairs formed with difference <= mid.
      int count = 0;

      for (int i = 1; i < nums.size(); i++) {
        // If adjacent elements form a valid pair
        if (nums[i] - nums[i - 1] <= mid) {
          count++;

          // Skip the next index because
          // each element can belong to at most one pair.
          i++;
        }
      }

      // If we can form at least p pairs, we can reduce the space
      if (count >= p) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    // low == high -> minimum feasible maximum difference
    return low;
  }
};