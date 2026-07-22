#include <bits/stdc++.h>
using namespace std;

// Approach Name: Breadth-First Search (BFS) on a Grid / Shortest Path in an Unweighted Graph 
// Time complexity = O(n ^ 2) 
// Space complexity = O(n ^ 2)

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    int dx[8] = {-1, 1, 0, 0, 1, -1, -1, 1};
    int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

    grid[0][0] = 1;

    while (!q.empty()) {
      int s = q.size();

      while (s--) {
        auto curr = q.front();
        q.pop();

        int i = curr.first;
        int j = curr.second;

        for (int k = 0; k < 8; k++) {
          int di = i + dx[k];
          int dj = j + dy[k];

          if (di >= 0 && di < n && dj >= 0 && dj < n && grid[di][dj] == 0) {
            grid[di][dj] = grid[i][j] + 1;
            q.push({di, dj});
          }
        }
      }
    }

    if (grid[n - 1][n - 1] == 0) return -1;
    return grid[n - 1][n - 1];
  }
};