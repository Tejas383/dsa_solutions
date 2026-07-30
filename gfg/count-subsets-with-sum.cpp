#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// Approach 1: Recursion
// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)

class Solution {
  int helper(int i, int target, vector<int>& arr) {
    if (i == arr.size()) {
      if (target == 0) return 1;
      return 0;
    }

    int take = 0;
    if (target - arr[i] >= 0) take = helper(i + 1, target - arr[i], arr);
    int skip = helper(i + 1, target, arr);

    return take + skip;
  }

 public:
  int perfectSum(vector<int>& arr, int target) {
    // code here
    return helper(0, target, arr);
  }
};

// Approach 2: Memoisation
// Time Complexity: O(n * target)
// Space Complexity: O(n * target)

class Solution {
  int helper(int i, int target, auto& arr, auto& dp) {
    if (dp[i][target] != -1) return dp[i][target];

    if (i == arr.size()) {
      if (target == 0) return dp[i][target] = 1;
      return dp[i][target] = 0;
    }

    int take = 0;
    if (target - arr[i] >= 0) take = helper(i + 1, target - arr[i], arr, dp);
    int skip = helper(i + 1, target, arr, dp);

    return dp[i][target] = take + skip;
  }

 public:
  int perfectSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return helper(0, target, arr, dp);
  }
};

// Approach 3: Tabulation
// Time Complexity: O(n * target)
// Space Complexity: O(n * target)

class Solution {
 public:
  int perfectSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= target; j++) {
        int take = 0;
        if (j - arr[i - 1] >= 0) take = dp[i - 1][j - arr[i - 1]];
        int skip = dp[i - 1][j];

        dp[i][j] = take + skip;
      }
    }

    return dp[n][target];
  }
};