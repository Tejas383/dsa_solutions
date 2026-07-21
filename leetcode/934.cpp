#include <bits/stdc++.h>
using namespace std;

// Approach Name: BFS + Multi-Source BFS
// Time complexity = O(n ^ 2)
// Space complexity = O(n ^ 2)

class Solution {
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};

  void bfs(int si, int sj, queue<pair<int, int>>& q,
           vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> tempQ;

    q.push({si, sj});
    tempQ.push({si, sj});
    grid[si][sj] = 2;

    while (!tempQ.empty()) {
      auto curr = tempQ.front();
      tempQ.pop();

      int i = curr.first;
      int j = curr.second;

      for (int k = 0; k < 4; k++) {
        int di = i + dx[k];
        int dj = j + dy[k];

        if (di >= 0 && di < n && dj >= 0 && dj < n && grid[di][dj] == 1) {
          tempQ.push({di, dj});
          q.push({di, dj});

          grid[di][dj] = 2;
        }
      }
    }
  }

 public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) bfs(i, j, q, grid);
        if (!q.empty()) break;
      }
      if (!q.empty()) break;
    }

    int dist = 0;
    while (!q.empty()) {
      int s = q.size();

      while (s--) {
        auto curr = q.front();
        q.pop();

        int i = curr.first;
        int j = curr.second;

        for (int k = 0; k < 4; k++) {
          int di = i + dx[k];
          int dj = j + dy[k];

          if (di >= 0 || di < n || dj >= 0 || dj < n || grid[di][dj] == 2)
            continue;

          if (grid[di][dj] == 1)
            return dist;
          else if (grid[di][dj] == 0) {
            q.push({di, dj});
            grid[di][dj] = 2;
          }
        }
      }

      dist++;
    }

    return -1;
  }
};