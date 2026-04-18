#include <vector>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

// Approach name: Hash Map + Reverse Number Matching (Brute-force over indices)
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = (rev * 10) + (num % 10);
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        map<int, vector<int>> idx;
        for (int i = 0; i < nums.size(); i++) {
            idx[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums[i]);

            if (idx.find(rev) != idx.end()) {
                vector<int> vec = idx[rev];

                for (int j = 0; j < vec.size(); j++) {
                    int loc = vec[j];

                    if (loc > i)
                        ans = min(ans, abs(i - loc));
                }
                
            }

            if (ans == 1)
                break;
        }
        
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};