#include <vector>;
#include <climits>;
using namespace std;

// Approach 1: Recursive Dynamic Programming (Top-Down) — without Memoization
// Time Complexity: O(4^(m+n))
// Space Complexity: O(m + n)

// Approach 2: Top-Down Dynamic Programming (Memoization) with State Augmentation
// Time complexity: O(m * n) , since skips is a constant (2)
// Space complexity: O(m * n) , since skips is a constant (2)
// STATE AUGMENTATION: expanding DP state to include all variables needed to uniquely define a subproblem. 
// Here, we include 'skips' in the state to account for the number of skips used, allowing us to handle the constraint of at most 2 skips effectively.

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& coins, int skips, vector<vector<vector<int>>>& dp) {
        if (dp[m][n][skips] != -1) 
            return dp[m][n][skips];
        
        if (m == 0 && n == 0) {
            if (coins[m][n] < 0 && skips > 0)
                return dp[m][n][skips] = max(coins[m][n], 0);
            return dp[m][n][skips] = coins[m][n];
        }
        
        if (m == 0) {
            // go left
            int take = coins[m][n] + solve(m, n - 1, coins, skips, dp);
            int skip = INT_MIN;
            if (coins[m][n] < 0 && skips > 0)
                skip = solve(m, n - 1, coins, skips - 1, dp);
            return dp[m][n][skips] = max(take, skip);
        }
        if (n == 0) {
            // go up
            int take = coins[m][n] + solve(m - 1, n, coins, skips, dp);
            int skip = INT_MIN;
            if (coins[m][n] < 0 && skips > 0)
                skip = solve(m - 1, n, coins, skips - 1, dp);
            return dp[m][n][skips] = max(take, skip);
        }

        // m != 0 && n != 0
        int upTake = solve(m - 1, n, coins, skips, dp); 
        int leftTake = solve(m, n - 1, coins, skips, dp);

        int take = coins[m][n] + max(leftTake, upTake);
        int skip = INT_MIN;

        if (coins[m][n] < 0 && skips > 0) {
            int upSkip = solve(m - 1, n, coins, skips - 1, dp); 
            int leftSkip = solve(m, n - 1, coins, skips - 1, dp);

            skip = max(leftSkip, upSkip);
        }

        return dp[m][n][skips] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(), vector<vector<int>> (coins[0].size(), vector<int> (3, -1)));
        return solve(coins.size() - 1, coins[0].size() - 1, coins, 2, dp);
    }
};