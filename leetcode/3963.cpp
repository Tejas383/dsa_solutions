#include <bits/stdc++.h>
using namespace std;

// Approach Name: String Construction and Vector Initialization
// Time Complexity (TC): O(m * n)
// Space Complexity (SC): O(m * n)

class Solution {
 public:
  vector<string> createGrid(int m, int n) {
    string str = "";
    string row1 = "";
    for (int i = 0; i < n - 1; i++) {
      row1 += ".";
      str += "#";
    }
    row1 += ".";

    vector<string> grid(m, str);

    grid[0] = row1;
    for (int i = 1; i < m; i++) {
      grid[i] += '.';
    }

    return grid;
  }
};