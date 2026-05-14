#include <vector>
using namespace std;

// Approach name: Frequency Counting / Hashing Approach
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
 public:
  bool isGood(vector<int>& nums) {
    int n = nums.size();

    vector<int> pres(n, 0);
    for (auto num : nums) {
      if (num >= n) return false;
      pres[num]++;
    }

    for (int i = 1; i < n - 1; i++) {
      if (pres[i] != 1) return false;
    }
    if (pres[n - 1] != 2) return false;

    return true;
  }
};