#include <bits/stdc++.h>
using namespace std;

// Approach Name: Pivot and Suffix Reversal
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i;

    // find the 1st element from the end which is greater than its next element
    // for example: [1,5,8,4,7,6,5,3,1]
    // the required element is 4
    for (i = nums.size() - 2; i >= 0; i--) {
      if (nums[i + 1] > nums[i]) break;
    }

    if (i >= 0) {
      // swap the element with its greater element from the right
      for (int j = nums.size() - 1; j > i; j--) {
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          break;
        }
      }
    }

    // arrange the last elements in ascending order
    reverse(nums.begin() + i + 1, nums.end());
  }
};