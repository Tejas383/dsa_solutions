#include <bits/stdc++.h>
using namespace std;

// Approach: Brute Force (Nested Loops)
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (abs(nums[i] - nums[j]) == k) count++;
      }
    }
    return count;
  }
};