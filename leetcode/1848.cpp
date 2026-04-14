#include <vector>
#include <cmath>
using namespace std;

// Approach 1: Linear Scan (Brute Force Traversal)
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                ans = min(ans, abs(start - i));
        }

        return ans;
    }
};