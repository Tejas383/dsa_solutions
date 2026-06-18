#include <bits/stdc++.h>
using namespace std;

// Approach Name: Layer-by-Layer Spiral Traversal
// Time complexity = O(m * n)
// Space complexity = O(1)

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int s = m * n;

    int i = 0;
    int j = 0;

    int t = 0;

    vector<int> spiral;

    while (spiral.size() < s) {
      while (spiral.size() < s && j < n - t) spiral.push_back(matrix[i][j++]);
      j--;
      i++;

      while (spiral.size() < s && i < m - t) spiral.push_back(matrix[i++][j]);
      i--;
      j--;

      while (spiral.size() < s && j >= t) spiral.push_back(matrix[i][j--]);
      j++;
      i--;

      t++;

      while (spiral.size() < s && i >= t) spiral.push_back(matrix[i--][j]);
      i++;
      j++;
    }

    return spiral;
  }
};