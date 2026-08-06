#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force - Take/Skip)
// Time complexity = O(2^n)
// Space complexity = O(n)

class Solution {
  int helper(int i, int sum, int target, vector<int>& nums) {
    if (i == nums.size() && sum == target) return 1;

    if (i == nums.size()) return 0;

    return helper(i + 1, sum + nums[i], target, nums) +
           helper(i + 1, sum - nums[i], target, nums);
  }

 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    return helper(0, 0, target, nums);
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(n * 2001)
// Space complexity = O(n * 2001) + O(n) (recursion stack)

class Solution {
  int helper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if (abs(sum) > 1000) return 0;

    if (dp[i][sum + 1000] != -1) return dp[i][sum + 1000];

    if (i == nums.size() && sum == 0) return dp[i][sum + 1000] = 1;

    if (i == nums.size()) return 0;

    return dp[i][sum + 1000] = helper(i + 1, sum + nums[i], nums, dp) +
                               helper(i + 1, sum - nums[i], nums, dp);
  }

 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2001, -1));
    return helper(0, target, nums, dp);
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
// Time complexity = O(n * 2001)
// Space complexity = O(n * 2001)

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2001, 0));

    dp[0][1000] = 1;
    int offset = 1000;
    for (int i = 1; i <= n; i++) {
      for (int sum = -1000; sum <= 1000; sum++) {
        int add = sum + nums[i - 1];
        int sub = sum - nums[i - 1];
        if (add + offset >= 0 && add + offset <= 2000)
          dp[i][sum + offset] += dp[i - 1][add + offset];
        if (sub + offset >= 0 && sub + offset <= 2000)
          dp[i][sum + offset] += dp[i - 1][sub + offset];
      }
    }

    return dp[n][target + offset];
  }
};