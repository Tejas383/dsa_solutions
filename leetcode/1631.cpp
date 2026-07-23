#include <bits/stdc++.h>
using namespace std;

// Approach name: Dijkstra's Algorithm (Greedy + Min Heap on a Grid / Minimum
// Bottleneck Path) Time Complexity: O((V+E)logV) Space Complexity: O(n * m)
// where,
// v = N × M vertices
// e ≈ 4NM edges (each cell has at most 4 neighbors)

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, 0, 0});
    // q = {current effort, i, j}

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    effort[0][0] = 0;

    while (!q.empty()) {
      auto curr = q.top();
      q.pop();

      int e = curr[0];
      int i = curr[1];
      int j = curr[2];

      for (int k = 0; k < 4; k++) {
        int di = i + dx[k];
        int dj = j + dy[k];

        if (di >= 0 && di < n && dj >= 0 && dj < m) {
          int de = max(abs(heights[i][j] - heights[di][dj]), e);

          if (de < effort[di][dj]) {
            effort[di][dj] = de;
            q.push({effort[di][dj], di, dj});
          }
        }
      }
    }

    return effort[n - 1][m - 1];
  }
};