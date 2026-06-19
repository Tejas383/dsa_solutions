#include <bits/stdc++.h>
using namespace std;

// Approach name: Modified Binary Search
// Time complexity: O(log n)
// Space complexity: O(1)

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
      mid = (low + high) / 2;

      if (nums[mid] == target) return true;

      if (nums[low] == nums[high] && nums[low] == nums[mid]) {
        low++;
        high--;
        continue;
      }

      if (nums[mid] <= nums[high]) {
        if (target >= nums[mid] && target <= nums[high])
          low = mid + 1;
        else
          high = mid - 1;
      } else {
        if (target >= nums[mid] || target <= nums[high])
          low = mid + 1;
        else
          high = mid - 1;
      }
    }

    return false;
  }
};