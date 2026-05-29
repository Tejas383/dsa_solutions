#include <climits>
#include <vector>
using namespace std;

// Approach Name: Digit Sum Traversal / Simulation
// Time ciomplexity = O(n * d)
// Space complexity = O(1)

class Solution {
 public:
  int minElement(vector<int>& nums) {
    int ans = INT_MAX;

    for (auto num : nums) {
      int sum = 0;
      while (num > 0) {
        sum += (num % 10);
        num /= 10;
      }
      ans = min(ans, sum);
    }

    return ans;
  }
};