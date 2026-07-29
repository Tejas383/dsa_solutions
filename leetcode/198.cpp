#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force / Take/Skip)
// Time complexity = O(2 ^ n)
// Space complexity = O(n)

class Solution {
  int helper(int i, vector<int>& nums) {
    if (i >= nums.size()) return 0;

    int take = nums[i] + helper(i + 2, nums);
    int skip = helper(i + 1, nums);

    return max(take, skip);
  }

 public:
  int rob(vector<int>& nums) { 
    return helper(0, nums); 
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
  vector<int> dp;

  int helper(int i, vector<int>& nums) {
    if (dp[i] != -1) return dp[i];

    if (i == 0) return dp[i] = 0;

    if (i == 1) return dp[i] = nums[0];

    int take = nums[i - 1] + helper(i - 2, nums);
    int skip = helper(i - 1, nums);

    return dp[i] = max(take, skip);
  }

 public:
  int rob(vector<int>& nums) {
    dp.resize(nums.size() + 1, -1);
    return helper(nums.size(), nums);
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() <= 1) return nums[0];

    vector<int> dp(nums.size(), -1);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      int take = nums[i] + dp[i - 2];
      int skip = dp[i - 1];

      dp[i] = max(take, skip);
    }

    return dp[nums.size() - 1];
  }
};