#include <bits/stdc++.h>
using namespace std;

// Approach 1: Two-pass constraint relaxation
// Time complexity = O(n)
// Space complexity = O(n), causing MLE

class Solution {
 public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    vector<int> heights(n + 2, n + 1);
    heights[0] = 0;
    heights[1] = 0;

    for (int i = 0; i <= n + 1; i++) cout << i << " ";

    cout << endl;

    for (auto vec : restrictions) {
      int idx = vec[0];
      int val = min(vec[1], idx);
      heights[idx] = val;
    }

    for (auto h : heights) cout << h << " ";

    for (int i = 1; i <= n; i++) {
      if (heights[i] == n + 1)
        heights[i] = min(heights[i - 1], heights[i + 1]) + 1;
      else
        heights[i] = min(min(heights[i - 1], heights[i + 1]) + 1, heights[i]);
    }

    cout << endl;

    for (auto h : heights) cout << h << " ";

    int ans = 0;

    for (int i = n; i > 0; i--) {
      heights[i] = min(min(heights[i - 1], heights[i + 1]) + 1, heights[i]);
      ans = max(ans, heights[i]);
    }

    cout << endl;

    for (auto h : heights) cout << h << " ";

    return ans;
  }
};