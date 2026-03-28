#include <vector>
using namespace std;

// Approach 1: Recursion (Top-Down) / Brute Force
// Approach 2: Recursion + Memoization (Top-Down DP)

class Solution {
public:
    int reach(int m, int n, vector<vector<int>>& dp) {
        if (dp[m][n] != -1)
            return dp[m][n];
        
        if (m == 0 && n == 0)
            return dp[m][n] = 1;
        
        int up, left;
        up = left = 0;

        if (m != 0)
            up = reach(m - 1, n, dp);
        if (n != 0)
            left = reach(m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return reach(m - 1, n - 1, dp);
    }
};