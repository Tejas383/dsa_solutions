#include <vector>
using namespace std;

// Approach 1: Recursion (Top-Down) / Brute Force
// Approach 2: Recursion + Memoization (Top-Down DP)
// Approach 3: Tabulation (Bottom-Up DP)
// Approach 4: Space Optimized DP (1D Tabulation)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n + 1, 1);
        // prev[0] = 1;
        vector<int> curr(n + 1, 0);

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    curr[j] = 1;
                else {
                    int up, left;
                    up = left = 0;

                    up = prev[j];
                    left = curr[j - 1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};