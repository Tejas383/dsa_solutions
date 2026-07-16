#include <bits/stdc++.h>
using namespace std;

// Approach Name: Recursive DFS
// Time complexity = O(n * m)
// Space complexity = O(h)

class Solution {
  void disconnected(int i, int j, int n, int m, vector<vector<char>>& grid) {
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int newI = i;
    int newJ = j;

    for (int k = 0; k < 4; k++) {
      newI = i + dx[k];
      newJ = j + dy[k];

      if (newI >= 0 && newI < n 
          && newJ >= 0 && newJ < m 
          && grid[newI][newJ] == '1') 
      {
        grid[newI][newJ] = '0';
        disconnected(newI, newJ, n, m, grid);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1') {
          count++;
          disconnected(i, j, n, m, grid);
        }
      }
    }

    return count;
  }
};