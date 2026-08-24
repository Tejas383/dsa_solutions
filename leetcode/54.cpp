#include <bits/stdc++.h>
using namespace std;

// Approach 1: Layer-by-Layer Spiral Traversal
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

// Approach 2 : Boundary Shrinking Traversal
// Time Complexity : O(m * n)
// Space Complexity : O(1)

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiral;

    int i = 0;
    int j = 0;

    int m = matrix.size();
    int r = -1;
    int n = matrix[0].size();
    int c = -1;

    int s = m * n;

    while (spiral.size() < s) {
      while (spiral.size() < s && j < n) spiral.push_back(matrix[i][j++]);
      j--;
      i++;
      n--;
      while (spiral.size() < s && i < m) spiral.push_back(matrix[i++][j]);
      i--;
      j--;
      m--;
      while (spiral.size() < s && j > c) spiral.push_back(matrix[i][j--]);
      j++;
      i--;
      r++;
      while (spiral.size() < s && i > r) spiral.push_back(matrix[i--][j]);
      i++;
      j++;
      c++;
    }

    return spiral;
  }
};