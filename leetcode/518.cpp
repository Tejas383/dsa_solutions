#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force - Take/Skip)
// Time complexity = O(2 ^ (n + amount))
// Space complexity = O(n + amount)

class Solution {
  int helper(int i, int amount, vector<int>& coins) {
    if (amount == 0) return 1;

    if (i >= coins.size()) return 0;

    int take = 0;
    if (amount >= coins[i]) 
      take = helper(i, amount - coins[i], coins);
    int skip = helper(i + 1, amount, coins);

    return take + skip;
  }

 public:
  int change(int amount, vector<int>& coins) {
    return helper(0, amount, coins);
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(n * amount)
// Space complexity = O(n * amount)

class Solution {
  int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (amount == 0) return dp[i][amount] = 1;

    if (i >= coins.size()) return dp[i][amount] = 0;

    if (dp[i][amount] != -1) return dp[i][amount];

    int take = 0;
    if (amount >= coins[i]) 
      take = helper(i, amount - coins[i], coins, dp);
    int skip = helper(i + 1, amount, coins, dp);

    return dp[i][amount] = take + skip;
  }

 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return helper(0, amount, coins, dp);
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation) (Unbounded Knapsack)
// Time complexity = O(n * amount)
// Space complexity = O(n * amount)

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= amount; j++) {
        int take = 0;
        if (j >= coins[i - 1]) take = dp[i][j - coins[i - 1]];
        int skip = dp[i - 1][j];

        dp[i][j] = 1LL * take + skip;
      }
    }

    return dp[n][amount];
  }
};