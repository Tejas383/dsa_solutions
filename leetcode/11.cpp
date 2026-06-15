#include <bits/stdc++.h>
using namespace std;

// Approach Name: Two Pointers
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;

    int ans = 0;

    while (i < j) {
      int area = min(height[i], height[j]) * (j - i);
      ans = max(ans, area);

      if (height[i] < height[j])
        i++;
      else
        j--;
    }

    return ans;
  }
};