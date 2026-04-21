#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Brute Force (All Pairs Comparison)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Approach 2: Greedy / Two-End Comparison
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1])
                ans = max(ans, n - i - 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0])
                ans = max(ans, i);
        }

        return ans;
    }
};