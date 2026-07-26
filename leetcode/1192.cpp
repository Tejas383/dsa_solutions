#include <bits/stdc++.h>
using namespace std;

// Approach name: Tarjan's Algorithm for Bridges (DFS + Discovery Time + Low-Link Values) 
// Time Complexity: O(V + E) 
// Space Complexity: O(V + E)

class Solution {
  int timer = 1;
  vector<bool> vis;
  vector<int> dist;
  vector<int> time;
  vector<vector<int>> adj;
  vector<vector<int>> ans;

  void dfs(int node, int parent) {
    vis[node] = true;

    dist[node] = time[node] = timer++;

    for (const auto& nbr : adj[node]) {
      if (nbr == parent) continue;

      if (!vis[nbr]) {
        dfs(nbr, node);
        time[node] = min(time[nbr], time[node]);

        if (time[nbr] > dist[node]) 
          ans.push_back({nbr, node});
      } else
        time[node] = min(time[nbr], time[node]);
    }
  }

 public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    adj.resize(n);
    for (const auto& edge : connections) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vis.resize(n, false);
    dist.resize(n, -1);
    time.resize(n, -1);

    for (int i = 0; i < n; i++) {
      if (!vis[i]) 
        dfs(i, -1);
    }

    return ans;
  }
};