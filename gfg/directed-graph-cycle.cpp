#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Approach 1: Recursive DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
  vector<vector<int>> adj;
  vector<bool> vis;
  vector<int> currPath;

  bool cycle(int curr) {
    if (currPath[curr]) return true;

    if (vis[curr]) return false;

    currPath[curr] = true;
    vis[curr] = true;

    for (auto nbr : adj[curr]) {
      if (cycle(nbr)) return true;
    }

    currPath[curr] = false;
    return false;
  }

 public:
  bool isCyclic(int V, vector<vector<int>>& edges) {
    // code here
    adj.resize(V);
    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    vis.resize(V, false);
    currPath.resize(V, false);

    for (int i = 0; i < V; i++) {
      if (!vis[i] && cycle(i)) return true;
    }

    return false;
  }
};