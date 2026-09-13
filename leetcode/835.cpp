#include <bits/stdc++.h>
using namespace std;

// Approach: Brute Force (Try Every Shift)
// Time Complexity: O(n^4)
// Space Complexity: O(1)

class Solution {
  int countOverlaps(int row_offset, int col_offset, vector<vector<int>>& img1,
                    vector<vector<int>>& img2) {
    int count = 0;
    int n = img1.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i + row_offset < 0 || i + row_offset >= n) continue;
        if (j + col_offset < 0 || j + col_offset >= n) continue;

        if (img1[i][j] == 1 && img2[i + row_offset][j + col_offset] == 1)
          count++;
      }
    }

    return count;
  }

 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n = img1.size();

    int ans = 0;
    for (int row_offset = -n + 1; row_offset < n; row_offset++) {
      for (int col_offset = -n + 1; col_offset < n; col_offset++) {
        ans = max(ans, countOverlaps(row_offset, col_offset, img1, img2));
      }
    }

    return ans;
  }
};