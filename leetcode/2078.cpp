#include <vector>
#include <algorithm>
using namespace std;

// Approach name: Brute Force (All Pairs Comparison)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = i + 1; j < colors.size(); j++) {
                if (colors[i] != colors[j])
                    ans = max(ans, abs(j - i));
            }
        }

        return ans;
    }
};