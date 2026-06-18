#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int firstPos(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
      mid = (low + high) / 2;

      if (target == nums[mid]) {
        ans = mid;
        high = mid - 1;
      } else if (target < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

  int lastPos(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
      mid = (low + high) / 2;

      if (target == nums[mid]) {
        ans = mid;
        low = mid + 1;
      } else if (target < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    return vector<int>{firstPos(nums, target), lastPos(nums, target)};
  }
};