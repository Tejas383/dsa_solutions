#include <bits/stdc++.h>
using namespace std;

// Approach Name: Row and Column Marking using Hash Sets
// Time complexity = O(m * n)
// Space complexity = O(m +n)

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> rows;
    unordered_set<int> cols;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (auto row : rows) {
      for (int j = 0; j < n; j++) {
        matrix[row][j] = 0;
      }
    }

    for (auto col : cols) {
      for (int i = 0; i < m; i++) {
        matrix[i][col] = 0;
      }
    }
  }
};