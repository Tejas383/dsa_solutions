#include <bits/stdc++.h>
using namespace std;

// Approach Name: BFS Two-Coloring
// Time complexity = O(V + E)
// Space complexity = O(V)

class Solution {
  vector<int> colors;
  vector<bool> vis;
  vector<vector<int>> adj;

  bool check(int i) {
    queue<int> q;
    q.push(i);
    vis[i] = true;
    colors[i] = 1;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto nbr : adj[curr]) {
        if (colors[curr] == colors[nbr])
          return false;
        else {
          if (!vis[nbr]) {
            q.push(nbr);
            vis[nbr] = true;

            if (colors[curr] == 1)
              colors[nbr] = 2;
            else
              colors[nbr] = 1;
          }
        }
      }
    }

    return true;
  }

 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size();
    colors.resize(v, 0);
    vis.resize(v, false);
    adj = graph;

    for (int i = 0; i < v; i++) {
      if (!vis[i] && !check(i)) return false;
    }

    return true;
  }
};