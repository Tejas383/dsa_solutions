#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (target > nums[nums.size() - 1]) return nums.size();

    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low < high) {
      mid = (low + high) / 2;

      if (nums[mid] == target) return mid;

      if (nums[mid] > target)
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }
};