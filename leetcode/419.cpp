#include <bits/stdc++.h>
using namespace std;

// Approach Name: Depth First Search (DFS) / Connected Components in a Grid (Flood Fill) 
// Time complexity = O(n * m) 
// Space complexity = O(n * m)

class Solution {
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  void dfs(int i, int j, int n, int m, vector<vector<char>>& board) {
    board[i][j] = 'Y';

    for (int k = 0; k < 4; k++) {
      int di = i + dx[k];
      int dj = j + dy[k];

      if (di >= 0 && di < n && dj >= 0 && dj < m && board[di][dj] == 'X')
        dfs(di, dj, n, m, board);
    }
  }

 public:
  int countBattleships(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    int ships = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'X') {
          ships++;
          dfs(i, j, n, m, board);
        }
      }
    }
    return ships;
  }
};