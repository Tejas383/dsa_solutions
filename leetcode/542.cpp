#include <bits/stdc++.h>
using namespace std;

// Approach Name: Multi-Source BFS
// Time complexity = O(n * m)
// Space complexity = O(n * m)

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 0) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    int dis = 0;

    while (!q.empty()) {
      int s = q.size();
      dis++;

      while (s--) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
          int di = i + dx[k];
          int dj = j + dy[k];

          if (di >= 0 && di < n && dj >= 0 && dj < m &&
              dist[di][dj] == INT_MAX) {
            dist[di][dj] = dis;
            q.push({di, dj});
          }
        }
      }
    }

    return dist;
  }
};