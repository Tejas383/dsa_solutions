#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Approach 1: Recursive DFS
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

// Approach 2: BFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
  bool bfs(queue<pair<int, int>>& q, vector<vector<int>>& adj,
           vector<bool>& vis) {
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();

      int node = curr.first;
      int parent = curr.second;

      for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
          vis[nbr] = true;
          q.push({nbr, node});
        } else if (nbr != parent)
          return true;
      }
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
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = true;

        if (bfs(q, adj, vis)) return true;
      }
    }

    return false;
  }
};