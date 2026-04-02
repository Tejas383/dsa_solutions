#include <vector>;
#include <climits>;
using namespace std;

// Approach 1: Recursive Dynamic Programming (Top-Down) — without Memoization
// Time Complexity: O(4^(m+n))
// Space Complexity: O(m + n)
// TLE

// Approach 2: Top-Down Dynamic Programming (Memoization) with State Augmentation
// Time complexity: O(m * n) , since skips is a constant (2)
// Space complexity: O(m * n) , since skips is a constant (2)
// STATE AUGMENTATION: expanding DP state to include all variables needed to uniquely define a subproblem. 
// Here, we include 'skips' in the state to account for the number of skips used, allowing us to handle the constraint of 2 skips.
// TLE due to large state space (because of recursion)

// Approach 3: Bottom-Up Dynamic Programming (Tabulation) with State Augmentation
// Time complexity: O(m * n) , since skips is a constant (2)
// Space complexity: O(m * n) , since skips is a constant (2)
// ACCEPTED

class Solution {
public:
  int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size();
    int n = coins[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (3, INT_MIN)));
    // dp[i][j][k] = maximum coins collectible till cell (i, j)
    // using k skips (skip allowed only for negative cells)

    // i -> m
    // j -> n
    // k -> skips

    // Base case: starting cell (0,0)
    for (int k = 0; k < 3; k++) {
      // i == 0 && j == 0

      // If negative and skips available → option to skip (take 0 instead)
      if (coins[0][0] < 0 && k > 0)
        dp[0][0][k] = max(coins[0][0], 0);
      else 
        dp[0][0][k] = coins[0][0];
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 3; k++) {
          if (i == 0 && j == 0)
            continue;

          // Transition:
          // 1. Take current cell → coins[i][j] + max(from top, from left)
          // 2. Skip current cell (only if negative and k > 0)
          //    → carry forward previous value with one less skip
          // Final answer = dp[m-1][n-1][2]

          if (i == 0) {
            // go left
            int take = coins[i][j] + dp[i][j - 1][k];
            int skip = INT_MIN;
            if (coins[i][j] < 0 && k > 0)
              skip = dp[i][j - 1][k - 1];
            
            dp[i][j][k] = max(take, skip);
          } else if (j == 0) {
            // go up
            int take = coins[i][j] + dp[i - 1][j][k];
            int skip = INT_MIN;
            if (coins[i][j] < 0 && k > 0)
                skip = dp[i - 1][j][k - 1];
            
            dp[i][j][k] = max(take, skip);
          } else {
            // i != 0 && j != 0
            int upTake = dp[i - 1][j][k];
            int leftTake = dp[i][j - 1][k];

            int take = coins[i][j] + max(leftTake, upTake);
            int skip = INT_MIN;

            if (coins[i][j] < 0 && k > 0) {
              int upSkip = dp[i - 1][j][k - 1];
              int leftSkip = dp[i][j - 1][k - 1];

              skip = max(leftSkip, upSkip);
            }

              dp[i][j][k] = max(take, skip);                    
          }
        }
      }
    }

    // Final answer
    return dp[m - 1][n - 1][2];
  }
};