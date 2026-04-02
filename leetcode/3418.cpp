#include <vector>;
#include <climits>;
using namespace std;

// Approach 1: Recursive Dynamic Programming (Top-Down) — without Memoization
// Time Complexity: O(4^(m+n))
// Space Complexity: O(m + n)

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& coins, int skips) {
        if (m == 0 && n == 0) {
            if (coins[m][n] < 0 && skips > 0)
                return max(coins[m][n], 0);
            return coins[m][n];
        }
        
        if (m == 0) {
            // go left
            int take = coins[m][n] + solve(m, n - 1, coins, skips);
            int skip = INT_MIN;
            if (coins[m][n] < 0 && skips > 0)
                skip = solve(m, n - 1, coins, skips - 1);
            return max(take, skip);
        }
        if (n == 0) {
            // go up
            int take = coins[m][n] + solve(m - 1, n, coins, skips);
            int skip = INT_MIN;
            if (coins[m][n] < 0 && skips > 0)
                skip = solve(m - 1, n, coins, skips - 1);
            return max(take, skip);
        }

        // m != 0 && n != 0
        int upTake = solve(m - 1, n, coins, skips); 
        int leftTake = solve(m, n - 1, coins, skips);

        int take = coins[m][n] + max(leftTake, upTake);
        int skip = INT_MIN;

        if (coins[m][n] < 0 && skips > 0) {
            int upSkip = solve(m - 1, n, coins, skips - 1); 
            int leftSkip = solve(m, n - 1, coins, skips - 1);

            skip = max(leftSkip, upSkip);
        }

        return max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        return solve(coins.size() - 1, coins[0].size() - 1, coins, 2);
    }
};