#include <algorithm>
#include <vector>
using namespace std;

// Approach name: Median-Based Greedy Approach (using flattening + sorting)
// Time Complexity = O(nm log nm),
// where,
// Flattening = O(n * m)
// Sorting = O(nm log nm)
// Space Complexity = O(n * m)

class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> nums;

    // // Flatten 2D grid into 1D array
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        nums.push_back(grid[i][j]);
      }
    }

    // Sorting the 1D array
    sort(nums.begin(), nums.end());

    // finding median
    // Median minimizes the total absolute difference,
    // so choosing median gives minimum number of operations
    int med = nums[nums.size() / 2];
    int ans = 0;

    for (int num : nums) {
      // If num and median do not have the same remainder when divided by x,
      // then it is impossible to make all elements equal
      if (num % x != med % x) return -1;

      // Number of operations needed to convert num to median
      // Each operation changes value by x
      ans += abs(med - num) / x;
    }

    return ans;
  }
};