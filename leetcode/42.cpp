#include <algorithm>
#include <vector>
using namespace std;

// Approach Name: Prefix & Suffix Maximum Arrays
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int maxVal;

    vector<int> max_left(n, -1);
    maxVal = 0;
    for (int i = 0; i < n; i++) {
      max_left[i] = maxVal;
      maxVal = max(maxVal, height[i]);
    }

    vector<int> max_right(n, -1);
    maxVal = 0;
    for (int i = n - 1; i >= 0; i--) {
      max_right[i] = maxVal;
      maxVal = max(maxVal, height[i]);
    }

    int ans = 0;
    vector<int> stored(n, 0);
    for (int i = 0; i < n; i++) {
      if (min(max_left[i], max_right[i]) < height[i]) continue;

      stored[i] = (min(max_left[i], max_right[i]) - height[i]);
      ans += stored[i];
    }

    return ans;
  }
};