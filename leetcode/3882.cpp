#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursive DFS (Brute Force)
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n) — recursion stack

class Solution {
  int helper(int i, int j, int x, int m, int n, vector<vector<int>>& grid) {
    if (i >= m || j >= n) return INT_MAX;

    if (i == m - 1 && j == n - 1) return x ^ grid[i][j];

    // move down
    int down = helper(i + 1, j, grid[i][j] ^ x, m, n, grid);

    // move right
    int right = helper(i, j + 1, grid[i][j] ^ x, m, n, grid);

    return min(down, right);
  }

 public:
  int minCost(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    return helper(0, 0, 0, m, n, grid);
  }
};

// Approach 2: DFS + Memoization (DP)
// Time Complexity: O(m * n * 1024)
// Space Complexity: O(m * n * 1024) — DP table

class Solution {
  vector<vector<vector<int>>> dp;

  int helper(int i, int j, int x, int m, int n, vector<vector<int>>& grid) {
    if (dp[i][j][x] != -1) return dp[i][j][x];

    if (i >= m || j >= n) return dp[i][j][x] = INT_MAX;

    if (i == m - 1 && j == n - 1) return dp[i][j][x] = x ^ grid[i][j];

    // move down
    int down = helper(i + 1, j, grid[i][j] ^ x, m, n, grid);

    // move right
    int right = helper(i, j + 1, grid[i][j] ^ x, m, n, grid);

    return dp[i][j][x] = min(down, right);
  }

 public:
  int minCost(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(1024, -1)));

    return helper(0, 0, 0, m, n, grid);
  }
};