#include <vector>
#include <map>
#include <climits>
using namespace std;

// Approach name: Hash Map + Sliding Window (on indices)
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto p : indices) {
            int dist = INT_MAX;

            // dist = abs(a - b) + abs(b - c) + abs(c - a);
            // a < b < c
            // dist = b - a + c - b + c - a
            //      = 2c - 2a
            //      = 2 * (c - a)
            
            if (p.second.size() >= 3) {
                for (int i = 0; i < p.second.size() - 2; i++) {
                    int a = p.second[i];
                    int c = p.second[i + 2];
                    ans = min(ans, (2 * (c - a)));
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};