#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Approach Name: Recursive DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
  bool dfs(int curr, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[curr] = true;

    for (auto nbr : adj[curr]) {
      if (!vis[nbr]) {
        if (dfs(nbr, curr, adj, vis)) return true;
      } else if (nbr != parent)
        return true;
    }

    return false;
  }

 public:
  bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adj(V);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (dfs(i, -1, adj, vis)) return true;
      }
    }

    return false;
  }
};