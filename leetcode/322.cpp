#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force - Take/Skip)
// Time complexity = O(2 ^ (n + amount))
// Space complexity = O(n + amount)

class Solution {
  int helper(int i, int amount, auto coins) {
    if (i >= coins.size()) return 1e9;

    if (amount == 0) return 0;

    int take = INT_MAX;
    if (coins[i] <= amount) 
      take = 1 + helper(i, amount - coins[i], coins);
    int skip = helper(i + 1, amount, coins);

    return min(take, skip);
  }

 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    return helper(0, amount, coins) >= 1e9 ? -1 : helper(0, amount, coins);
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(n * amount)
// Space complexity = O(n * amount)

class Solution {
  vector<vector<int>> dp;

  int helper(int i, int amount, vector<int>& coins) {
    if (amount == 0) return dp[i][amount] = 0;

    if (i >= coins.size()) return 1e9;

    if (dp[i][amount] != -1) return dp[i][amount];

    int take = 1e9;
    if (coins[i] <= amount) take = 1 + helper(i, amount - coins[i], coins);
    int skip = helper(i + 1, amount, coins);

    return dp[i][amount] = min(take, skip);
  }

 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    dp.resize(n, vector<int>(amount + 1, -1));
    int ans = helper(0, amount, coins);
    return ans >= 1e9 ? -1 : ans;
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
  vector<vector<int>> dp;

  int helper(int i, int amount, vector<int>& coins) {
    if (amount == 0) return dp[i][amount] = 0;

    if (i >= coins.size()) return 1e9;

    if (dp[i][amount] != -1) return dp[i][amount];

    int take = 1e9;
    if (coins[i] <= amount) take = 1 + helper(i, amount - coins[i], coins);
    int skip = helper(i + 1, amount, coins);

    return dp[i][amount] = min(take, skip);
  }

 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    dp.resize(n, vector<int>(amount + 1, -1));
    int ans = helper(0, amount, coins);
    return ans >= 1e9 ? -1 : ans;
  }
};