#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/articulation-point2616/1

// Approach Name: Tarjan's Algorithm for Articulation Points (DFS + Discovery  Time & Low Time)
// Time Complexity: O(V + E) 
// Space Complexity: O(V + E)

class Solution {
  vector<vector<int>> adj;
  vector<bool> vis;
  vector<int> discTime;
  vector<int> lowTime;
  vector<bool> marker;
  int timer = 1;

  void dfs(int node, int parent) {
    vis[node] = true;
    discTime[node] = lowTime[node] = timer++;

    int children = 0;

    for (const auto& nbr : adj[node]) {
      if (nbr == parent) continue;

      if (!vis[nbr]) {
        dfs(nbr, node);

        lowTime[node] = min(lowTime[node], lowTime[nbr]);

        if (lowTime[nbr] >= discTime[node] && parent != -1) 
          marker[node] = true;

        children++;
      } else {
        lowTime[node] = min(lowTime[node], discTime[nbr]);
      }
    }

    if (children > 1 && parent == -1) 
      marker[node] = true;
  }

 public:
  vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
    // Code here
    vis.resize(V, false);
    discTime.resize(V, -1);
    lowTime.resize(V, -1);
    marker.resize(V, false);
    adj.resize(V);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < V; i++)
      if (!vis[i]) dfs(i, -1);

    vector<int> ans;
    for (int i = 0; i < V; i++)
      if (marker[i]) ans.push_back(i);

    if (ans.empty()) return {-1};
    return ans;
  }
};