#include <vector>
using namespace std;

// Approach name: Top-Down Dynamic Programming (3D DP) with Memoization
// Time Complexity : O(n * m * k)
// Space Complexity : O(n * m * k)

class Solution {
 public:
  int helper(int n, int m, vector<vector<int>>& grid, int k,
             vector<vector<vector<int>>>& dp) {
    if (dp[n][m][k] != -2) return dp[n][m][k];

    if (n == 0 && m == 0) return dp[n][m][k] = grid[n][m];

    int cost = (grid[n][m] == 0) ? 0 : 1;
    if (k < cost) return dp[n][m][k] = -1;

    int upScore = -1;
    int leftScore = -1;

    // move up
    if (n > 0) {
      int a = helper(n - 1, m, grid, k - cost, dp);
      if (a == -1)
        upScore = -1;
      else
        upScore = grid[n][m] + a;
    }

    // move left
    if (m > 0) {
      int a = helper(n, m - 1, grid, k - cost, dp);
      if (a == -1)
        leftScore = -1;
      else
        leftScore = grid[n][m] + a;
    }

    int score = max(upScore, leftScore);

    return dp[n][m][k] = score;
  }

  int maxPathScore(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -2)));

    int ans = helper(n - 1, m - 1, grid, k, dp);

    return ans;
  }
};