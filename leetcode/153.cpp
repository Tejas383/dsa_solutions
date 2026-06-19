#include <bits/stdc++.h>
using namespace std;

// Approach name: Modified Binary Search
// Time complexity: O(log n)
// Space complexity: O(1)

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
      mid = (low + high) / 2;

      if (nums[mid] < nums[high]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return nums[mid];
  }
};