#include <bits/stdc++.h>
using namespace std;

// Approach name: Modified Binary Search on Rotated Sorted Array
// Time complexity: O(log n)
// Space complexity: O(1)

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high) / 2;

    while (low <= high) {
      mid = (low + high) / 2;

      if (nums[mid] == target) return mid;

      if (nums[mid] < nums[high]) {
        if (target <= nums[high] && target > nums[mid]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else {  // nums[mid] > nums[high]
        if (target <= nums[high] || target > nums[mid]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }

    return -1;
  }
};