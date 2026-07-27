#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Approach 1: Kosaraju's Algorithm (Two-Pass DFS for Strongly Connected Components) 
// Time Complexity: O(V + E) 
// Space Complexity: O(V + E)

class Solution {
  vector<vector<int>> adj;
  stack<int> st;
  vector<bool> vis;

  void dfs1(int node) {
    vis[node] = true;

    for (const auto& nbr : adj[node])
      if (!vis[nbr]) dfs1(nbr);

    st.push(node);
  }

  void dfs2(int node) {
    vis[node] = true;

    for (const auto& nbr : adj[node])
      if (!vis[nbr]) dfs2(nbr);
  }

 public:
  int kosaraju(int V, vector<vector<int>>& edges) {
    // code here
    vis.resize(V, false);
    adj.resize(V);
    for (const auto& edge : edges)
      adj[edge[0]].push_back(edge[1]);

    for (int i = 0; i < V; i++)
      if (!vis[i]) dfs1(i);

    vis.assign(V, false);
    adj.assign(V, {});
    for (const auto& edge : edges)
      adj[edge[1]].push_back(edge[0]);

    int scc = 0;
    while (!st.empty()) {
      int curr = st.top();
      st.pop();

      if (!vis[curr]) {
        scc++;
        dfs2(curr);
      }
    }

    return scc;
  }
};