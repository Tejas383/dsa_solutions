#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force - Take/Skip)
// Time complexity = O(2^n)
// Space complexity = O(n)

class Solution {
  int helper(int i, int m, int n, vector<string>& strs) {
    if (i == strs.size()) return 0;

    int z = 0;
    int o = 0;
    int take = 0;
    for (char c : strs[i]) c == '0' ? z++ : o++;

    if (m - z >= 0 && n - o >= 0) take = 1 + helper(i + 1, m - z, n - o, strs);
    int skip = helper(i + 1, m, n, strs);

    return max(take, skip);
  }

 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    return helper(0, m, n, strs);
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(sz * m * n)
// Space complexity = O(sz * m * n)

class Solution {
  int helper(int i, int m, int n, vector<string>& strs, auto& dp) {
    if (dp[i][m][n] != -1) return dp[i][m][n];

    if (i == strs.size()) return dp[i][m][n] = 0;

    int z = 0;
    int o = 0;
    int take = 0;
    for (char c : strs[i]) c == '0' ? z++ : o++;

    if (m - z >= 0 && n - o >= 0)
      take = 1 + helper(i + 1, m - z, n - o, strs, dp);
    int skip = helper(i + 1, m, n, strs, dp);

    return dp[i][m][n] = max(take, skip);
  }

 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int sz = strs.size();
    vector<vector<vector<int>>> dp(
        sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
    );
    return helper(0, m, n, strs, dp);
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation) (0/1 Knapsack)
// Time complexity = O(sz * m * n) 
// Space complexity = O(sz * m * n)

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int sz = strs.size();
    vector<vector<vector<int>>> dp(
        sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0))
    );

    for (int i = 1; i <= sz; i++) {
      int z = 0;
      int o = 0;
      for (char c : strs[i - 1]) c == '0' ? z++ : o++;

      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= n; k++) {
          int take = 0;
          if (j - z >= 0 && k - o >= 0) take = 1 + dp[i - 1][j - z][k - o];
          int skip = dp[i - 1][j][k];

          dp[i][j][k] = max(take, skip);
        }
      }
    }

    return dp[sz][m][n];
  }
};