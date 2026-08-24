#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursive DFS
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

      if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
          grid[newI][newJ] == '1') {
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

// Approach 2: BFS
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) worst case

class Solution {
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};

  void bfs(int i, int j, vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = 0;

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      int I = curr.first;
      int J = curr.second;

      for (int k = 0; k < 4; k++) {
        int di = I + dx[k];
        int dj = J + dy[k];

        if (di >= 0 && di < m && dj >= 0 && dj < n && grid[di][dj] == '1') {
          q.push({di, dj});
          grid[di][dj] = '0';
        }
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          count++;
          bfs(i, j, grid);
        }
      }
    }

    return count;
  }
};

// Approach 3: Disjoint Set Union (DSU / Union-Find)
// Time Complexity  : O(n * m * α(n * m)) ≈ O(n * m)
// Space Complexity : O(n * m)

class Solution {
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};

  vector<int> parent;

  int findParent(int a) {
    if (parent[a] == a) return a;

    return parent[a] = findParent(parent[a]);
  }

  void makeUnion(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);

    if (pa == pb) return;

    parent[pa] = parent[b];
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    parent.resize(m * n);
    for (int i = 0; i < m * n; i++) {
      parent[i] = i;
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') count++;
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '0') continue;

        for (int k = 0; k < 4; k++) {
          int di = i + dx[k];
          int dj = j + dy[k];

          if (di >= 0 && di < m && dj >= 0 && dj < n && grid[di][dj] == '1') {
            int a = n * i + j;
            int b = n * di + dj;

            if (findParent(a) != findParent(b)) {
              makeUnion(a, b);
              count--;
            }
          }
        }
      }
    }

    return count;
  }
};