#include <vector>
#include <cmath>
using namespace std;

// Approach 1: Linear Scan (Brute Force Traversal)
// Time Complexity = O(n)
// Space Complexity = O(1)

// Approach 2: Two-Pointer Expansion (Bidirectional Linear Search)
// Time Complexity = O(n)
// Space Complexity = O(1)
// slightly better, because of early return

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start;
        int j = start;
        while (i >= 0 || j < nums.size()) {
            if (i >= 0) {
                if (nums[i] == target)
                    return abs(i - start);
                i--;
            }
            if (j < nums.size()) {
                if (nums[j] == target)
                    return abs(j - start);
                j++;
            }
        }

        return -1;
    }
};