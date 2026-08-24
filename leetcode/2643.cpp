#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sorting Rows and Binary Search for Maximum Ones
// Time Complexity: O(m * n log n)
// Space Complexity: O(log n)

class Solution {
  int calculateOnes(vector<int> currRow) {
    int low = 0;
    int high = currRow.size() - 1;
    int mid;

    while (low <= high) {
      mid = (high - low) / 2 + low;

      if (currRow[mid] == 0)
        high = mid - 1;
      else
        low = mid + 1;
    }

    return low;
  }

 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    for (auto& row : mat) {
      sort(row.begin(), row.end());
      reverse(row.begin(), row.end());
    }

    int ones = 0;
    int row = 0;

    for (int i = 0; i < mat.size(); i++) {
      if (mat[i][ones] == 1) {
        row = i;
        ones = calculateOnes(mat[i]);
      }
      if (ones == mat[i].size()) break;
    }

    return {row, ones};
  }
};

// Approach Name: Linear Counting
// Time Complexity: O(m * n)
// Space Complexity: O(1)

class Solution {
 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    for (auto& row : mat) {
      sort(row.begin(), row.end());
      reverse(row.begin(), row.end());
    }

    int ones = 0;
    int row = 0;

    for (int i = 0; i < mat.size(); i++) {
      int count = 0;

      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == 1) count++;
      }

      if (count > ones) {
        ones = count;
        row = i;
      }

      if (ones == mat[i].size()) break;
    }

    return {row, ones};
  }
};