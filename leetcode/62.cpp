#include <vector>
using namespace std;

// Approach 1: Recursion (Top-Down) / Brute Force
// Approach 2: Recursion + Memoization (Top-Down DP)
// Approach 3: Tabulation (Bottom-Up DP)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up, left;
                up = left = 0;

                if (i != 0)
                    up = dp[i - 1][j];
                if (j != 0)
                    left = dp[i][j - 1];

                dp[i][j] += up + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};