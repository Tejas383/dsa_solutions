#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force - Take/Skip)
// Time complexity = O(2^n)
// Space complexity = O(n)

class Solution {
  bool helper(int i, int sum, vector<int>& nums) {
    if (i >= nums.size()) return false;

    if (sum == 0) return true;

    return helper(i + 1, sum - nums[i], nums) || helper(i + 1, sum, nums);
  }

 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) sum += num;

    if (sum % 2 == 1) return false;

    sum /= 2;
    return helper(0, sum, nums);
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(n * sum)
// Space complexity = O(n * sum)

class Solution {
  bool helper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if (i >= nums.size()) return false;

    if (sum < 0) return false;

    if (sum == 0) return dp[i][sum] = true;

    if (dp[i][sum] != -1) return dp[i][sum];

    return dp[i][sum] = helper(i + 1, sum - nums[i], nums, dp) ||
                        helper(i + 1, sum, nums, dp);
  }

 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) sum += num;

    if (sum % 2 == 1) return false;

    sum /= 2;
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return helper(0, sum, nums, dp);
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation) (0/1 Knapsack / Subset Sum) 
// Time complexity = O(n * sum)
// Space complexity = O(n * sum)

class Solution {
  bool helper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if (i >= nums.size()) return false;

    if (sum < 0) return false;

    if (sum == 0) return dp[i][sum] = true;

    if (dp[i][sum] != -1) return dp[i][sum];

    return dp[i][sum] = helper(i + 1, sum - nums[i], nums, dp) ||
                        helper(i + 1, sum, nums, dp);
  }

 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) sum += num;

    if (sum % 2 == 1) return false;

    sum /= 2;
    int n = nums.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        bool take = false;
        if (j >= nums[i - 1]) take = dp[i - 1][j - nums[i - 1]];
        bool skip = dp[i - 1][j];

        dp[i][j] = take || skip;
      }
    }

    return dp[n][sum];
  }
};