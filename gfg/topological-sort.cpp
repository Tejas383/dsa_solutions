#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/topological-sort/1

// Approach 1: Kahn's Algorithm (BFS Topological Sort)
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
 public:
  vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);
    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      ans.push_back(curr);

      for (auto nbr : adj[curr]) {
        indegree[nbr]--;
        if (indegree[nbr] == 0) q.push(nbr);
      }
    }

    return ans;
  }
};

// Approach 2: DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
  vector<vector<int>> adj;
  vector<bool> vis;
  stack<int> st;

  void dfs(int node) {
    vis[node] = true;

    // dfs on adjacent vertices of the current vertex
    for (const auto& nbr : adj[node]) {
      if (!vis[nbr]) dfs(nbr);
    }

    // after dfs, insert into the stack
    st.push(node);
  }

 public:
  vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vis.resize(V);
    adj.resize(V);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    // dfs on non visited vertices
    for (int i = 0; i < V; i++) {
      if (!vis[i]) dfs(i);
    }

    vector<int> ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};