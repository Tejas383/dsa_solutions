#include <bits/stdc++.h>
using namespace std;

// Approach Name: Direct Traversal with Divisibility Check
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
 public:
  int sumOfSquares(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (n % (i + 1) == 0) {
        ans += (nums[i] * nums[i]);
      }
    }

    return ans;
  }
};