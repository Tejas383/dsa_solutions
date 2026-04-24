#include <vector>
#include <map>
using namespace std;

// Approach Name: Grouping + Prefix Sum
// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> indices;

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }

        vector<long long> ans(n);
        for (auto p : indices) {
            vector<int> vec = p.second;

            long long sum = 0;
            for (auto v : vec)
                sum += v;
            
            long long total = 0;
            for (int i = 0; i < vec.size(); i++) {
                ans[vec[i]] = sum - total * 2 + vec[i] * (2 * i - vec.size());
                total += vec[i];
            }
        }

        return ans;
    }
};